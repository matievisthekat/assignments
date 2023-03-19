import java.util.Scanner;

public class Teams {
    public static void showTeams(int[] group, int[] team, int start, int index) {
        if (index == team.length) {
            for (int i = 0; i < team.length; i++) {
                System.out.print(group[team[i]] + " ");
            }
            System.out.println();
            return;
        }
        
        for (int i = start; i < group.length; i++) {
            team[index] = i;
            showTeams(group, team, i + 1, index + 1);
        }
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter group size: ");
        int n = input.nextInt();
        int[] group = new int[n];
        for (int i = 0; i < n; i++) {
            group[i] = i + 1;
        }
        
        System.out.print("Enter team size: ");
        int k = input.nextInt();
        int[] team = new int[k];
        
        System.out.println("All possible teams:");
        showTeams(group, team, 0, 0);
        input.close();
    }
}
