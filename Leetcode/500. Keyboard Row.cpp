class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
 
        for(int i=0;i<words.size();i++)
        {
            int top=0;
            int mid=0;
            int bot=0;
            for(int j=0;j<words[i].size();j++)
            {
                if(words[i][j]=='Q'||words[i][j]=='W'||words[i][j]=='E'||words[i][j]=='R'||words[i][j]=='T'||words[i][j]=='Y'||words[i][j]=='U'||words[i][j]=='I'||words[i][j]=='O'||words[i][j]=='P'||words[i][j]=='q'||words[i][j]=='w'||words[i][j]=='e'||words[i][j]=='r'||words[i][j]=='t'||words[i][j]=='y'||words[i][j]=='u'||words[i][j]=='i'||words[i][j]=='o'||words[i][j]=='p') top++;
                else if(words[i][j]=='A'||words[i][j]=='S'||words[i][j]=='D'||words[i][j]=='F'||words[i][j]=='G'||words[i][j]=='H'||words[i][j]=='J'||words[i][j]=='K'||words[i][j]=='L'||words[i][j]=='a'||words[i][j]=='s'||words[i][j]=='d'||words[i][j]=='f'||words[i][j]=='g'||words[i][j]=='h'||words[i][j]=='j'||words[i][j]=='k'||words[i][j]=='l') mid++;
                else bot++;
            }
            if(top==0&&mid==0&&bot>0) ret.push_back(words[i]);
            if(top==0&&mid>0&&bot==0) ret.push_back(words[i]); 
            if(top>0&&mid==0&&bot==0) ret.push_back(words[i]);
        }
        return ret;
    }
};