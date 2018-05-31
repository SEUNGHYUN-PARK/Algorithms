class Solution {
public:
    char findTheDifference(string s, string t) {
        char ret;
        int alphabets[26] ={0,};
        int alphabett[26] ={0,};
        for(int i=0;i<s.size();i++)
        {
            alphabets[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++)
        {
            alphabett[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(alphabett[i]!=alphabets[i])
            {
                ret = i+'a';
                return ret;
            }
        }
        
    }
};