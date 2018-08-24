#define N 4
typedef struct {

	int strike;

	int ball;

} Result;

// API

extern Result query(int guess[]);
int allNum[5040][5];

void init()
{
	int row = 0;
	int tmp;
	for (int i = 123; i <= 9876; i++)
	{
		bool flag = false;
		int numbercnt[10] = { 0, };
		tmp = i;
		while (tmp > 0)
		{
			numbercnt[tmp%10]++;
			tmp /= 10;
		}
		if (i < 1000)
		{
			numbercnt[0]++;
		}
		for (int i = 0; i < 10; i++)
		{
			if (numbercnt[i] > 1)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		else
		{
			int col = 3;
			tmp = i;
			while (tmp > 0)
			{
				allNum[row][col--] = tmp % 10;
				tmp /= 10;
			}
			allNum[row][4] = 0;
			row++;
		}

	}
}

void removeCandidate(Result _r, int guess[])
{
	for (int i = 0; i < 5040; i++)
	{
		Result cr;
		cr.strike = 0, cr.ball = 0;
		if (allNum[i][4] == -1)
			continue;
		else
		{
			int digit_cnt[10] = { 0, };
			for (int j = 0; j < 4; j++)
			{
				digit_cnt[allNum[i][j]]++;
			}

			for (int k = 0; k < 4; k++)
			{
				if (guess[k] == allNum[i][k])
				{
					cr.strike++;
				}
				else if (digit_cnt[guess[k]]>0)
				{
					cr.ball++;
				}
			}
		}
		if (_r.strike == cr.strike && _r.ball == cr.ball)
			allNum[i][4] = 0;
		else
			allNum[i][4] = -1;
	}

}

void doUserImplementation(int guess[]) {

	init();
	while (true)
	{
		for (int i = 0; i < 5040; i++)
		{
			if (allNum[i][4] == -1)
				continue;
			if (allNum[i][4] == 0)
			{
				guess[0] = allNum[i][0], guess[1] = allNum[i][1], guess[2] = allNum[i][2], guess[3] = allNum[i][3];
				break;
			}
		}

		Result r = query(guess);
		if (r.strike == 4)
			break;
		else
			removeCandidate(r, guess);
	}
}
