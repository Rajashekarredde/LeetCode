class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> vec = {-1, -1}; 
        int lo = 0;
        int hi = nums.size() - 1;
        
        while( lo <= hi )
        {
            int mid = lo + (hi - lo) / 2;
            
            if( nums[ mid ] == target )
            {
                vec[0] = mid; 
                hi = mid - 1;
            }
            else if( nums[ mid ] < target )
                lo = mid + 1;
            
            else
                hi = mid - 1;
        }
        
        lo = 0;
        hi = nums.size() - 1;
        
        while( lo <= hi )
        {
            int mid = lo + (hi - lo) / 2;
            
            if( nums[ mid ] == target )
            {                
                vec[1] = mid; 
                lo = mid + 1;
            }
             
            else if( nums[ mid ] < target )
                lo = mid + 1;
            
            else
                hi = mid - 1;
        }
        
        return vec;
        
    }
};