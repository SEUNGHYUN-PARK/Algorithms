#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int map[20][20];
int n;
int result;
void map_init()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            map[i][j]=0;
        }
    }
}
int main(void)
{
    int T;
    scanf("%d",&T);
    for(int test_case =1;test_case<=T;test_case++)
    {
        map_init();
        result = 2100000000;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }
        vector<int> all(n);
        for (int i = 0; i < n / 2; i++) //절반은 1팀이고 나머지 절반은 2팀이야
            all[i] = 1;
        sort(all.begin(), all.end());
        do
        {
            vector<int> red;
            vector<int> blue;
            for (int i = 0; i < n; i++)
            {
                if (all[i] == 1)
                    red.push_back(i);
                else
                    blue.push_back(i);
            }
            int red_total = 0, blue_total = 0;
            for(int i=0;i<n/2;i++)
                for (int j = 0; j < n / 2; j++)
                {
                    if (i == j)continue;
                    red_total += map[red[i]][red[j]];
                    blue_total += map[blue[i]][blue[j]];
                }
            int tmp = abs(red_total - blue_total);
            result = min(result, tmp);
        } while (next_permutation(all.begin(), all.end()));

        printf("#%d %d\n",test_case, result);
    }

}
