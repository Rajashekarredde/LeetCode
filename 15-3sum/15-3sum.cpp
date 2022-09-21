class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort( nums.begin(),nums.end() );
        int l, r;
        int n = nums.size();
        vector< vector<int> >sol;
        for( int i = 0; i<n; i++ )
        {
            if( i > 0 && nums[i] == nums[i-1] )
                continue;
            else
            {
                l = i+1;
                r = n -1;
                int val = 0 - (nums[i] );
                while( l < r )
                {
                    if( nums[l] + nums[r] == val  )
                    {
                        sol.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        while( nums[l] == nums[l-1] && l < r )
                            l++;
                    }
                    else if(  nums[l] + nums[r] < val )
                        l++;
                    else if( nums[l] + nums[r] > val )
                        r--;
                }
            }
        }
        return sol;
    }
};