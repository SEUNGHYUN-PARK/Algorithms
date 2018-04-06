import java.util.Scanner;

public class Main {
	static int r_max = -1000000000;
	static int r_min =  1000000000;
	static int[] arr = new int[12];
	static int n,p,s,m,d;
	static void go(int p_cnt, int s_cnt, int m_cnt, int d_cnt, int current, int idx)
	{
		if(idx==n) // There are no operator
		{
			r_max = Math.max(r_max, current);
			r_min = Math.min(r_min, current);
			return;
		}
		if(p_cnt<p)
			go(p_cnt+1,s_cnt,m_cnt,d_cnt,current+arr[idx],idx+1);
		if(s_cnt<s)
			go(p_cnt,s_cnt+1,m_cnt,d_cnt,current-arr[idx],idx+1);
		if(m_cnt<m)
			go(p_cnt,s_cnt,m_cnt+1,d_cnt,current*arr[idx],idx+1);
		if(d_cnt<d)
			go(p_cnt,s_cnt,m_cnt,d_cnt+1,current/arr[idx],idx+1);
		
	}
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		for(int i=0;i<n;i++)
		{
			arr[i]=in.nextInt();
		}
		p=in.nextInt();
		s=in.nextInt();
		m=in.nextInt();
		d=in.nextInt();
		go(0,0,0,0,arr[0],1);
		System.out.println(r_max);
		System.out.println(r_min);
		in.close();
	}
}
