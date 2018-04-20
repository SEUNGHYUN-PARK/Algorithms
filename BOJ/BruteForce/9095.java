import java.util.Scanner;

public class Main {
	
	static int t,n;
	static int cnt;
	static void go(int num)
	{
		if(num<=0)
		{
			cnt++;
			return;
		}
		if(num>=1)
			go(num-1);
		if(num>=2)
			go(num-2);
		if(num>=3)
			go(num-3);
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		t=sc.nextInt();
		while(t>0)
		{
			cnt=0;
			n=sc.nextInt();
			go(n);
			t--;
			System.out.println(cnt);
		}
			
	}

}
