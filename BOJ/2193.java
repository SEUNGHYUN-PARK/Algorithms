import java.util.Scanner;

public class Main {

    public static long d[][];
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        d = new long[num+1][2];
        d[0][0]=0;
        d[0][1]=0;
        d[1][0]=0;
        d[1][1]=1;
        for (int i = 2; i <= num; i++) {
            d[i][0] = d[i-1][0]+d[i-1][1];
            d[i][1]=d[i-1][0];
        }
        long ans =0;
        for (int i = 0; i <=1; i++) {
            ans+=d[num][i];
        }
        System.out.println(ans);
    }
}
