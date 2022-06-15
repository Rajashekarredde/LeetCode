class Solution {
public:
    int search(vector<int>& nums, int tar) 
    {
         int low=0,high=nums.size()-1;
        
        while(low<=high)
        {
            long long mid=((high+low)/2);
            
            if(nums[mid]==tar)
            return mid;
            
            if(nums[low]<=nums[mid])
            {
                if(tar>=nums[low] and tar<nums[mid])
                high=mid-1;
                else
                low=mid+1;
            }
			else
            {
                if(tar>nums[mid] and tar<=nums[high])
                low=mid+1;
                else
                high=mid-1;
            }     
        }
        
        return -1;    
        
    }
};