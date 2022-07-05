class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        int sum = 0, ans = 0;
        int n = arr.size();
        
        for( int i =0 ; i<n; ++i )
        {
            sum = 0;
            for( int j = i; j<n; ++j )
            {
                sum += arr[j];
                
                if( (i+j)%2 == 0 )
                {
                    ans+= sum;
                }
            }
        }
        return ans;
    }
};