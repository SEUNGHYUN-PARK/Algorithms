#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int t;
int tc = 1;
int main(void)
{
	cin >> t;
	while (t--)
	{
		vector<char> v;
		int alphabet_num;
		cin>>alphabet_num;
		for(int i=0;i<alphabet_num;i++)
		{
			char tmp;
			int temp;
			cin >> tmp >> temp;
			for (int j = 0; j < temp; j++)
			{
				v.push_back(tmp);
			}
			
		}
		printf("#%d\n", tc++);
		for (int k = 0; k < v.size(); k++)
		{
			if (k >= 10 && k % 10 == 0)
			{
				printf("\n");
			}
			printf("%c", v[k]);
		}
		printf("\n");
	}
}