class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int start = 0;
        int n = nums.size() - 1;
        int end = n;
        
        int mid = 0;
        
        vector<int> pos = {-1, -1};
        
        while( start <= end )
        {
            mid = start + ( end - start ) / 2;
            
            if( nums[mid] == target )
            {
                pos[0] = mid;
                end = mid - 1;
            }
            else if( nums[ mid] < target )
            {
                start = mid + 1; 
            }
            else 
                end = mid - 1; 
        }
        
         start = 0;
         end = n;
        
         while( start <= end )
        {
            mid = start + ( end - start ) / 2;
            
            if( nums[mid] == target )
            {
                pos[1] = mid;
                start = mid + 1;
            }
            else if( nums[ mid] < target )
            {
                start = mid + 1; 
            }
            else end = mid - 1; 
        }
        
        return pos;
    }
};