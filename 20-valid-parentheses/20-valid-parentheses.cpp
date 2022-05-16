class Solution {
public:
    bool isValid(string s) 
    {
        std::vector<char> sun;
        for( int i = 0; i<s.length(); ++i )
        {
            if( s[i] == '(' || 
                s[i] == '[' ||
                s[i] == '{'  )
            {
                sun.push_back(s[i]);
            }
            else
            {
                
            char a = getValidChar( s[i] );
                
            if( !sun.size() ) return false;
            
            if( a == ' ' )
            {
                return false;
            }
            else if( sun.back() != a )
            {   
                return false;
            }
            else
            {
               sun.pop_back();
            }
        }
            
        }
        if( !sun.size() )
        return true;
        else
        return false;
    }
    
    char getValidChar( char a )
    {
        switch(a)
        {
            case ')' :
                return '(';
                
            case ']' :
                return '[';
                
            case '}' :
                return '{';
                
            default :
                return ' ';
        }
    }
};