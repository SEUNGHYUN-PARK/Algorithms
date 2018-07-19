#define N 4

typedef struct {
    int strike;
    int ball;
} Result;

extern Result query(int guess[]);


void numinit(int(*arr)[5])
{
    int i = 0;
    for (int number = 123; number <= 9876; number++)
    {
        int temp = number;
        int temparr[4] = { 0,0,0,0 };
        int index = 3;
        while (temp>0)
        {
            temparr[index--] = temp % 10;
            temp /= 10;
        }
        if (temparr[0] == temparr[1] || temparr[0] == temparr[2] || temparr[0] == temparr[3] ||
            temparr[1] == temparr[0] || temparr[1] == temparr[2] || temparr[1] == temparr[3] ||
            temparr[2] == temparr[0] || temparr[2] == temparr[1] || temparr[2] == temparr[3] ||
            temparr[3] == temparr[0] || temparr[3] == temparr[1] || temparr[3] == temparr[2])
            continue;

        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = temparr[j];
        }
        arr[i][4] = 0;
        i++;
    }
}

void doUserImplementation(int guess[]) {

    int num[5040][5];
    numinit(num);
    int qcnt = 0;
    int k = 0;
    while (true)
    {
        if (qcnt == 0)
        {
            guess[0] = 0;
            guess[1] = 1;
            guess[2] = 2;
            guess[3] = 3;
        }
        else if (qcnt == 1)
        {
            guess[0] = 4;
            guess[1] = 5;
            guess[2] = 6;
            guess[3] = 7;
        }
        else if (qcnt == 2)
        {
            guess[0] = 8;
            guess[1] = 9;
            guess[2] = 1;
            guess[3] = 5;
        }
        else
        {
            //int l = k;
            int max = -1;
            for (int i = 0; i < 5040; i++)
            {
                if (num[i][4] > max)
                {
                    k = i;
                    max = num[i][4];
                }
            }
            guess[0] = num[k][0];
            guess[1] = num[k][1];
            guess[2] = num[k][2];
            guess[3] = num[k][3];
        }

        Result r = query(guess);
        if (r.strike == 4)
            break;
        else if (r.ball == 4)
        {

            for (int i = 0; i < 5040; i++)
            {

                int temp = 0;
                if (i == k)
                    continue;
                if (num[i][4] == -1)
                    continue;
                if (num[k][4] != num[i][4])
                {
                    num[i][4] = -1;
                    continue;
                }
                for (int j = 0; j < 4; j++)
                {
                    if (num[k][j] == num[i][j])
                    {
                        num[i][4] = -1;
                        break;
                    }
                }
            }
            num[k][4] = -1;

        }
        else if (r.strike == 0 && r.ball == 0)
        {
            //
            for (int i = 0; i < 5040; i++)
            {
                if (num[i][4]==-1)
                    continue;
                for (int j = 0;j < 4; j++)
                {
                    if (num[i][j] == guess[0] || num[i][j] == guess[1] || num[i][j] == guess[2] || num[i][j] == guess[3])
                    {
                        num[i][4] = -1;
                        break;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < 5040; i++)
            {
                if (num[i][4] == -1)
                    continue;
                if (num[i][0] == guess[0] && num[i][1] == guess[1] && num[i][2] == guess[2] && num[i][3] == guess[3])
                {
                    num[i][4] = -1;
                    continue;
                }
                int temp=0;
                for (int j = 0; j < 4; j++)
                {
                    if (num[i][j] == guess[0] || num[i][j] == guess[1] || num[i][j] == guess[2] || num[i][j] == guess[3])
                    {
                        temp++;
                    }
                }

                if (r.strike+r.ball!=4&&temp == 4)
                    num[i][4] = -1;
                else
                {
                    if (temp >= r.ball + r.strike)
                        num[i][4] += (r.ball + r.strike);
                    else
                        num[i][4] += temp;
                }
            }
        }
        //guess 재설정하기
        qcnt++;
    }
}
