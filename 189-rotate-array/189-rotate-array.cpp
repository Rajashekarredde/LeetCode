class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
       int n = nums.size();
       k = k%n;
       solve( nums, 0, n-1);
       solve( nums, 0, k-1 );
       solve( nums, k, n-1 );
    }
    
    void solve( vector<int> &nums, int l, int r )
    {
        int temp;
        while( l < r )
        {
            temp = nums[r];
            nums[r] = nums[l];
            nums[l] = temp;
            l++;
            r--;
        }
    }
};