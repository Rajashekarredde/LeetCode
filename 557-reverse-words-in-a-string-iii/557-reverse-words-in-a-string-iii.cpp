class Solution {
public:
    string reverseWords(string s) 
    {
        int start = 0, i;
        
        for(  i = 0; i< s.length() ; ++i )
        {
            if( s[i] == ' ' )
            {
                reverse( s.begin()+ start, s.begin() + i);
                start = i + 1;
            }
        }
        
        reverse( s.begin()+ start, s.begin() + i);
        
        return s;
    }
};