class Solution 
{
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int right = 0, left = 0;
        int ans = 0;
        int product = 1;
        while( right < nums.size() )
        {
            product = product * nums[right];
            while( product >= k && right > left )
            {
                product = product/nums[left++];
            }
            
            if( product < k )
            {
                ans += (right -left) + 1;
            }
            right++;
        }
        return ans;
    }
};