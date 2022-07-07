class Solution {
public:
    int firstUniqChar(string s) 
    {
        int arr[26]={0};
        for(int i=0;i<s.length();i++)
        {
            int c=s[i]-'a';
            arr[c]++;
        }
        
        for(int i=0;i<s.length();i++)
        {
            int c=s[i]-'a';
            if(arr[c]==1){
                return i;
            }
        }
        return -1;
    }
};