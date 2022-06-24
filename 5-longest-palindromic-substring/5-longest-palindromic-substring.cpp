class Solution {
public:
    string longestPalindrome(string s) 
    {
        int l, h, start =0, end = 1;
        int n = s.length();
        
        for( int i = 1; i<n; ++i )
        {
            l = i - 1;
            h  = i;
            
            while( l >=0 && h < n && s[l] == s[h] )
            {
                if( h - l + 1 > end )
                {
                    start = l;
                    end = h - l + 1;
                }
                l--; h++;
            }
            
            l = i - 1;
            h  = i + 1;
            
            while( l >=0 && h < n && s[l] == s[h] )
            {
                if( h - l + 1 > end )
                {
                    start = l;
                    end = h - l + 1;
                }
                l--; h++;
            }
        }
        
        string t;
        
        n = start + end ;
        
        for( int i = start; i< n ; ++i )
        {
            t.push_back( s[i] );
        }
        return t;
    }
};