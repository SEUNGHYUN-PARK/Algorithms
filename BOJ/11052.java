import java.util.Scanner;
public class Main {

    public static int p[];
    public static int d[];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cnt = sc.nextInt();
        p=new int[cnt+1];
        p[0]=0;
        d=new int[cnt+1];
        d[0]=0;
        for (int i = 1; i < p.length; i++) {
            p[i]= sc.nextInt();
        }

        for (int i = 1; i <= cnt; i++) {
            for (int j = 1; j <= i; j++) {
                d[i] = Math.max(d[i],d[i-j]+p[j]);
            }
        }
        System.out.println(d[cnt]);
    }
}
