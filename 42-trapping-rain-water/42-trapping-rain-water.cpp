class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        
        int maxLeft = INT_MIN, maxRight = INT_MIN;
        
        int left = 0, right = n-1;
        
        int ans = 0;
        
        while( left <= right )
        {
            if( height[left] <= height[right] )
            {
                if( maxLeft < height[left] )
                    maxLeft = height[left];
                else
                    ans += ( maxLeft - height[left] );
                left++;
            }
            else
            {
                if( maxRight < height[right] )
                    maxRight = height[right];
                else
                    ans += ( maxRight - height[right] );
                right--;
            }
        }
        return ans;
    }
};