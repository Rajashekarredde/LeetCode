class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
       int mul = nums[0];
       
        vector<int> store(n, 0);
        
        mul = nums[0];
        store[0] = 1;
        
        for( int i = 1; i<n ; ++i )
        {
            store[i] = mul;
            mul = mul * nums[i];
        }
        
        mul = nums[n -1];
        
        for( int i = n-2; i>=0; i-- )
        {
            store[i] = store[i] * mul;
            mul = mul * nums[i];
        }
        return store;
        
    }
};