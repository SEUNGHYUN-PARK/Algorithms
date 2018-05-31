#include <iostream>
#include <string>
using namespace std;
string s;
int main(void)
{
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if ('a' <= s[i] && s[i] <= 'z')
			s[i] -= 32;
	}
	cout << s<<"\n";
}