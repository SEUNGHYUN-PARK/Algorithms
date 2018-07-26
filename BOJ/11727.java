import java.util.Scanner;

public class Main {
    public static int d[] = new int[1001];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        d[0]=1;
        d[1]=1;
        for (int i = 2; i <= num; i++) {
            d[i] = d[i-1]+2*d[i-2];
            d[i]%=10007;
        }
        System.out.println(d[num]);
    }
}
