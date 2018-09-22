#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int max_damage = -2100000000;
vector<int> answer;

void go(vector<int> healths, vector<vector<int>> items, vector<bool> checked, vector<bool> personpick, int personnumber)
{
	if (personnumber >= healths.size())
	{
		int temp = 0;
		vector<int> res;
		for (int i = 0; i<checked.size(); i++)
		{
			if (checked[i] == true)
			{
				temp += items[i][0];
			}
		}
		if (temp >= max_damage)
		{
			for (int i = 0; i<checked.size(); i++)
			{
				if (checked[i] == true)
				{
					res.push_back(i+1);
				}
			}
			answer = res;
			max_damage = temp;
		}
		return;
	}

	for (int i = 0; i<items.size(); i++)
	{
		if (checked[i] == false && (healths[personnumber] - items[i][1]) >= 100)
		{
			int current = personnumber;
			checked[i] = true;
			personpick[current] = true;
			go(healths, items, checked, personpick, personnumber + 1);
			checked[i] = false;
			personpick[current] = false;
		}

	}
	if (personpick[personnumber] == false)
	{
		go(healths, items, checked, personpick, personnumber + 1);
	}


}
vector<int> solution(vector<int> healths, vector<vector<int>> items) {
	vector<bool> checked(items.size());
	vector<bool> personpick(healths.size());
	go(healths, items, checked, personpick,0);
	return answer;
}
