class Solution {
public:
    int longestValidParentheses( string s )
    {
           int res = 0;
	    stack<int> st; 
	    for (int i = 0; i < s.size(); i++) {
		if (!st.empty() && s[i] == ')' && s[st.top()] == '(')
        {
            st.pop();
			res = max(res, st.empty() ? i + 1 : i - st.top());
        }
		else {
			st.push(i);
		}
	}
	return res;
}
};