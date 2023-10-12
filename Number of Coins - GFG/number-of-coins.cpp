//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int F( vector<vector<int>>&dp, int coins[], int V, int i)
	{
	    if( i == 0 )
	    {
	        if( V % coins[i] == 0 ) return V / coins[i];
	        return 1e9;
	    }
	    
	    if( dp[i][V] != -1) return dp[i][V];
	    
	    int notake = F(dp, coins, V, i-1);
	    int take = INT_MAX;
	    
	    if( V >= coins[i] )
	        take = 1 + F(dp, coins, V-coins[i], i);
	    
	    return dp[i][V] = min(take, notake);
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>>dp(M, vector<int>(V+1, -1));
	    int result = F(dp, coins, V, M-1);
	    return (result == 1e9) ? -1 : result;    
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends