class Solution {
public:
int pivotIndex(vector<int>& nums) 
{
    int n = nums.size();
    
    int lsum =0, rsum= 0;
    
    for( int i =1; i< n ; ++i )
    {
        rsum = rsum + nums[i];
    }
    
    for( int i =0 ;i < n; ++i )
    {
        if( lsum ==rsum) return i;
        else
        {
            lsum = lsum + nums[i];
            
            if( i+1 < n )  rsum = rsum - nums[i+1];
        }
    }
    return -1;
}

};