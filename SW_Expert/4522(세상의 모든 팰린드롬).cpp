#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
bool is_palindrome(string s)
{
    string ss = s;
    string temp = s;
    reverse(temp.begin(),temp.end());
    for(int i=0;i<ss.size();i++)
    {
        if(temp[i]=='?')
            temp[i]=ss[i];
        if(ss[i]=='?')
            ss[i]=temp[i];
    }
    if(temp==ss)
        return true;
    else
        return false;
}
bool is_patterned(string s)
{
    int q_cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='?')
            q_cnt++;
    }
    if(q_cnt==0)
        return false;
    else
        return true;
}
int main(void)
{
    int T;
    scanf("%d",&T);
    for(int test_case=1;test_case<=T;test_case++)
    {
        string result;
        string s;
        cin>>s;
        if(is_patterned(s))
        {
            if(is_palindrome(s))
            {
                result="Exist";
            }
            else
            {
                result="Not exist";
            }
        }
        else
        {
            if(is_palindrome(s))
            {
                result="Exist";
            }
            else
            {
                result="Not exist";
            }
        }
        cout<<"#"<<test_case<<" "<<result<<"\n";
    }
}
