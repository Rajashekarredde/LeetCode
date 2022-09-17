class Solution {
public:
    void solver( int arr[], int &count, int &prevMid )
    {
         for( int i = 0; i<26; i++ )
        {
            if( arr[i]  == 0 )
                continue;
            
            if( arr[i]%2 == 0 )
                count += arr[i];
            else
            {
                count -= prevMid;
                prevMid =( prevMid/2) * 2;
                count += prevMid;
                prevMid = arr[i];
                count += prevMid;
            }
        }        
    }
    
    int longestPalindrome(string s) 
    {
        int capArr[26] = {0};
        int smallArr[26] = {0};
        int n = s.length();
        int temp;
        for( int i = 0; i<n; ++i )
        {
            if( s[i] >= 65 && s[i] <= 90 )
            {    
                temp = s[i] - 'A';
                capArr[temp]++;
            }
            else
            {
                temp = s[i] - 'a';
                smallArr[temp]++;
            }
        }
        
        int prevMid = 0;
        int count = 0;
        solver( capArr, count, prevMid );
        solver( smallArr, count, prevMid );
        return count;
    }
};