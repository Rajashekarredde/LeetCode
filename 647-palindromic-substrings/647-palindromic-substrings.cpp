class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.length();
        int l, r, ans = 0;
        for( int i =0; i<n; ++i )
        {
            ans += countPali( s, i, i );
            ans += countPali( s, i, i+ 1);
        }
        return ans;
    }
    
    int countPali( string s, int l, int r )
    {
        int ans =0;
        int n = s.length();
        while( l >= 0 && r < n && s[l] == s[r] )
         {
                 l--;
                 r++;
                 ans++;
        }
        return ans;
    }
};