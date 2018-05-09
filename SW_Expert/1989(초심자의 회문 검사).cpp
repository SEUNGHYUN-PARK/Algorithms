#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
int tc=1;
int t;
 
int main(void)
{
    scanf("%d",&t);
    while(t--)
    {
        stack<char> st;
        string s;
        string cmp="";
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            st.push(s[i]);
        }
        while(!st.empty())
        {
            cmp.push_back(st.top());
            st.pop();
        }
        if(s==cmp)
            printf("#%d 1\n",tc++);
        else
            printf("#%d 0\n",tc++);
    }
}