#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	string s;
	string res;
	const char *c;
	int num = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i; j < s.size(); j++)
		{
			if (s[j] == 'x')
			{
				res = s.substr(i, j - i);
				if (res == ""||res=="+") res = "1";
				if (res == "-")res = "-1";
				i = j;
				c = res.c_str();
				int tmp = atoi(c);
				num += tmp;
				break;
			}
				
		}
	}
	if (num == 1)
	{
		cout << "1\n";
	}
	else if (num == -1)
	{
		cout << "-1\n";
	}
	else
		cout << num << "\n";

}