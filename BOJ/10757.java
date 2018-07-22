import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String A,B;
        Scanner sc = new Scanner(System.in);
        A=sc.next(); B = sc.next();
        BigInteger a = new BigInteger(A);
        BigInteger b = new BigInteger(B);
        BigInteger res = a.add(b);
        System.out.println(res);
    }
}
