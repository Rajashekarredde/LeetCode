class Solution {
public:
    int search(vector<int>& nums, int tar) 
    {  
        int start = 0, mid = 0;
        
        int end = nums.size() - 1;
        
        while( start <= end )
        {
            mid = start + ( end - start ) / 2;
            
            if( nums[mid] == tar )
            {
                return mid;
            }
            
            if( nums[start] <= nums[mid] )
            {
                if( tar >= nums[start] && tar < nums[mid] )
                   end = mid - 1;
                else 
                    start = mid + 1;
            }
            else
            {
                if( tar > nums[mid] && tar <= nums[end] )
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        
        return -1;
       
    }
};