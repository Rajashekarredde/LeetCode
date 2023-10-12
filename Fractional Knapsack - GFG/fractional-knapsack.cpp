//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comparator( Item i, Item j )
    {
        double a = (double) i.value / (double) i.weight;
        double b = (double) j.value / (double) j.weight;
        return a > b;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, comparator);
        int curW = 0;
        double val = 0.0;
        for( int i = 0; i<n; i++ )
        {
            if( curW + arr[i].weight < W )
            {
                curW += arr[i].weight;
                val += arr[i].value;
            }
            else
            {
                double t = W - curW;
                double v = (double)arr[i].value/ (double)arr[i].weight;
                val += (v*t);
                break;
            }
        }
        return val;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends