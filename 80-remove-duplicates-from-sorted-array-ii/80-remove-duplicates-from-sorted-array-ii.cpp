class Solution {
public:
    int removeDuplicates(vector<int>& a) 
    {
        int k = 0;
        int cnt = 1;
        int n = a.size();
        
        for(int i = 1; i < n; ++i)
        {
            if(a[i] == a[i-1]) {
                cnt++;
                if(cnt <= 2){
                    a[++k] = a[i];
                }
            }else{
                a[++k] = a[i];
                cnt = 1;
            }
        }
        return k + 1;
    }
};