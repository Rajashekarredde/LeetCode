class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int nonZero = 0;
        int count = 0;
        for( int i = 0 ; i< nums.size(); ++i )
        {
            if( nums[i] )
            {
                nums[nonZero] = nums[i];
                nonZero++;
            }
            else
            {
                count++;
            }
        }
        
        for( int i = 0 ; i< count; ++i )
        {
            nums[nonZero] = 0;
            nonZero++;
        }
        
    }
};