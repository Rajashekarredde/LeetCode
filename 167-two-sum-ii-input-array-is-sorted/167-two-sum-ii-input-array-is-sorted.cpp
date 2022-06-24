class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
       int left = 0;
       int right = numbers.size() - 1;
        int n = numbers.size();
       
        vector<int> ans;
        
        for( int i =0; i<n; ++i )
        {
            if( numbers[left] + numbers[right]  == target )
            {
                ans.push_back( left + 1);
                ans.push_back( right + 1);
                return ans;
            }
            else if( numbers[right] + numbers[left] > target )
            {
                right--;
            }
            else
                left++ ;
        }
                        return ans;
    }
};