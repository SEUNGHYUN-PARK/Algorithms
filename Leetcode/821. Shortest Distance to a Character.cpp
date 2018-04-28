class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> loc;
        vector<int> ret;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]==C)
                loc.push_back(i);
        }
        for(int i=0;i<S.size();i++)
        {
            int min_idx=10000;
            for(int j=0;j<loc.size();j++)
            {
                int temp = abs(i-loc[j]);
                min_idx=min(min_idx,temp);
            }
            ret.push_back(min_idx);
        }
        return ret;
    }
};