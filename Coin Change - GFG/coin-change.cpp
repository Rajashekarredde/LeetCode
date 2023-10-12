//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    long long int F(vector<vector<long long>>&dp, int coins[], int i, int sum)
    {
        if( i == 0)
        {
            if( sum % coins[i] == 0 ) return 1;
            return 0;
        }
        
        if( dp[i][sum] != -1 ) return dp[i][sum];
        
        long long int take = 0;
        if( sum >= coins[i] )
        {
            take =  F(dp, coins, i, sum-coins[i]);
        }
        long long int notake = F(dp, coins, i-1, sum);
        
        return dp[i][sum] = take+ notake;
    }
    
    long long int count(int coins[], int N, int sum) 
    {
        vector<vector<long long int>> dp(N, vector<long long int>(sum + 1, -1));
        return F(dp, coins, N - 1, sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends