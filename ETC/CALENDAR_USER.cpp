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

typedef struct
{
	bool idarr[10000];
	DATE date;
	int schedule_cnt;
}CALENDAR;


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
CALENDAR *c[100];
bool isFirstEXE = true;
int total_YearArr[100];
//int x[100][13][32];
//int y[100][13][32];

void init()
{
	//문제의 조건에 맞게 초기화를 한다
	//2099년 12월 31일까지의 범위내에서 작동한다
	if (isFirstEXE)
	{
		for (int i = 0; i < 100; i++)
		{
			int total_Year = 0;
			for (int j = 1; j <= 12; j++)
			{
				total_Year += dayofMonth(i, j);
			}
			total_YearArr[i] = total_Year;
			c[i] = new CALENDAR[total_Year];
		}
		isFirstEXE = false;
	}
	else
	{
		for (int i = 0; i < 100; i++)
		{
			delete c[i];
		}
		for (int i = 0; i < 100; i++)
		{
			c[i] = new CALENDAR[total_YearArr[i]];
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < total_YearArr[i]; j++)
		{
			for (int k = 0; k < 10000; k++)
			{
				c[i][j].idarr[k] = false;
			}
			c[i][j].schedule_cnt = 0;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		int k = 0;
		for (int j = 1; j <= 12; j++)
		{
			int temp = dayofMonth(i + 2000, j);
			for (int tmp = 1; tmp <= temp; tmp++)
			{
				c[i][k].date.year = i + 2000;
				c[i][k].date.month = j;
				c[i][k].date.day = tmp;
				k++;
			}
		}
	}
}

void addPlan(int id, DATE date, REPEAT repeat)
{
	/*
	date일에 값이 id인 일정을 추가해주는기능
	다만 repeat변수의 값에 따라 기능이 상이하다
	repeat.type으로는
	NONE,
	DAILY,
	WEEKLY,
	YEARLY,
	EVERY3DAYS,
	EVERY5DAYS,
	EVERY10DAYS

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
	int days = 0;
	bool flag = true;
	for (int i = 0; i < 100; i++)
	{
		if (flag && i != date.year - 2000)
			continue;
		if (repeat.cnt <= 0)
			break;
		for (int j = 0; j < total_YearArr[i]; j++)
		{
			if (repeat.cnt <= 0)
				break;
			if (flag && c[i][j].date.month == date.month&& c[i][j].date.day == date.day)
			{
				c[i][j].idarr[id] = true;
				c[i][j].schedule_cnt++;
				repeat.cnt--;
				days++;
				flag = false;
				continue;
			}
			if (flag==false&&repeat.cnt > 0)
			{
				if (repeat.type == 1)
				{
					c[i][j].idarr[id] = true;
					c[i][j].schedule_cnt++;
					repeat.cnt--;
				}
				else if (repeat.type == 2)
				{
					if (days % 7 == 0)
					{
						c[i][j].idarr[id] = true;
						c[i][j].schedule_cnt++;
						repeat.cnt--;
					}
				}
				else if (repeat.type == 3)
				{
					if (c[i][j].date.day == date.day)
					{
						c[i][j].idarr[id] = true;
						c[i][j].schedule_cnt++;
						repeat.cnt--;
					}
				}
				else if (repeat.type == 4)
				{
					if (date.year<=c[i][j].date.year && c[i][j].date.month == date.month && c[i][j].date.day == date.day)
					{
						c[i][j].idarr[id] = true;
						c[i][j].schedule_cnt++;
						repeat.cnt--;
					}
				}
				else if (repeat.type == 5)
				{
					if (days % 3 == 0)
					{
						c[i][j].idarr[id] = true;
						c[i][j].schedule_cnt++;
						repeat.cnt--;
					}
				}
				else if (repeat.type == 6)
				{
					if (days % 5 == 0)
					{
						c[i][j].idarr[id] = true;
						c[i][j].schedule_cnt++;
						repeat.cnt--;
					}
				}
				else if (repeat.type == 7)
				{
					if (days % 10 == 0)
					{
						c[i][j].idarr[id] = true;
						c[i][j].schedule_cnt++;
						repeat.cnt--;
					}
				}
				days++;
			}

		}
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
	bool idarr[10000] = { false, };
	bool flag = true;
	for (int i = 0; i < 100; i++)
	{
		if (flag && i != date.year - 2000)
			continue;
		for (int j = 0; j < total_YearArr[i]; j++)
		{
			if (flag && c[i][j].date.month == date.month&& c[i][j].date.day == date.day)
			{
				flag = false;
				for (int k = 0; k < 10000; k++)
				{
					if (c[i][j].idarr[k] == true)
					{
						idarr[k] = c[i][j].idarr[k];
						c[i][j].idarr[k] = false;
						c[i][j].schedule_cnt--;
						
					}
				}
			}
			if (dMode == 0)
				break;
			else
			{
				for (int k = 0; k < 10000; k++)
				{
					if (c[i][j].idarr[k] == true && idarr[k]==true && idarr[k] == c[i][j].idarr[k])
					{
						c[i][j].idarr[k] = false;
						c[i][j].schedule_cnt--;
					}
				}
			}
		}
		if (dMode == 0)
			break;
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
	bool flag = true;
	bool isfinish = false;
	int res = 0;
	for (int i = 0; i < 100; i++)
	{
		if (flag && i != from.year - 2000)
			continue;
		for (int j = 0; j < total_YearArr[i]; j++)
		{
			if (flag && c[i][j].date.month == from.month&& c[i][j].date.day == from.day)
			{
				res += c[i][j].schedule_cnt;
				flag = false;
				continue;
			}
			if (flag == false)
			{
				res += c[i][j].schedule_cnt;
			}
			if (flag == false && c[i][j].date.year==to.year && c[i][j].date.month == to.month&& c[i][j].date.day == to.day)
			{
				isfinish = true;
				break;
			}
		}
		if (isfinish)
			break;
	}

	return res;
}