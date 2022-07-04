class Solution {
public:
    bool areOccurrencesEqual(string s)
    {
        int arr[26] = {0};
        int n = s.length(); int temp = 0;
        
        for( int i =0 ; i<n; ++i )
            arr[ s[i] - 'a' ]++;
        
        for( int i =0 ; i<26; ++i )
        {
            if( !arr[i] )
               continue;
            else if( !temp )
               temp = arr[i];
            else if( temp != arr[i] )
                return false;
        }
        return true;
    }
};