class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {  
        int count = 1;
        int unique = 0;
        int n = nums.size();
        
        for( int i = 1; i<n; ++i )
        {
            if( nums[unique] != nums[i] )
            {
                unique++;
                nums[ unique ] = nums[i];
                count++;
            }
        }
        return count;
    }
};