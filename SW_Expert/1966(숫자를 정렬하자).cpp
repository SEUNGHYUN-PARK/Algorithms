#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int t;
int tc=1;

int main(void)
{
	scanf("%d",&t);
    while(t--)
    {
        vector<int> v;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int temp;
            scanf("%d",&temp);
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        printf("#%d ",tc++);
        for(int i=0;i<v.size();i++)
        {
            printf("%d ",v[i]);
        }
        printf("\n");
    }
}