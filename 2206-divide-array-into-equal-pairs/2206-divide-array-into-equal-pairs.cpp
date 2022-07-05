class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        unordered_map< int, int> store;
        int n = nums.size();
        int pair = n/ 2;

        for( int i = 0; i<n; ++i )
        {
           if( nums[i] == INT_MIN ) continue;
            
           for( int j = i + 1; j<n; ++j )
           {
               if( nums[i] == nums[j] )
               {
                   nums[i] = INT_MIN;
                   nums[j] = INT_MIN;
                   pair --;
                   break;
               }
           }
        }
        
        if( !pair ) return true;
        else return false;
        
    }
};