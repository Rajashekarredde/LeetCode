class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        int k;
        vector<int> store;
        
        for( int i =0 ; i<n ; ++i )
        {
            k = (  abs(nums[i]) - 1) ;
            if( nums.at(k) < 0 )
            {
                store.push_back( abs(nums[i]) );
            }
            nums.at(k) = -1 * abs( nums[k] );
        }
        return store;
    }
};