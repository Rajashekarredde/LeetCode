class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {  
        if( !nums.size() )
        {
             return 0;    
        }
        
        int count = 1;
        int unique = 0;
        for( int i =1 ;i< nums.size() ; ++i )
        {
            if( nums[ unique ] != nums[i] )
            {
                unique+=1;
                nums[unique] = nums[i];
                count++;
            }
        }
        return count;
    }
};