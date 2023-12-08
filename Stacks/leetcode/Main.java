import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = 0;
        int sum = 0;

        while (n != -1) {
            n = scanner.nextInt();
            if (n < 100 && n != -1) {
                sum += n;
            } else {
                if (sum != 0) {
                    System.out.println(sum);
                }
                sum = 0;
                if(n != -1) System.out.println(n);
            }
        }
        if (sum != 0) {
            System.out.println(sum);
        }

        scanner.close();
    }
}