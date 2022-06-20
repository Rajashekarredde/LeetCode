class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        
        int ans = 0, sum =0;
        unordered_map< int , int> store;
                
        for ( int i = 0; i< nums.size(); ++i )
        {
            sum += nums[i] == 0 ? -1 : 1;
            
            if( sum == 0  && ( ans < i+ 1) )
            {
                ans = i + 1;
            }
            else if( store.find( sum) != store.end() )
            {
                ans = max( ans, i - store[ sum ] );
            }
            else
            {
                store[ sum ] = i;
            }
        }
        return ans;
           
    }
};