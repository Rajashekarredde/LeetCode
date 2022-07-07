class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int n = s.length();
        string ans;
        int count =0;
        
        for( int i = n-1 ; i>=0; i-- )
        {
            if( s[i] == ' ' && !ans.empty() )
            {
                break;
            }
            else if( s[i] != ' ')
            {
                ans.push_back( s[i] );
                count++;
            }
        }
        return count;
    }
};