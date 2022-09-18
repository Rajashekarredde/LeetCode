class Solution {
public:
    void solver( vector<int>&arr, int target, int index, vector<int>&ds, 
                 vector< vector<int> >&ans )
    {
        if( index == arr.size() )
        {
            if( target == 0 )
                ans.push_back( ds );
            return;
        }
        if( arr[index] <= target )
        {
            ds.push_back( arr[index] );
            solver( arr, target - arr[index], index, ds, ans);
            ds.pop_back();
        }
        solver( arr, target, index+1, ds, ans );
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector< vector<int> >ans;
        vector< int >ds; 
        solver( candidates, target, 0, ds, ans );
        return ans;
    }
};