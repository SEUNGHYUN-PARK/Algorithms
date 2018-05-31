class Solution {
public:
	bool isPalindrome(int x) {
		bool judge = true;
		if (x<0)
			return false;
		stack<int> s;
		queue<int> q;
		while (x>0)
		{
			int temp = x % 10;
			s.push(temp);
			q.push(temp);
			x /= 10;
		}
		while (!q.empty())
		{
			if (q.front() != s.top()) { judge = false; break; }
			q.pop();
			s.pop();
		}
		return judge;
	}
};
