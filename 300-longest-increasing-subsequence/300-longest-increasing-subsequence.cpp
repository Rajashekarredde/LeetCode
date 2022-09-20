class Solution {
public:
    int binarySearch( vector<int>& nums )
    {
        vector<int> ans;
        int n = nums.size();
        ans.push_back( nums[0] );
        for( int i = 1; i<n; i++ )
        {
            if( ans.back() < nums[i] )
                ans.push_back( nums[i] );
            else
            {
                int index = lower_bound( ans.begin(), ans.end(), nums[i] ) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    
    int solver( vector<int>&nums, int cur, int prev, vector< vector<int> >&dp, int n  )
    {
        if( cur ==  n )
            return 0;
        
        if( dp[cur][prev+1] != -1 )
            return dp[cur][prev+1];
        
        int take = 0;
        if( prev == -1 || nums[cur] > nums[prev] )
        {
            take = 1 + solver( nums, cur+1, cur, dp, n );
        }
        int notTake = solver ( nums, cur+1, prev, dp, n );
        
        return dp[cur][prev+1] = max( take, notTake );
    }
    
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector< vector<int> >dp(n, vector<int>(n+1, -1) );
        //int ans = solver( nums, 0, -1, dp, n );
        int ans = binarySearch( nums );
        return ans;
    }
};