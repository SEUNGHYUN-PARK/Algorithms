#include <iostream>
#include <cstdio>
using namespace std;
int d;
int res;
int main(void)
{
    scanf("%d",&d);
    while(d>0){
        double temp;
        res += d/5;
        if(d<5)
        {
            temp =double(d)/5;
            if(temp>0&&temp<1)
                res++;
            break;
        }
        d%=5;

    }
    printf("%d\n",res);
}