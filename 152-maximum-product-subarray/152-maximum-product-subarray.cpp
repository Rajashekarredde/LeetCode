class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];
        for( int i = 1; i<nums.size(); ++i )
        {
            int choice1 = maxi * nums[i];
            int choice2 = mini * nums[i];
            maxi = max( nums[i], max(choice1, choice2) );
            mini = min( nums[i], min(choice1, choice2) );
            ans = max( ans, maxi );
        }
        return ans;
    }
};