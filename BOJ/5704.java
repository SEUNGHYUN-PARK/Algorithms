import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true)
        {
            int alphabet_count[] = new int[26];
            String s =sc.nextLine();
            if(s.equals("*"))
                break;
            char cs[] = s.toCharArray();
            for (int i = 0; i < cs.length; i++) {
                if(cs[i]==' ')
                    continue;
                else
                    alphabet_count[cs[i]-'a']++;
            }
            Boolean ispangram=true;
            for (int i = 0; i < alphabet_count.length; i++) {
                if(alphabet_count[i]<1)
                {
                    ispangram=false;
                    break;
                }
            }
            if(ispangram)
            {
                System.out.println("Y");
            }
            else
            {
                System.out.println("N");
            }

        }
    }
}
