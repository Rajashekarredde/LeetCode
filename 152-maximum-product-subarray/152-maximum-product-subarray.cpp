class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
       int maxProd = nums[0];
       int minProd = nums[0];
       int ans = nums[0];
        for( int i = 1; i<nums.size(); ++i )
        {
            int choice1 = maxProd * nums[i];
            int choice2 = minProd * nums[i];
            maxProd = max( nums[i], max( choice1, choice2) );
            minProd = min( nums[i], min( choice2, choice1 ));
            ans = max( ans, maxProd );
        }
        return ans;
    }
};