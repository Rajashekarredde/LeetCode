class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string ans;
        sort( strs.begin(), strs.end() );
        string first = strs[0];
        int n = strs.size();
        string last = strs[n-1];
        for( int i =0; i<first.length(); ++i )
        {
            if(  first[i]  == last[i] )
                ans.push_back( first[i] );
            else
                break;
        }
        return ans;
    }
};