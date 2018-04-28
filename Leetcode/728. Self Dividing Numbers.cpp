class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for(int i=left;i<=right;i++)
        {
            bool judge = true;
            int tmp = i;
            while(tmp>0)
            {
                int digit = tmp%10;
                if(digit==0) // If one of digit numbers is 0, it can't divide by 0.
                {
                    judge=false;
                    break;
                }
                int remain = i%digit;
                if(remain!=0)
                {
                    judge=false;
                    break;
                }
                tmp/=10;
            }
            if(judge==true)
                ret.push_back(i);
        }
        return ret;
    }
};