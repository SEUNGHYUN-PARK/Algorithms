#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string s;
int main(void)
{
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		printf("%d ", s[i] - 'A' + 1);
	}
	puts("");
}