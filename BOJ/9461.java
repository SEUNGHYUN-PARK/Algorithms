import java.util.ArrayList;
import java.util.Scanner;

public class Padovansequence {
    public static long[] init={0,1,1,1,2,2,3,4,5,7,9};
    public static ArrayList<Long> p;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        p= new ArrayList<>();
        for (int i = 0; i < init.length; i++) {
           p.add(init[i]);
        }

        for (int i = 11; i <=100; i++) {
            p.add(p.get(i-1)+p.get(i-5));
        }
        int T=sc.nextInt();
        for (int i = 0; i < T; i++) {
            int num = sc.nextInt();
            System.out.println(p.get(num));
        }
    }
}
