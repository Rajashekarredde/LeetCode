class Solution {
public:
    string longestPalindrome(string s) 
    {
        int l, h;
        
        int start =0, end = 1;
        int n = s.length();
        
        for( int i = 1; i< n; ++i )
        {
            l = i - 1;
            h = i;
            
            while( l >= 0 && h < n && s[l] == s[h] )
            {
                if( h - l + 1 > end  )
                {
                    end = h - l + 1;
                    start = l;
                }
                l--; h++;
            }
            
            
            l = i - 1;
            h = i + 1;
            
            while( l >= 0 && h < n && s[l] == s[h] )
            {
                if( h - l + 1 > end  )
                {
                    end = h - l + 1;
                    start = l;
                }
                l--; h++;
            }
        }
        
        string t;
        for( int i =start; i< (start + end); ++i )
        {
            t.push_back( s[i] );
        }
        return t;
    }
};