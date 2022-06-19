class Solution {
public:
    int findMiddleIndex(vector<int>& nums) 
    {
    
    int rsum=0;
    int lsum=0;
    
    for(int i=1;i<nums.size();i++)
    {
        rsum=rsum+nums[i];
    }
    
    for(int i=0;i<nums.size();i++)
    {
        if(lsum==rsum)
            return i;
        else
        {
            lsum=lsum+nums[i];
            
            if( i+1 < nums.size() )
                rsum = rsum-nums[i+1];
        }
    }
    return -1;
        
    }
};