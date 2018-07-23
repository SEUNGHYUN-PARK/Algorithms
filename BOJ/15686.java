import java.util.ArrayList;
import java.util.Scanner;

class Pair
{
    int x;
    int y;
    Pair(int _x,int _y)
    {
        this.x=_x;
        this.y=_y;
    }
}

public class Main {
    public static int[][] map;
    public static boolean check[][];
    public static int N,M;
    public static int res=10000;
    public static ArrayList<Pair> houses = new ArrayList<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N=sc.nextInt();
        M=sc.nextInt();// N : 맵의 크기, M은 남길 치킨집의 갯수

        map = new int[N+1][N+1];
        check = new boolean[N+1][N+1];
        for (int i = 1; i < map.length; i++) {
            for (int j = 1; j < map[i].length; j++) {
                map[i][j]=sc.nextInt();
                check[i][j]=false;
                if(map[i][j]==1)
                    houses.add(new Pair(i,j));
            }
        }
        go(M);
        System.out.println(res);
    }
    public static void go(int _m)
    {
        decision(0,1,_m);
    }
    public static void decision(int current, int xstart, int _m)
    {
        if(current >= _m)
        {
            int temp = calculate_distance();
            res=  Math.min(temp,res);
            return;
        } // _m개 만큼의 지점을 선정했으면 거리 계산으로 넘어감


        for (int i = xstart; i < map.length; i++) {
            for (int j = 1; j < map[i].length; j++) {
                if(map[i][j]==2 && check[i][j]==false) {
                    check[i][j]=true;
                    decision(current+1,i,_m);
                    check[i][j]=false;
                }
            }
        }
    }
    public static int calculate_distance()
    {
        int ret=0;
        ArrayList<Pair> chickens = new ArrayList<>();
        for (int i = 1; i < check.length; i++) {
            for (int j = 1; j < check[i].length; j++) {
                if(check[i][j]==true)
                    chickens.add(new Pair(i,j));
            }
        }
        int k=2;
        for (int i = 0; i < houses.size(); i++) {
            int xpos = houses.get(i).x;
            int ypos = houses.get(i).y;
            int min = 10000;
            for (int j = 0; j < chickens.size(); j++) {
                int cxpos = chickens.get(j).x;
                int cypos = chickens.get(j).y;
                int dis =  Math.abs(cxpos-xpos)+Math.abs(cypos-ypos);
                min = Math.min(min,dis);
            }
            ret+=min;
        }

        return ret;
    }

}
