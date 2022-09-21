class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1;
        int high = INT_MIN;
        for( int i = 0; i< piles.size(); ++i )
        {
            low = min( low, piles[i] );
            high = max( high, piles[i] );
        }
        
        long long ans, sum;
        
        while( low <= high )
        {
            long long mid = (low+high)/2;
            sum = 0;
            for( int i = 0; i<piles.size(); i++ )
            {
                sum +=  (piles[i]/mid);
                if( piles[i]%mid != 0  ) sum += 1;
            }
            if( sum <= h )
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};