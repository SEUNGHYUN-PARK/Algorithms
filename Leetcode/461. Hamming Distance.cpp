class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt=0;
        while(true)
        {
            int xt=x%2,yt=y%2;
            if(xt!=yt) cnt++;
            x=x/2;
            y=y/2;
            if(x==0&&y==0) break;
        }
        return cnt;
    }
};