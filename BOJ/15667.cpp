#include <iostream>
#include <cstdio>
using namespace std;

int k;

int main(void)
{
    scanf("%d",&k);
    int i;
    for(i=1;i<=100;i++)
    {
        if(1+i+i*i==k) break;
    }
    printf("%d\n",i);
}
