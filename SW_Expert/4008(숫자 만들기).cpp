#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
int max_num;
int min_num;
int result;
int arr[12]={0,};
int n;
int op[4]={0,}; // + - * /
void go(int idx, int p, int s, int m, int d, int current)
{
    if(idx == n-1)
    {
        max_num = max(current,max_num);
        min_num = min(current,min_num);
        result = max_num - min_num;
        return;
    }
    if(p<op[0])
        go(idx+1,p+1,s,m,d,current+arr[idx+1]);
    if(s<op[1])
        go(idx+1,p,s+1,m,d,current-arr[idx+1]);
    if(m<op[2])
        go(idx+1,p,s,m+1,d,current*arr[idx+1]);
    if(d<op[3])
        go(idx+1,p,s,m,d+1,current/arr[idx+1]);
}
int main(void)
{
    int T;
    scanf("%d",&T);
    for(int test_case = 1; test_case<=T; test_case++)
    {
        memset(arr, 0, 12);
        memset(op, 0, 4);
        max_num = -100000000;
        min_num = 100000000;
        scanf("%d",&n);
        for(int i=0;i<4;i++)
        {
            scanf("%d",&op[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        go(0,0,0,0,0,arr[0]);
        printf("#%d %d\n",test_case,result);
    }
}
