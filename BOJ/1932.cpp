#include <iostream>
#include <cstdio>
using namespace std;
int n;
int dp[505][505];
int a[505][505];

int go(int x, int y)
{
    if(x==n)
      return 0;
    int& ret=dp[x][y];
    if(ret)
      return ret;
    return ret=a[x][y]+max(rec(x+1,y),rec(x+1,y+1));
    // 현재 X,Y를 기준으로 한줄 아래에 있는 수
    // 두개 중 더 큰 수를 골라 더해나간다
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j){
            scanf("%d",&a[i][j]);
        }
    }
    int go = rec(0,0);
    printf("%d\n",go);
}
