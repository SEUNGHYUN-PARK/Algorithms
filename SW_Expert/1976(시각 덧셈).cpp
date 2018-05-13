#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int t;
int tc=1;
int main(void)
{
    scanf("%d",&t);
    while(t--)
    {
        int t1,m1,t2,m2,rt,rm;
        scanf("%d %d %d %d",&t1,&m1,&t2,&m2);
        rt= t1+t2;
        rm = m1+m2;
        rt+= rm/60;
        if(rt>12&& rt%12!=0)
            rt%=12;
        else if(rt>12&& rt%12==0)
            rt=12;
        rm=rm%60;
        printf("#%d %d %d\n",tc++,rt,rm);
    }
}