class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        int n =  ransomNote.length();
        int m = magazine.length();
        int arr[26] = {0};
        int k;
        
        for( int i=0; i<m; ++i )
        {
            k = magazine[i] - 'a';
            arr[k]++;
        }
        
        for( int i =0; i<n; ++i )
        {
            k = ransomNote[i] - 'a';
            if( arr[k] == 0 )
                return false;
            else
                arr[k]--;
        }
        return true;
    }
};