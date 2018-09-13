#include <cstdio>


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

enum {
	NONE,
	DAILY,
	WEEKLY,
	YEARLY,
	EVERY3DAYS,
	EVERY5DAYS,
	EVERY10DAYS
};

extern int dayofMonth(int yy, int mm)
{
	if (mm == 2)
	{
		if (((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0))
		{
			return 29;
		}
		else
			return 28;
	}
	else if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
		return 31;
	else
		return 30;

}
typedef struct Calendar
{
	int year, month, day;
	int id_cnt;
	bool id_list[10001];
}Calendar;


int idxarr[991232] = {0,}; // 0은 빈칸
Calendar calendar[36526];

bool abovetwice = false;

int choosePattern(REPEAT _repeat)
{
	/*
	NONE (1),
	DAILY (1), ok
	WEEKLY (3),
	YEARLY (4),
	EVERY3DAYS (5),
	EVERY5DAYS (6),
	EVERY10DAYS (7)
	*/
	int ret;
	if (_repeat.type == 1)
		ret = 0;
	else if (_repeat.type == 2)
		ret = 1;
	else if (_repeat.type == 3)
		ret = 7;
	else if (_repeat.type == 4)
		ret = -1;
	else if (_repeat.type == 5)
		ret = 3;
	else if (_repeat.type == 6)
		ret = 5;
	else if (_repeat.type == 7)
		ret = 10;
	return ret;
}



void init()
{
	//문제의 조건에 맞게 초기화를 한다
	//2099년 12월 31일까지의 범위내에서 작동한다
	if (!abovetwice)
	{
		int arridx = 1;
		for (int i = 0; i <= 99; i++) {
			for (int j = 1; j <= 12; j++)
			{
				int maxday = dayofMonth(i, j);
				for (int k = 1; k <= maxday; k++)
				{
					
					int idx = k + j * 100 + i * 10000;
					idxarr[idx] = arridx;
					calendar[arridx].year = i;
					calendar[arridx].month = j;
					calendar[arridx].day = k;
					arridx++;
				}
			}
		}
		abovetwice = true;
	}
	for (int i = 1; i <= 36525; i++)
	{
		if (calendar[i].id_cnt == 0) continue;
		for (int j = 1; j <= 10000; j++)
		{
			calendar[i].id_list[j] = false;
		}
	}

}

void addPlan(int id, DATE date, REPEAT repeat)
{
	/*
	date일에 값이 id인 일정을 추가해주는기능
	다만 repeat변수의 값에 따라 기능이 상이하다
	repeat.type으로는
	NONE (0),
	DAILY (1),
	WEEKLY (2),
	YEARLY (3),
	EVERY3DAYS (4),
	EVERY5DAYS (5),
	EVERY10DAYS (6)

	repeat.cnt는 repeat.type을 반복하고자 하는횟수를 의미

	ex)repeat.type==DAILY
	repeat.cnt==5
	=> date일 기준으로 5일동안 값이 id인 일을 추가함

	ex)repeat.type==YEARLY
	repeat.cnt==3
	=> date일 기준으로 3년동안 같은날에 값이 id인 일을 추가함

	Parameter
	int id : 추가하고자하는 id 값
	DATE date : 기준일
	REPEAT repeat : 반복제어변수
	*/
	int idx = date.day + date.month * 100 + (date.year - 2000) * 10000;
	int current = idxarr[idx];
	int interval = choosePattern(repeat);
	int remain = repeat.cnt;
	int daycount = 0;

	calendar[current].id_list[id] = true;
	calendar[current].id_cnt++;
	current++;
	remain--;
	daycount++;

	while (remain > 0)
	{
		if (interval == -1)
		{
			if (date.year != calendar[current].year&&date.month == calendar[current].month&&date.day == calendar[current].day)
			{
				calendar[current].id_list[id] = true;
				calendar[current].id_cnt++;
			}
			remain--;
		}
		else if (interval > 0 && daycount%interval == 0)
		{
			calendar[current].id_list[id] = true;
			calendar[current].id_cnt++;
			remain--;
		}
		else if (interval == 0)
			break;
		current++;
		daycount++;
	}



	
}
void deletePlan(DATE date, int dMode)
{
	/*
	dMode의 값에따라 기능이 상이하다
	dMode가 0일땐
	date일, 단 하루에 있는 모든 일정들을 없애는 기능을 수행하며
	dMode가 1일땐
	date일, 단 하루에 할당된 모든 일정들을 없애는 기능을 수행
	+ date일 이후에 있는 일중에서, date일에 할당된 계획들을 찾아 전부 없애주는 모드

	Parameter
	DATE date : 해당일
	int dmode : 삭제모드
	*/
	int deletearr[10000] = { 0, };
	int deletearrsize = 0;
	int k = 0;
	int idx = date.day + date.month * 100 + (date.year - 2000) * 10000;
	int target = idxarr[idx];
	int lastday = idxarr[991231];
	calendar[target].id_cnt = 0;
	for (int i = 1; i <= 10000; i++)
	{
		if (calendar[target].id_list[i] == true)
		{
			calendar[target].id_list[i] = false;
			deletearr[k++] = i;
			deletearrsize++;
		}
	}
	if (dMode == 1)
	{
		target += 1;
		for (int i = target; i <= lastday; i++)
		{
			if (calendar[i].id_cnt > 0)
			{
				int ididx = 0;
				while (calendar[i].id_cnt > 0)
				{
					calendar[i].id_list[deletearr[ididx++]]=false;
					calendar[i].id_cnt--;
				}
			}
			else
				continue;
		}
	}


}
int searchPlan(DATE from, DATE to)
{
	/*
	from 날짜부터 to날짜까지의 일정의 갯수를 세
	리턴한다.

	Parameter
	DATE from : 갯수를 세기를 시작하는 기준일
	DATE to : 갯수를 세기를 끝내는 종료일
	*/
	int fidx = from.day + from.month * 100 + (from.year - 2000) * 10000;
	int tidx = to.day + to.month * 100 + (to.year - 2000) * 10000;
	int FROM = idxarr[fidx];
	int TO = idxarr[tidx];
	int res = 0;
	for (int i = FROM; i <= TO; i++)
	{
		res += calendar[i].id_cnt;
	}
	return res;
}