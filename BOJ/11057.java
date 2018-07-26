import java.util.Scanner;

public class AscendingNumber {
    public static long d[][];
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int digit = scanner.nextInt();
        d = new long[digit+1][10];
        for (int i = 0; i <= 9; i++) {
            d[1][i] = 1;
        }
        for (int i = 0; i <=digit ; i++) {
            d[i][0]=1;
        }

        for (int i = 1; i <=digit ; i++) {
            for (int j = 1; j <=9 ; j++) {
                d[i][j]=d[i][j-1]+d[i-1][j];
                d[i][j]%=10007;
            }
        }
        long ans = 0;
        for (int i = 0; i <=9 ; i++) {
            ans+=d[digit][i];
        }
        ans%=10007;
        System.out.println(ans);
    }
}
