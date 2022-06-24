class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
         unordered_map< int, int> store;
         
         int n = nums.size();
         vector< int > ans;
         ans.reserve(n);

         for( int i = 0; i<n ; ++i )
         {
             if( store.find( nums[i] ) == store.end() )
                 store[ nums[i] ] = 1;
             else
                 store[ nums[i] ]++;
         }
       
        priority_queue<pair<int,int>>pq;
        for(auto i:store)
        {
            pq.push({i.second,i.first});
        }
        int i=0;
        while(i<k)
        {
            ans.push_back((pq.top()).second);
            pq.pop();
            i++;    
        }
 
        return ans;
        
    }
};