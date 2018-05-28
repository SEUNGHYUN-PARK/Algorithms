#include <cstdio>
int r = 1, x, y, n;
int main() 
{
    scanf("%d ", &n);
    while(n--) {
        scanf("%d %d", &x, &y);
        if (x == r) r = y;
        else if (y == r) r = x;
    }
    printf("%d", r);
    return 0;
}