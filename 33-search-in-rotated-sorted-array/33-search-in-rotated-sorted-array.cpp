class Solution {
public:
    int search(vector<int>& nums, int tar) 
    {  
        
        for( int i = 0 ; i< nums.size(); ++i )
        {
            if( tar == nums[i])
            {
                return i;
            }
        }
        
        return -1;
       
    }
};