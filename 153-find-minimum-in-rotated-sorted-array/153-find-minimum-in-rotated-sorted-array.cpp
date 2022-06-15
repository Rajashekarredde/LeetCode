class Solution 
{
  public:
    int findMin(vector<int>& nums) 
    {
        int s=0,e=nums.size()-1,ans=min(nums[e],nums[s]);
        while(s<=e)
        {
            int m=s+(e-s)/2;
         
            if(nums[m]>nums[e]&&nums[m]>=nums[s])
                s=m+1;
            else 
                e=m-1;
            
            ans=min(nums[m],ans);
        }
        return ans;
    }
};