class Solution {
public:
    int reverse(int x) {
        int result=0;
        string s = to_string(x);
        if(x>0)
        {
            for(int i=0;i<s.size();i++)
            {
                result += (s[i]-'0') * pow(10,i);
            }
        }
        else
        {
            for(int i=1;i<s.size();i++)
            {
                result -= (s[i]-'0') * pow(10,i-1);
            }
        }
        if(result<=pow(-2,31)||result>=pow(2,31)-1)
             return 0;
        else
            return result;
    }
};