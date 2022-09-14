class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
         int curMin =1;
         int curMax =1;
         int temp;
         int ans = INT_MIN;
        
         for( int i = 0; i<nums.size(); ++i )
         {
             ans = max( ans, nums[i] );
         }
        
         for( int i = 0; i<nums.size(); i++ )
         {
             if( nums[i] == 0 )
             {
                 curMin = 1;
                 curMax = 1;
                 continue;
             }
             temp = nums[i] * curMax;
             curMax = max(  nums[i], max(curMin*nums[i], curMax*nums[i]) );
             curMin = min( nums[i], min( curMin*nums[i], temp) );
             ans = max( ans,curMax );
         }
         return ans;
    }
};