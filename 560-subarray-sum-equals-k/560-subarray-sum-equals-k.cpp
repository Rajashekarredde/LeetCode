class Solution 
{
  public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> store;
        
        int n = nums.size();
        int count = 0, sum =0;
        
        for( int i = 0; i<n ; ++i )
        {
            sum = sum + nums[i];
                
            if( sum == k ) count++;
            
            if(  store.find( sum - k ) != store.end() )
            {
                count = store[ sum - k] + count;
            }
            
            if( store.find(sum) == store.end() )
            {
                store[ sum ] = 1;
            }
            else
            {
                store[sum]++;
            }
        }
        return count;
    }
};