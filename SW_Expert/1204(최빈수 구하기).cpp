#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int T,r_idx;
    scanf("%d ",&T);
    for(int test_case=1;test_case<=T;test_case++)
    {
        int c_num;
        scanf("%d ",&c_num);
        int number[101] ={0,};
        for(int i=0;i<1000;i++)
        {
            int temp;
            scanf("%d ",&temp);
            number[temp]++;
        }
        r_idx=0;
        for(int i=0;i<=100;i++)
        {
            if(number[r_idx]<number[i])
                r_idx=i;
        }
        
        printf("#%d %d\n",c_num, r_idx);
    }
}
