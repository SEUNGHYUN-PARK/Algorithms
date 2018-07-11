#include <iostream>
#include <cstdio>
using namespace std;
int pos_num[10000001];
int neg_num[10000001];

int pos_search(int _target, int start, int end)
{
    int mid = (start+end)/2;
    if(mid==_target)
        return pos_num[mid];
    else if(mid<_target)
        return pos_search(_target, mid+1, end);
    else
        return pos_search(_target, start, mid-1);
}
int neg_search(int _target, int start, int end)
{
    int mid = (start+end)/2;
    if(mid==_target)
        return neg_num[mid];
    else if(mid<_target)
        return neg_search(_target, mid+1, end);
    else
        return neg_search(_target, start, mid-1);
}
int main(void)
{
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int temp;
        scanf("%d",&temp);
        if(temp>=0)
            pos_num[temp]++;
        else if(temp<=0)
            neg_num[temp*-1]++;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int temp;
        scanf("%d",&temp);
        if(temp>=0)
            printf("%d ",pos_search(temp,0,10000001));
        else if(temp<=0)
            printf("%d ",neg_search(temp*-1,0,10000001));
    }
    printf("\n");
}
