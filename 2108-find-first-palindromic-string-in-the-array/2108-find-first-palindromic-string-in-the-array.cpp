class Solution {
public:
    bool isPalindrome( string s )
    {
        int l = 0; int r = s.length() - 1;
        
        while( l <= r )
        {
           if( s[l] != s[r] )
              return false;
           l++; r--;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) 
    {
        int n = words.size();
        for( int i =0 ; i<n ; ++i )
        {
            if( isPalindrome( words[i] ) )
                return words[i];
        }
        return "";
    }
};