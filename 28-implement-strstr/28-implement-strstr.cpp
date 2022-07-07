class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int m = haystack.length();
        int n = needle.length();
        bool isFound = false;
        
        for( int i =0; i<m; ++i )
        {
            if( haystack[i] == needle[0] )
            {
                for( int j=0; j<n; ++j )
                {
                    if( haystack[i+j] != needle[j] )
                    {
                        isFound = false;
                        break;
                    }
                    else
                        isFound = true;
                }
            }
            
            if( isFound ) return i;
        }
        return -1;
    }
};