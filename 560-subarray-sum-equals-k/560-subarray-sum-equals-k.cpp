class Solution 
{
  public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> store;
        int sum = 0;
        int count = 0, n = nums.size();
        
        for( int i= 0; i<n ; ++i )
        {
            sum += nums[i];
            
            if( sum == k )
            {
                 count++;
            }
            
            if( store.find( sum - k ) != store.end() )
            {
                count = count + store[ sum - k ];
            }
            
            if( store.find( sum ) != store.end() )
            {
                store[sum]++;
            }
            else
            {
                store[sum] = 1;
            }
        }
        return count;
    }
};