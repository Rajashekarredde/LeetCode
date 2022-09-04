class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        
        int l, r;
        int start = 0;
        int end = 1;
        
        for( int i = 0; i<n; ++i )
        {
            l = i, r= i;
            
            while( l >= 0 && r < n && s[l] == s[r] )
            {
                if( r - l + 1 > end )
                {
                    start = l;
                    end = r-l+1;
                }
                l--; r++;
            }
            
                        l = i, r= i+1;
            
            while( l >= 0 && r < n && s[l] == s[r] )
            {
                if( r - l + 1 > end )
                {
                    start = l;
                    end = r-l+1;
                }
                l--; r++;
            }
        }
        
        n = start+ end;
        string ans;
        for( int i = start; i<n; ++i )
        {
            ans.push_back( s[i] );
        }
        return ans;
    }
};