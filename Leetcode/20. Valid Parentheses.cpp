class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.size()==1) return false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                st.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(st.size()>0&&st.top()=='(')
                    st.pop();
                else
                    st.push(s[i]);
            }
            else if(s[i]=='}')
            {
                if(st.size()>0&&st.top()=='{')
                    st.pop();                
                else
                    st.push(s[i]);
            }
            else if(s[i]==']')
            {
                if(st.size()>0&&st.top()=='[')
                    st.pop();                
                else
                    st.push(s[i]);
            }
        }
        
        if(st.empty()) return true;
        else return false;
    }
};