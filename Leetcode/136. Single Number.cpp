class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            bool flag=false;
            for(int j=0;j<nums.size();j++)
            {
                if(i==j) continue;
                if(nums[i]==nums[j]) flag=true;
            }
            if(flag==false)
                return nums[i];
        }
    }
};