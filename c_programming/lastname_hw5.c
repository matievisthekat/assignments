#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define ARRAY_SIZE 10000
#define MAX_VALUE 50000

int array[ARRAY_SIZE];

typedef struct {
    int min;
    int max;
} min_max_t;

min_max_t global_min_max;
pthread_mutex_t min_max_lock;

void *find_min_max(void *arg) {
    int thread_id = *((int*) arg);
    int start = thread_id * (ARRAY_SIZE / 2);
    int end = (thread_id + 1) * (ARRAY_SIZE / 2);
    int local_min = MAX_VALUE;
    int local_max = 0;
    for (int i = start; i < end; i++) {
        if (array[i] < local_min) {
            local_min = array[i];
        }
        if (array[i] > local_max) {
            local_max = array[i];
        }
    }
    pthread_mutex_lock(&min_max_lock);
    if (local_min < global_min_max.min) {
        global_min_max.min = local_min;
    }
    if (local_max > global_min_max.max) {
        global_min_max.max = local_max;
    }
    pthread_mutex_unlock(&min_max_lock);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    printf("Initializing array...\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % MAX_VALUE;
        for (int j = 0; j < i; j++) {
            if (array[j] == array[i]) {
                i--;
                break;
            }
        }
    }
    printf("First 10 values of array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\nLast 10 values of array:\n");
    for (int i = ARRAY_SIZE - 10; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    int num_threads[] = {2, 10, 100};
    for (int i = 0; i < 3; i++) {
        int n = num_threads[i];
        pthread_t threads[n];
        global_min_max.min = MAX_VALUE;
        global_min_max.max = 0;
        pthread_mutex_init(&min_max_lock, NULL);
        printf("Running with %d threads...\n", n);
        clock_t start_time = clock();
        for (int j = 0; j < n; j++) {
            int *thread_id = malloc(sizeof(int));
            *thread_id = j;
            pthread_create(&threads[j], NULL, find_min_max, (void*) thread_id);
        }
        for (int j = 0; j < n; j++) {
            pthread_join(threads[j], NULL);
        }
        clock_t end_time = clock();
        pthread_mutex_destroy(&min_max_lock);
        printf("Min value: %d\n", global_min_max.min);
        printf("Max value: %d\n", global_min_max.max);
        printf("Execution time: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    }
    return 0;
}
