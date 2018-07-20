class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),i;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])break;
        }
        int id = i+1;
        for(int j=i+1;j<n;j++)
        {
            if(nums[j]>nums[i])id = j;
        }
        if(i!=-1)swap(nums[id] , nums[i]);
        sort(nums.begin() + i +1 , nums.end());
    }
};