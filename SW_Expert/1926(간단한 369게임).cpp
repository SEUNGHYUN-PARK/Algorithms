#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int n;
int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int three_cnt = 0;
        string temp = to_string(i);
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] == '3' || temp[j] == '6' || temp[j] == '9')
            {
                three_cnt++;
            }
        }
        if (three_cnt > 0)
        {
            for (int k = 0; k < three_cnt; k++)
            {
                printf("-");
            }
            printf(" ");
        }
        else
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}