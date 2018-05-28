/*
고기의 일부분을 뒤집으려하지말고
고기판 자체를 뒤집으면 된다.
나무가 아닌 숲을 보는 것도 중요하다.
*/
#include <iostream>
#include <cstdio>
using namespace std;
char grill[12][12];
int h, w;
int main(void)
{
    int tc;
    scanf("%d ",&tc);
    while (tc--) {
        scanf("%d %d ",&h,&w);
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++)
                scanf("%c ",&grill[i][j]);
        }
        for (int i = 1; i <= h; i++) {
            for (int j = w; j >= 1; j--)
                printf("%c",grill[i][j]);
            puts("");
        }
    }
}