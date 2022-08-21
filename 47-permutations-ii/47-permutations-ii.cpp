class Solution {
public:
    
    void solve( int index, vector<int> &nums, vector< vector<int> > &ans, 
                set< vector<int> > &store )
    {
        if( index == nums.size() )
        {
            if( store.find(nums) == store.end() )
            {
                store.insert( nums );
                ans.push_back( nums );
            }
            return;
        }
        
        for( int i = index; i < nums.size(); ++i )
        {
            swap( nums[index], nums[i] );
            solve( index+1, nums, ans, store );
            swap( nums[index], nums[i] );
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector< vector<int> > ans;
        set< vector<int> >store;
        solve( 0, nums, ans, store );
        return ans;
    }
};