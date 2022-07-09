class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
       unordered_map<int, int> store;
       int n = nums.size();
        
        for( int i =0; i<n; ++i  )
        {
            store[nums[i]]++;
        }
        
        for( auto itr : store )
        {
            if( itr.second == 1 )
                return itr.first;
        }
        return 0;
    }
};