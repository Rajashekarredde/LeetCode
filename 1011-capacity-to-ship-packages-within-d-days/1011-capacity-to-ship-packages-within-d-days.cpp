class Solution {
public:
    bool solve( vector<int>&weights, int n, int mid, int days )
    {
        int sum = 0, temp_d = 1;
        for( int  i = 0 ; i<n; ++i )
        {
            if( sum + weights[i] <= mid )
            {
                sum += weights[i];
            }
            else
            {
                sum = weights[i];
                temp_d++;
            }
        }
        
        if( temp_d <= days )
            return true;
        else
            return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days)
    {
        int low = INT_MIN, high= 0;
        int n = weights.size();
        for( int i = 0; i<n; ++i )
        {
            low = max(low, weights[i] );
            high += weights[i];
        }
        int ans = 0;
        while( low <= high )
        {
            int mid = (low+high)/2;
            if( solve( weights, n, mid, days ) )
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};