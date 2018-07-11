#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;
int map[500][500];
int N;
int x,y,d,g;
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
vector<int> v;
void go(int x,int y,int g,int start)
{
    int ox=x;
    int oy=y;
    if(start > g) // 종료
    {
        return;
    }
    map[x][y]=1;
    queue<int> q;
    stack<int> st;
    for(int i=0;i<v.size();i++)
    {
        q.push(v[i]);
    }
    int nx=0,ny=0;
    while(!q.empty())
    {
        int _d = q.front ();
        q.pop();
        nx = x+dx[_d];
        ny = y+dy[_d];
        map[nx][ny]=1;
        if(_d==0)
            st.push(1);
        if(_d==1)
            st.push(2);
        if(_d==2)
            st.push(3);
        if(_d==3)
            st.push(0);
        x=nx;
        y=ny;
    }
    while(!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    go(ox,oy,g,start+1);
}

int main(void)
{
    int count=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d %d %d",&x,&y,&d,&g);
        v.push_back(d);
        go(y,x,g,0);
        v.clear();
    }
    for(int i=0;i<200;i++)
        for(int j=0;j<200;j++)
        {
            if(map[i][j]==1&&map[i+1][j]==1&&map[i][j+1]==1&&map[i+1][j+1]==1)
                count++;
        }
    printf("%d\n",count);

}
