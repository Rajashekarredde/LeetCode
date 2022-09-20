class Solution {
public:
    int firstBadVersion(int n) 
    {
        int l = 0;
        int r = n;
        int ans = INT_MAX;
        while( l <= r )
        {
            int mid = l + ( r - l )/2;
            if( isBadVersion( mid ) )
            {  
                ans = min( ans, mid );
                r = mid - 1;
            }
            else
                l = mid +1;
        }
        return ans;
    }
};