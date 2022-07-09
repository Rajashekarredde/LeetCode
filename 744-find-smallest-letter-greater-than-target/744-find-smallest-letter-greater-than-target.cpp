class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int n = letters.size();
        char c = ' ';
        
        for(  int i =0; i<n; ++i )
        {
            if(  letters[i] > target && ( c == ' ') )
            {
                return letters[i];
            }
            else if( ( i == n-1 ) && c == ' ' )
            {
                return letters[0];
            }
        }
        return ' ';
    }
};