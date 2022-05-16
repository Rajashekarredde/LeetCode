class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int num=0;
        
        for (auto it =nums.begin(); it !=nums.end(); ++it )
        {
            num += *it;
            *it = num;
            
        }
        return nums;
        
    }
};