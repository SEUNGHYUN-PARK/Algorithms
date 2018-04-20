class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<bool> check(nums.size());
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            int temp = target-nums[i];
            for(int j=0;j<nums.size();j++)
            {
                if(i==j) continue;
                if(temp==nums[j] && check[i]==false && check[j]==false)
                {
                    result.push_back(i);
                    result.push_back(j);
                    check[i]=true;
                    check[j]=true;
                }
            }
        }
        return result;
    }
};