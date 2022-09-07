class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int i,j,k=0;
k=-1;
for(i=0;i<nums.size();i++)
{
for(j=i+1;j<nums.size();j++)
{
if(nums[j]>nums[i] && (nums[j]-nums[i])>k)
k=nums[j]-nums[i];

       }
    }
    return k;
}
        
};