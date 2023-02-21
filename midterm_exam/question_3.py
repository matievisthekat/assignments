def compute_mean(numbers):
    if not numbers:
        return None
    total = 0
    count = 0
    for number in numbers:
        total += number
        count += 1
    mean = total / count
    return mean

def main():
    numbers = [1, 2, 3, 4, 5, 11, 55, 23]
    mean = compute_mean(numbers)
    print(f"The mean of {numbers} is {mean}")

if __name__ == "__main__":
    main()