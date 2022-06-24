class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int n = nums.size();
        priority_queue< int, vector<int>, greater<int> > store;
        
        for( int i =0; i<k; ++i )
        {
            store.push( nums[i] );
        }
        
        for( int i =k; i<n; ++i )
        {
            if( store.top() < nums[i] )
            {
                store.pop();
                store.push( nums[i] );
            }
        }
        return store.top();
    }
};