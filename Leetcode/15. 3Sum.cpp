class Solution {
public:
    /* DFS Recursive search -> Time limits exceeded
    vector<vector<int>> v;
    vector<vector<int>> threeSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            vector<int> t;
            t.push_back(nums[i]);
            go(nums,t,nums[i],1,i);            
        }
         
        return v;
    }
    void go(vector<int>& nums, vector<int> before, int current, int count, int idx)
    {
        if(count==3)
        {
            if(current==0)
            {
                sort(before.begin(),before.end());
                bool flag=false;
                for(int i=0;i<v.size();i++)
                {
                    if(v[i]==before)
                        flag=true;
                }
                if(flag==false)
                     v.push_back(before);
            }
               
        }
        if(idx+1<nums.size())
        {
            go(nums,before,current,count,idx+1);
            vector<int> after = before;
            after.push_back(nums[idx+1]);
            go(nums,after,current+nums[idx+1],count+1,idx+1);
        }
        else
            return;
    }
    */
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());

        for (int i = 0; i < num.size(); i++) {
            
            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;

            while (front < back) {
                int sum = num[front] + num[back];
                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i];
                    triplet[1] = num[front];
                    triplet[2] = num[back];
                    res.push_back(triplet);
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[1]) front++;
                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[2]) back--;
                }   
            }
            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) 
                i++;

        }
        return res;
    }
    
    
};