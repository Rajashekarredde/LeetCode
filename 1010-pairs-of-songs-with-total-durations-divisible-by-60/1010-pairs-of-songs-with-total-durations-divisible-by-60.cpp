class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        unordered_map<int, int> mp;
        int count = 0;
        int n = time.size();
        for( int i = 0; i<n; i++ )
        {
            time[i] = time[i]%60;
            
            int num = time[i] == 0 ? 60 : time[i];
            if( mp.find( 60 - num ) != mp.end() )
                count += mp[ 60 - num ];
            mp[time[i]]++;
        }
        return count;
    }
};