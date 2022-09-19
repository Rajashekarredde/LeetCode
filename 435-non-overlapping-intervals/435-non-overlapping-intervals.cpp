class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        if( !n )
            return 0;
        sort( intervals.begin(), intervals.end() );
        vector<int> temp = intervals[0];
        int count = 0;
        for( auto it = intervals.begin()+1; it != intervals.end(); it++ )
        {
            if( temp[1] > it[0][0] )
            {
                count++;
                temp[1] = min( temp[1], it[0][1] );
            }
            else
            {
                temp[0] = it[0][0];
                temp[1] = it[0][1];
            }
        }
        return count;
    }
};