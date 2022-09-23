class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector< vector<int> >ans;
        solver( ans, 0, nums );
        return ans;
    }
    
    void solver( vector< vector<int> >&ans, int index, vector<int>&nums )
    {
        if( nums.size() == index )
        {
            ans.push_back( nums );
            return;
        }
        
        for( int i = index; i<nums.size(); ++i )
        {
            swap( nums[i], nums[index] );
            solver( ans, index+1, nums );
            swap( nums[i], nums[index] );
        }
    }
};