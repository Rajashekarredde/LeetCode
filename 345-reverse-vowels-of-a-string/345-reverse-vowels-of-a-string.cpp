class Solution {
public:
    bool isVowel( char a )
    {
        if( a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' 
        ||  a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' )
        {
            return true;
        }
        return false;
    }
    
    string reverseVowels(string s) 
    {
        int l =0, r = s.length() - 1;
        char temp;
        
        while ( l < r )
        {
            if( !isVowel( s[l] ) ) l++;
            
            if( !isVowel( s[r] ) ) r--;        
            
            if( isVowel( s[l]) && isVowel( s[r] ) )
            {
                temp = s[l];
                s[l]  = s[r];
                s[r] = temp;
                l++;
                r--;
            }
        }
        return s;
    }
};