class Solution {
public:
    int countElements(vector<int>& nums) 
    {
        int n = nums.size();
        int min = INT_MAX;
        int max = INT_MIN;
        int count = 0;
        
        for( int i = 0; i<n; ++i )
        {
            if( nums[i] > max )
                max = nums[i];
            
            if( nums[i] < min )
                min = nums[i];
        }
        
          for( int i = 0; i<n; ++i )
          {
              if( max > nums[i] && nums[i] > min )
                  count++;
          }
        return count;
    }
};