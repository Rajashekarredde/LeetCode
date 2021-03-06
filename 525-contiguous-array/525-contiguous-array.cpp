class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int sum =0, ans =0;
        
        unordered_map< int, int > store;
        store.insert({0, -1});
        
        for( int i = 0; i< nums.size(); ++i )
        {
            if( nums[i] )  sum += 1;
            else sum -= 1;
            
            if( store.find( sum ) != store.end() )
            {
                ans = max( ans, i- store[sum] );
            }
            else
            {
                store[sum] = i;
            }
        }
        return ans;
    }
};