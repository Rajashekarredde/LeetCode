class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int num = 0;
        
        for ( auto it = accounts.begin(); it != accounts.end(); ++it)
        {
            int tempSum =0;            
            for (auto sun = (*it).begin(); sun != (*it).end() ;++sun )
               tempSum = tempSum + *sun;
            if( tempSum > num )
                num = tempSum;
        }
        
        return num;        
    }
};