class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stS;
        stack<char> stT;
        string nS,nT;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]!='#')
                stS.push(S[i]);
            else
            {
                if(!stS.empty())
                    stS.pop();
            }
        }
        for(int i=0;i<T.size();i++)
        {
            if(T[i]!='#')
                stT.push(T[i]);
            else
            {
                if(!stT.empty())
                    stT.pop();
            }
        }
        while(!stS.empty())
        {
            nS.push_back(stS.top());
            stS.pop();
        }
        while(!stT.empty())
        {
            nT.push_back(stT.top());
            stT.pop();
        }

        if(nS==nT)
            return true;
        else
            return false;

    }
};
