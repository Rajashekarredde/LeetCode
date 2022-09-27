class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        int n = s.length();
        stack< pair<char, int > >st;
        st.push({s[0], 1});
        for( int i = 1; i<n; i++ )
        {
            cout<<s[i]<<endl;
            if( st.empty() || st.top().first != s[i])
            {
                st.push({s[i], 1});
                continue;
            }
            else if( st.top().first == s[i] )
            {
                auto it = st.top();
                st.pop();
                it.second += 1;
                st.push( it );
            }
            
            if( st.top().second == k )
                st.pop();
        }
        string str = "";
        while( !st.empty() )
        {
            auto it = st.top();
            st.pop();
            for( int i = 0; i < it.second; i++ )
            {
                str.push_back(it.first);
            }
        }
        
        reverse( str.begin(), str.end() );
        return str;
    }
};