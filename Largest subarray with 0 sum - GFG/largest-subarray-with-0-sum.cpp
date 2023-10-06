//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int k)
    {   
         long long sum = 0;
        int ans = 0;
        int n = nums.size();
        unordered_map<long long, int> mp;
        
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            if (sum == 0)
                ans = i + 1;
            
            long long rem = sum;
            if (mp.find(rem) != mp.end())
            {
                int idx = i - mp[rem];
                ans = max(ans, idx);
            }
            
            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends