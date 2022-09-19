class Solution {
public:
    int maxArea(vector<int>& arr) 
    {
        int left = 0; 
        int right = arr.size() - 1;
        int ans = INT_MIN;
        while( left < right )
        {
            ans = max( ans, ( min( arr[left], arr[right] )*( right - left) ) ) ;
            if( arr[left] < arr[right] )
                left++;
            else if( arr[left] > arr[right] )
            {
               right--; 
            }
            else
            {
                left++; right--;
            }
        }
        return ans;
    }
};