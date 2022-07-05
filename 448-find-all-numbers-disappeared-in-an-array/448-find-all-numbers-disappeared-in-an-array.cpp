class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n = nums.size();
        vector< int > store;
        int k;

        for( int i =0; i<n; ++i )
        {     
              k = abs( nums[i] ) - 1;
              nums.at(k) =  -1 * abs(nums[k]);
        }
        
        for( int i =0; i<n; ++i )
        {
            if( nums[i] >= 1 )
                store.push_back( i + 1);
        }
        return store;
    }
};