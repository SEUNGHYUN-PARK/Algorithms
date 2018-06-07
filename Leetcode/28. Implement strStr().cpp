class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;
        if(haystack.size()==0)
            return -1;
        if(haystack.size()<needle.size())
            return -1;
        int i,j;
        for(i=0;i<=haystack.size()-needle.size();i++)
        {
            bool flag = true;
            int ret=i;
            int k=0;
            for(j=i;j<i+needle.size();j++)
            {
                if(k>=needle.size())
                    break;
                if(haystack[j]!=needle[k++])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                return ret;
            }
        }
        return -1;
    }
};
