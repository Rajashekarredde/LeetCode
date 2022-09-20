class Solution {
public:
    int maxProfit(vector<int>& arr) 
    {
        int n = arr.size();
        
        int profit = 0;
        
        int mini = arr[0];
        
        for( int i = 1; i<n; i++ )
        {
            if( arr[i] < mini )
                mini = arr[i];
            else if( arr[i] - mini > profit )
            {
                profit = arr[i] - mini;
            }
        }
        return profit;
    }
};