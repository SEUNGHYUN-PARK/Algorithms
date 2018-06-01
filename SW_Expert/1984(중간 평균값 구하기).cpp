#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int T;
    scanf("%d",&T);
    for(int test_case=1;test_case<=T;test_case++)
    {
        vector<int> v;
        double dav;
        int nav;
        int sum=0;
 
        for(int i=0;i<10;i++)
        {
            int temp;
            scanf("%d",&temp);
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        for(int i=1;i<9;i++)
        {
            sum+=v[i];
        }
        nav = sum/8;
        dav = double(sum)/8;
        double sub = dav-double(nav);
        if(0.5<=sub&&sub<1)
        {
            nav++;
        }
        printf("#%d %d\n",test_case,nav);
    }
}
