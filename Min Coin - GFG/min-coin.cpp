//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int F(vector<vector<int>>&dp, int amount, vector<int>&nums, int i)
	{
	    if( i == 0 )
	    {
	        if( amount % nums[i] == 0 ) return amount / nums[i];
	        return 1e9;
	    }
	    
	    if( dp[i][amount] != -1 ) return dp[i][amount];
	    
	    int take = INT_MAX;
	    if( amount >= nums[i] )
    	    take = 1 + F(dp, amount-nums[i], nums, i);
    	 int notTake = F(dp, amount, nums, i-1);
    	 
    	 return dp[i][amount] = min(take, notTake);
	}
	
	int MinCoin(vector<int>nums, int amount)
	{
	    vector<vector<int>>dp(nums.size(), vector<int>(amount+1, -1));
	    int result = F(dp, amount, nums, nums.size()-1);
	   return  result == 1e9 ?  -1 :  result;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends