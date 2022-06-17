class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
           if(k==0)
            return 0;
        
        int ans = 0,p=1,i=0,j=0;
        for(i=0;i<nums.size();i++)
        {
            p *= nums[i];
            
            while(j<i && p>=k)
                p /= nums[j++];
            
            if(p<k)
                ans += i-j+1;
            
            
        }
        return ans;
    }
};