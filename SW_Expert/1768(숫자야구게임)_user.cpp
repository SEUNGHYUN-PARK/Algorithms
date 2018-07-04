#define N 4
//#include <stdio.h>
typedef struct {
    int strike;
    int ball;
} Result;

// API
extern Result query(int guess[]);

void doUserImplementation(int guess[]) {

    int qcnt=0;
    int num[5040][5];
    int s=0;

    for(int i=123;i<=9876;i++)
    {
        int tmp=i;
        int last=3;
        num[s][0]=0;
        num[s][4]=1; //일단 모든 수가 후보군...
        while(tmp>0)
        {
            num[s][last] = tmp % 10;
            tmp/=10;
            last--;
        }
        s++;
    }
    while(true)
    {
        // 숫자제시
            //첫 시작일때만 임의의 수를 제시
        // 쿼리던짐
        // 리턴된값에 맞춰 값 수정
            //스트라이크일경우 반복문 종료
            //이외의 경우는 다시 수결정
                // 아웃이면 각각의 수를 포함하는 모든 수를 제거->[5040][5]
        if(qcnt<1)
        {
            guess[0]=2;
            guess[1]=5;
            guess[2]=9;
            guess[3]=6;
        }
        qcnt++;
        Result r = query(guess);
        if(r.strike==4&&r.ball==0)
            break;
        else
        {
            if(r.strike==0&&r.ball==0)
            {

            }

        }

    }

}
