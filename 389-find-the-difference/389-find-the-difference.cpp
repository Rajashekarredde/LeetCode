class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        int n = t.length();
        int m = s.length();
        bool isFound;
        
        for( int i=0; i<n; ++i )
        {
            isFound = false;
            for( int j =0; j<m; ++j )
            {
                if( t[i]  == s[j] )
                {
                    isFound = true;
                    s[j] = '\0';
                    break;
                }
            }
            
            if( !isFound )
                return t[i];
        }
        return ' ';
    }
};