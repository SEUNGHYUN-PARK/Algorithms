#include <iostream>
#include <cstdio>
using namespace std;
int t;
int tc=1;
int main(void)
{
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int a=0,b=0,c=0,d=0,e=0;
        scanf("%d",&n);
        while (n>1) {
            if(!(n%11))
            {
                n/=11;
                e++;
                continue;
            }
            else if(!(n%7))
            {
                n/=7;
                d++;
                continue;
            }
            else if(!(n%5))
            {
                n/=5;
                c++;
                continue;
            }
            else if(!(n%3))
            {
                n/=3;
                b++;
                continue;
            }
            else if(!(n%2))
            {
                n/=2;
                a++;
                continue;
            }
            else {}
        }
        printf("#%d %d %d %d %d %d\n",tc++,a,b,c,d,e);
    }
}
