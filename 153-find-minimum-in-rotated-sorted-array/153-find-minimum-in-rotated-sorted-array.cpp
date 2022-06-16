class Solution 
{
  public:
    int findMin(vector<int>& nums) 
    {
        int start = 0, end = nums.size() - 1, mid = 0;
        
        int ans = min( nums[start], nums[end] );
        
        while( start <= end )
        {
            mid = start + ( end - start ) / 2;
            
            if( nums[mid] > nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid -1 ;
            }
            
            ans = min( ans, nums[mid] );
            
        }
        
        return ans;
    }
};