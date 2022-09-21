class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<long long> st;
        int n = tokens.size();
        long long sol = 0;
        for( int i = 0; i<n; i++ )
        {
            if( tokens[i] != "+" && tokens[i] != "-" &&
                tokens[i] != "*" && tokens[i] != "/" )
            {
                st.push( stoi(tokens[i]) );
            }
            else
            {
                long long val2 = st.top();
                st.pop();
                long long val = st.top();
                st.pop();
                
                if( tokens[i] == "+" )
                     sol = (val + val2);
                else if( tokens[i] == "-" )
                    sol  = (val - val2);
                else if( tokens[i] == "/" )
                    sol  = (val / val2);
                else if( tokens[i] == "*" )
                    sol  = (val * val2);
                    
                st.push( sol );
            }
        }
        return st.top();
    }
};