class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
       int maxLeft = INT_MIN, maxRight = INT_MIN;
       int l = 0, r = n-1;
        int ans = 0;
        
        while( l <= r )
        {
            if( height [l] <= height[r] )
            {
                if( maxLeft < height[l] )
                    maxLeft = height[l];
                else
                    ans += maxLeft - height[l];
                l++;
            }
            else
            {
                if( maxRight < height[r] )
                    maxRight = height[r];
                else
                    ans += maxRight - height[r];
                r--;
            }
        }
        return ans;
    }
};