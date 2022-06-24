class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
           int minprice=INT_MAX;
        int maxprofit=INT_MIN;
        for(int i:prices){
            minprice=min(minprice,i);
            maxprofit=max(maxprofit,i-minprice);
        }
        return maxprofit; 
    }
};