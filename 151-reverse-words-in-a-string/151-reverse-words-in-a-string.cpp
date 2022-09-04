class Solution {
public:
    string reverseWords(string s) 
    {
        string str;
        stack<string> st;
        vector<string> store;
        for( int i = 0; i<s.length(); ++i )
        { 
            if( s[i] != ' ' )
            {
                str.push_back(s[i]);
            }
            else if( !str.empty() )
            {
                st.push( str );
                str.clear();
            }
        }
        if( !str.empty() )
          st.push( str );
        str.clear();
        while( !st.empty() )
        {
            string k = st.top();
            st.pop();
            str.append(k);
            if( !st.empty() )
            str.append(" ");
        }
        return str;
    }
};