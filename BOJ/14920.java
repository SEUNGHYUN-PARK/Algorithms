import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int current = sc.nextInt();
        int next;
        int n=1;
        while(current != 1)
        {
            if(current%2==0)
            {
                next = current/2;
            }
            else
            {
                next = 3*current+1;
            }
            n++;
            current=next;
        }

        System.out.println(n);
    }
}
