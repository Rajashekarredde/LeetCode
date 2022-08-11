class Solution {
public:
    bool isValid(string s) 
    {
        int n = s.length();
        if( n < 2)
            return false;
        
        stack<char> store;
        for( int i = 0; i<n; ++i )
        {
            if( s[i] == '(' || 
                s[i] == '{' ||
                s[i] == '[' )
            {
                store.push(s[i]);
            }
            else if( !store.empty() )
            {
               char c = store.top();
               store.pop();
               if( (s[i] == ')' && c != '(' ) ||
                   (s[i] == ']' && c != '[' ) ||
                   (s[i] == '}' && c != '{' ) )
                   return false;
            }
            else
                return false;
        }
        if( store.empty() )
        return true;
        return false;
    }
};