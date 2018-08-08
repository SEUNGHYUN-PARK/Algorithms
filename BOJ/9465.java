import java.util.Scanner;

public class Sticker {


    public static void main(String[] args) {
        long arr[][];
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        long d[][];
        for(int i=0;i<T;i++)
        {
            int n = scanner.nextInt();
            arr = new long[2][n+1]; //0은 위쪽 1은 아래쪽
            d = new long[3][n+1]; // 0은 위쪽 1은 아래쪽 2는 안뜯음
            for(int row=0;row<2;row++)
            {
                for(int col=1;col<=n;col++)
                {
                    arr[row][col]=scanner.nextInt();
                }
            }
            for(int k=1;k<=n;k++)
            {
                d[2][k] = Math.max(Math.max(d[1][k-1],d[0][k-1]),d[2][k-1]);
                d[0][k] = Math.max(d[1][k-1],d[2][k-1])+arr[0][k];
                d[1][k] = Math.max(d[0][k-1],d[2][k-1])+arr[1][k];
            }

            long ans = 0;
            ans = Math.max(d[0][n],Math.max(d[1][n],d[2][n]));
            System.out.println(ans);

        }
    }
}
