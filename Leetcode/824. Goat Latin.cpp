class Solution {
public:
    string toGoatLatin(string S) {
        string ret="";
        int acnt=1;
        for(int i=0;i<S.size();i++)
        {
            int j;
            if(S[i]==' ') 
            {
                continue;   
            }
            else if(S[i]=='A'||S[i]=='a'||S[i]=='E'||S[i]=='e'||S[i]=='I'||S[i]=='i'||S[i]=='O'||S[i]=='o'||S[i]=='U'||S[i]=='u')
            {
                
                for(j=i;j<S.size();j++)
                {
                    if(S[j]==' ') break;
                    ret.push_back(S[j]);
                }
                i=j;
            }
            else
            {
                for(j=i+1;j<S.size();j++)
                {
                    if(S[j]==' ') break;
                    ret.push_back(S[j]);
                }
                ret.push_back(S[i]);
                i=j;
            }
            ret.push_back('m');
            ret.push_back('a');
            for(int i =1;i<=acnt;i++)
                ret.push_back('a');
            if(j!=S.size())
                ret.push_back(' ');
            acnt++;
        }
        return ret;
    }
};