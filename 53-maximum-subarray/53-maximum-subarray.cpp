class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int max_so_far = nums[0];
        
        int max_end = 0, n = nums.size();
        
        for( int i = 0; i<n; ++i )
        {
            max_end = max_end + nums[i];
            
            if( max_so_far < max_end )
            {
                max_so_far = max_end;
            }
            
            if( max_end < 0 )
            {
                max_end = 0;
            }
        }
        
        return max_so_far;
    }
};