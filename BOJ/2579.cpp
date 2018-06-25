#include <cstdio>

int max(int a, int b)
{
    return a > b ? a : b;
}
int n;
int s[305];
int d[305];
int main(void){
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &s[i]);

    for (int i = 1; i <= 3 && i <= n; i++)
        if (i!=3)
            d[i] = d[i - 1] + s[i];
        else
            d[i] = max(s[i] + d[i - 2], s[i] + s[i - 1]);

    for (int i = 4; i <= n; i++)
        d[i]=max(s[i] + d[i - 2], s[i] + s[i - 1] + d[i - 3]);

    printf("%d\n", d[n]);

}
