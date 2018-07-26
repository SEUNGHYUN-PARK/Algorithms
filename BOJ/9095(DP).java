import java.util.Scanner;

public class Main {
    public static int arr[] = new int[12];
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T= scanner.nextInt();
        arr[0]=1;
        arr[1]=1;
        arr[2]=2;
        for (int i = 3; i <=11 ; i++) {
            arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
        }
        for (int i = 0; i < T; i++) {
            int s = scanner.nextInt();
            System.out.println(arr[s]);
        }

    }
}
