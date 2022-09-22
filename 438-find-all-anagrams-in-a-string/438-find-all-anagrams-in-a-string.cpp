class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
                
        int s_len = s.length();
        int p_len = p.length();
        
        if(s.size() < p.size()) return {};
        
        vector<int>s_freq( 26, 0 );
        vector<int>p_freq( 26, 0 );
        
        for( int i=0; i<p.length(); ++i )
        {
            s_freq[ s[i] - 'a']++;
            p_freq[ p[i] - 'a']++;
        }
        
        vector<int> ans;
        if( p_freq == s_freq )
            ans.push_back(0);

        
        for(int i = p_len; i<s.length(); i++ )
        {
            s_freq[ s[i - p_len] - 'a' ]--;
            s_freq[ s[i] - 'a']++;
            
            if( p_freq == s_freq )
                ans.push_back( (i-p_len) + 1 );
        }        
        return ans;
    }
};