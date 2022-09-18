class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        int n = nums.size();
      
        if( n < 2 )
            return true;
        
        bool ans = true;
        bool isIncreasing;

        for( int i = 0; i<n-1; i++ )
        {
            if( nums[i] == nums[i+1] )
                continue;
            else
            {
                isIncreasing = nums[i] < nums[i+1] ? true : false;
                break;
            }
        }
        
        for( int i = 0; i<n-1; ++i )
        {
            if( isIncreasing && nums[i] > nums[i+1])
                return false;
            else if( !isIncreasing && nums[i] < nums[i+1] )
                return false;
        }
        
        return ans;
    }
};