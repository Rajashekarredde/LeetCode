class Solution 
{
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int left = 0, right = 0, count =0, product = 1;
        
        int n =nums.size();
        
        while( right < n )
        {
            product *= nums[right];
            
           while( product >= k && right > left )
            {
                product = ( product / nums[left++] );
            }
            
            if( product < k )
            count += right -left  + 1;
            
            right++;
        }
        return count;
    }
};