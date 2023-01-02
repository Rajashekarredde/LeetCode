//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k)
    {
        vector<long long > ans;
        stack< long long > st;
        int temp = k;
        for( int i = 0; i<arr.size(); ++i )
        {
            st.push( arr[i] );
            temp--;
            if( i == arr.size() - 1 || temp == 0 )
            {
                while( !st.empty() )
                {
                    ans.push_back( st.top() );
                    st.pop();
                }
                temp = k;
            }
        }
        arr.clear();
        for( int i = 0; i<ans.size(); ++i )
            arr.push_back( ans[i] ); 
    }
};

//{ Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends