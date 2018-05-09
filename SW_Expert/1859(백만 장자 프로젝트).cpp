#include <cstdio>
int T, N, max, num[1000000];
long long ans;
int main() {
    scanf("%d", &T);
    for (int t_case = 0; t_case < T; t_case++) {//각 test case 수행
        scanf("%d", &N);//연속된 일수
        ans = 0, max = 0;
        for (int i = 0; i < N; i++)
            scanf("%d", num+i); //일수에 해당하는 매매가 저장
        for (int j = N - 1; j >= 0; j--) {//뒤에서부터 읽기
            max = (max < num[j]) ? num[j] : max;//최댓값과 해당값을 비교하여 최댓값을 저장
            ans += max - num[j];//최댓값과 해당값의 차이를 누적
        }
        printf("#%d %lld\n", t_case + 1, ans);
    }
}