bool check(string _str)
{
    for(int i=0;i<_str.size();i++)
    {
        if(_str[i]=='(')
            return true;
    }
    return false;
}
string reverseParentheses(string s)
{
    do{
        stack<char> cst;
        stack<char> sst;
        bool flag=false;
        string result;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(!cst.empty())
                {
                    cst.push(s[i]);
                    sst.push(s[i]);
                }
                else
                {
                    cst.push(s[i]);
                }
               // continue;
            }
            else if(s[i]==')')
            {
                if(!cst.empty())
                {
                    cst.pop();
                    if(!cst.empty())
                    {
                        sst.push(s[i]);
                        flag=true;
                    }

                }
                else
                {
                    cst.pop();

                }
                //continue;
            }
            if(s[i]!='('&&s[i]!=')')
            {
                if(!cst.empty())
                {
                    sst.push(s[i]);
                }
                else
                {
                    result.push_back(s[i]);
                }
            }
            if(cst.empty())
            {
                while(!sst.empty())
                {
                    result.push_back(sst.top());
                    sst.pop();
                }
                if(flag)
                {
                    for(int j=0;j<result.size();j++)
                    {
                        if(result[j]==')')
                            result[j]='(';
                        else if(result[j]=='(')
                            result[j]=')';
                    }
                    flag=false;
                }
            }
        }
        s=result;
    }while(check(s));
    return s;
}
