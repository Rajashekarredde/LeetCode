class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
     
          int start = 0;
        int end = nums.size()-1;
        
        if (nums.size()==1){
            if (nums[0] == target)
                return {0,0};
            return {-1,-1};
        }
        
        
        while (start < end){
            if (nums[start] != target){
                start++;
            }
            if (nums[end] != target){
                end--;
            }
            
            if (nums[start] == target && nums[end] == target){
                return {start, end};
            }
            
        }
        return {-1, -1};
    }
};