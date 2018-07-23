#include <iostream>
#include <cstdio>
using namespace std;

enum {
	ADD,
	DELETE,
	SEARCH
};

typedef struct
{
	int year;
	int month;
	int day;
}DATE;

typedef struct
{
	int type;
	int cnt;
}REPEAT;

void init();
void addPlan(int id, DATE date, REPEAT repeat);
void deletePlan(DATE date, int dMode);
int searchPlan(DATE from, DATE to);
extern int dayofMonth(int year, int month);

static int run()
{

	int id = 1;
	int answer = 100;
	int N;
	init();
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int cmdtype;
		scanf("%d", &cmdtype);
		DATE date, date1;
		REPEAT repeat;
		int nDate, nDate1, rMode, rCnt, dMode, sCnt;
		switch (cmdtype)
		{
			case ADD:
			{
				scanf("%d %d %d", &nDate, &rMode, &rCnt);
				date.year = (nDate / 10000) + 2000;
				date.month = (nDate / 100) % 100;
				date.day = nDate % 100;
				repeat.type = rMode;
				repeat.cnt = rCnt;
				addPlan(id, date,repeat);
				id++;
				break;
			}
			case DELETE:
			{
				scanf("%d %d", &nDate, &dMode);
				date.year = (nDate / 10000) + 2000;
				date.month = (nDate / 100) % 100;
				date.day = nDate % 100;
				deletePlan(date, dMode);
				break;
			}
			case SEARCH:
			{
				scanf("%d %d %d", &nDate, &nDate1, &sCnt);

				date.year = (nDate / 10000) + 2000;
				date.month = (nDate / 100) % 100;
				date.day = nDate % 100;
				date1.year = (nDate1 / 10000) + 2000;
				date1.month = (nDate1 / 100) % 100;
				date1.day = nDate1 % 100;
				int result = searchPlan(date,date1);
				if (result != sCnt)
					answer = 0;
				return answer;
				
			}

		}
	}

}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		printf("#%d %d\n", test_case, run());
	}
}