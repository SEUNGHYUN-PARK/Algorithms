class Solution {
public:
    string reverseStr(string s, int k) {
        stack<char> st;
        queue<char> q;
        string ret="";
        int i=0,j=0,l=0;
        while(i<s.size())
        {
            for(j=i;j<i+k;j++)
            {
                if(j<s.size())
                {
                    st.push(s[j]);   
                }
            }
            while(!st.empty())
            {
                ret.push_back(st.top());
                st.pop();
            }
            for(l=j;l<j+k;l++)
            {
                if(l<s.size())
                {
                    q.push(s[l]);
                }
            }
            while(!q.empty())
            {
                ret.push_back(q.front());
                q.pop();
            }
            i=l;
        }
        return ret;
    }
};