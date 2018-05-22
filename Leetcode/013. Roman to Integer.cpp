class Solution {
public:
	int romanToInt(string s) {
		int sum = 0;
		for (int i = 0; i<s.size(); i++)
		{
			//I V X L C D M 1 5 10 50 100 500 1000
			//IV IX XL XC CD CM 4 9 40 90 400 900  
			int parsingscore = 0;
			if (s[i] == 'I')
			{
				if (s[i + 1] == 'V')
				{
					parsingscore = 4;
					i++;
				}
				else if (s[i + 1] == 'X')
				{
					parsingscore = 9;
					i++;
				}
				else
				{
					parsingscore = 1;
				}
			}
			else if (s[i] == 'V')
			{
				parsingscore = 5;
			}
			else if (s[i] == 'X')
			{
				if (s[i + 1] == 'L')
				{
					parsingscore = 40;
					i++;
				}
				else if (s[i + 1] == 'C')
				{
					parsingscore = 90;
					i++;
				}
				else
				{
					parsingscore = 10;
				}
			}
			else if (s[i] == 'L')
			{
				parsingscore = 50;
			}
			else if (s[i] == 'C')
			{
				if (s[i + 1] == 'D')
				{
					parsingscore = 400;
					i++;
				}
				else if (s[i + 1] == 'M')
				{
					parsingscore = 900;
					i++;
				}
				else
				{
					parsingscore = 100;
				}
			}
			else if (s[i] == 'D')
			{
				parsingscore = 500;
			}
			else
			{
				parsingscore = 1000;
			}
			sum += parsingscore;
		}
		return sum;
	}
};
