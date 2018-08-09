import java.util.Scanner;

public class Sorting {
    public static int positive[];
    public static int negative[];
    public static void main(String[] args) {
        positive = new int[1001];
        negative = new int[1001];
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        for(int i=0;i<num;i++)
        {
            int temp = sc.nextInt();
            if(temp>0)
                positive[temp]++;
            else
                negative[temp*-1]++;
        }
        for (int i = 1000; i >=0 ; i--) {
            if(negative[i]>0)
                System.out.print(i*-1+" ");
        }
        for (int i = 1; i < positive.length; i++) {
            if(positive[i]>0)
                System.out.print(i+" ");
        }
    }
}
