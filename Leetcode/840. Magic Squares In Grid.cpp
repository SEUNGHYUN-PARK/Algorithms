class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int xmax=grid.size()-3,ymax=grid[0].size()-3;
        int cnt=0;
        for(int i=0;i<=xmax;i++)
        {
            for(int j=0;j<=ymax;j++)
            {
                if(check(grid,i,j))
                  cnt++;  
            }
        }
        return cnt;
    }
    bool check(vector<vector<int>>& grid, int x, int y)
    {
        int arr[10]={0,};
        int temp=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[x+i][y+j]<=9)
                    arr[grid[x+i][y+j]]++;
            }
        }
        for(int i=1;i<=9;i++)
        {
            temp+=arr[i];
        }
        
        int a = grid[x][y]+grid[x][y+1]+grid[x][y+2];
        int b = grid[x+1][y]+grid[x+1][y+1]+grid[x+1][y+2];
        int c = grid[x+2][y]+grid[x+2][y+1]+grid[x+2][y+2];
        int d = grid[x][y]+grid[x+1][y]+grid[x+2][y];
        int e = grid[x][y+1]+grid[x+1][y+1]+grid[x+2][y+1];
        int f = grid[x][y+2]+grid[x+1][y+2]+grid[x+2][y+2];
        int g = grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2];
        int h = grid[x][y+2]+grid[x+1][y+1]+grid[x+2][y];
        
        if(temp==9 &&(a==b)&&(b==c)&&(c==d)&&(d==e)&&(e==f)&&(f==g)&&(g==h))
            return true;
        else 
            return false;
        
    }
};