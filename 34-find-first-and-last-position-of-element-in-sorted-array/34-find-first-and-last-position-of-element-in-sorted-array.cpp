class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
     
        vector<int> vec = {-1, -1};
        
        int lo = 0;
        int hi = nums.size() - 1;
        
        //first position
        while( lo <= hi )
        {
            //to avoid overflow not using mid = (  lo + hi  ) / 2
            int mid = lo + (hi - lo) / 2;
            
            if( nums[ mid ] == target )
            {
                
                vec[0] = mid; //storing the potential first position
                //keep searching on left
                hi = mid - 1;
            }
                
             //Basic Binary search operations
            else if( nums[ mid ] < target )
                lo = mid + 1;
            
            else
                hi = mid - 1;
        }
        
        //resetting the values of hi and lo
        lo = 0;
        hi = nums.size() - 1;
        
        
        //last position
        while( lo <= hi )
        {
            //to avoid overflow not using mid = (  lo + hi  ) / 2
            int mid = lo + (hi - lo) / 2;
            
            if( nums[ mid ] == target )
            {
                
                vec[1] = mid; //storing the potential last position
                
                // keep searching on right
                lo = mid + 1;
            }
             
            //Basic Binary search operations
            else if( nums[ mid ] < target )
                lo = mid + 1;
            
            else
                hi = mid - 1;
        }
        
        return vec;
        
    }
};