#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
int t, tcnum = 1;

int main(void)
{
	scanf("%d", &t);
	while (t--)
	{
		string s;
		int year, month, day;
		cin >> s;

		string temp;
		const char *ctemp;
		for (int i = 0; i < 4; i++)
		{
			temp.push_back(s[i]);
		}
		ctemp = temp.c_str();
		year = atoi(ctemp);
		
		string temp2;
		const char *ctemp2;
		for (int i = 4; i < 6; i++)
		{
			temp2.push_back(s[i]);	
		}
		ctemp2 = temp2.c_str();
		month = atoi(ctemp2);

		string temp3;
		const char *ctemp3;
		for (int i = 6; i < 8; i++)
		{
			temp3.push_back(s[i]);
		}
		ctemp3 = temp3.c_str();
		day = atoi(ctemp3);

		if (month == 1 && 1 <= day &&day <= 31)
		{
			cout << "#" << tcnum++ << " " << temp << "/" << temp2 << "/" << temp3 << "\n";
		}
		else if (month == 2 && 1 <= day &&day <= 28)
		{
			cout << "#" << tcnum++ << " " << temp << "/" << temp2 << "/" << temp3 << "\n";
		}
		else if (month == 3 && 1 <= day && day <= 31)
		{
			cout << "#" << tcnum++ << " " << temp << "/" << temp2 << "/" << temp3 << "\n";
		}
		else if (month == 4 && 1 <= day &&day <= 30)
		{
			cout << "#" << tcnum++ << " " << temp << "/" << temp2 << "/" << temp3 << "\n";
		}
		else if (month == 5 && 1 <= day &&day <= 31)
		{
			cout << "#" << tcnum++ << " " << temp << "/" << temp2 << "/" << temp3 << "\n";
		}
		else if (month == 6 && 1 <= day &&day <= 30)
		{
			cout << "#" << tcnum++ << " " << temp << "/" << temp2 << "/" << temp3 << "\n";
		}
		else if (month == 7 && 1 <= day &&day <= 31)
		{
			cout << "#" << tcnum++ << " " << temp << "/" << temp2 << "/" << temp3 << "\n";
		}
		else if (month == 8 && 1 <= day &&day <= 31)
		{
			cout << "#" << tcnum++ << " " << temp << "/" << temp2 << "/" << temp3 << "\n";
		}
		else if (month == 9 && 1 <= day &&day <= 30)
		{
			cout << "#" << tcnum++ << " " << temp << "/" << temp2 << "/" << temp3 << "\n";
		}
		else if (month == 10 && 1 <= day &&day <= 31)
		{
			cout << "#" << tcnum++ << " " << temp << "/" << temp2 << "/" << temp3 << "\n";
		}
		else if (month == 11 && 1 <= day &&day <= 30)
		{
			cout << "#" << tcnum++ << " " << temp << "/" << temp2 << "/" << temp3 << "\n";
		}
		else if (month == 12 && 1 <= day &&day <= 31)
		{
			cout << "#" << tcnum++ << " " << temp << "/" << temp2 << "/" << temp3 << "\n";
		}
		else
		{
			printf("#%d -1\n",tcnum++);
		}


	}
}