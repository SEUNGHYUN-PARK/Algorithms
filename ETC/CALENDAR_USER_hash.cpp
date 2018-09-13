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


int idxarr[991232] = {0,}; // 0�� ��ĭ
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
	//������ ���ǿ� �°� �ʱ�ȭ�� �Ѵ�
	//2099�� 12�� 31�ϱ����� ���������� �۵��Ѵ�
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
	date�Ͽ� ���� id�� ������ �߰����ִ±��
	�ٸ� repeat������ ���� ���� ����� �����ϴ�
	repeat.type���δ�
	NONE (0),
	DAILY (1),
	WEEKLY (2),
	YEARLY (3),
	EVERY3DAYS (4),
	EVERY5DAYS (5),
	EVERY10DAYS (6)

	repeat.cnt�� repeat.type�� �ݺ��ϰ��� �ϴ�Ƚ���� �ǹ�

	ex)repeat.type==DAILY
	repeat.cnt==5
	=> date�� �������� 5�ϵ��� ���� id�� ���� �߰���

	ex)repeat.type==YEARLY
	repeat.cnt==3
	=> date�� �������� 3�⵿�� �������� ���� id�� ���� �߰���

	Parameter
	int id : �߰��ϰ����ϴ� id ��
	DATE date : ������
	REPEAT repeat : �ݺ������
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
	dMode�� �������� ����� �����ϴ�
	dMode�� 0�϶�
	date��, �� �Ϸ翡 �ִ� ��� �������� ���ִ� ����� �����ϸ�
	dMode�� 1�϶�
	date��, �� �Ϸ翡 �Ҵ�� ��� �������� ���ִ� ����� ����
	+ date�� ���Ŀ� �ִ� ���߿���, date�Ͽ� �Ҵ�� ��ȹ���� ã�� ���� �����ִ� ���

	Parameter
	DATE date : �ش���
	int dmode : �������
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
	from ��¥���� to��¥������ ������ ������ ��
	�����Ѵ�.

	Parameter
	DATE from : ������ ���⸦ �����ϴ� ������
	DATE to : ������ ���⸦ ������ ������
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