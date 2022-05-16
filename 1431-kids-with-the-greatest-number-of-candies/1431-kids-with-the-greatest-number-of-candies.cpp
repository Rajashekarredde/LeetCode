class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
     
        vector<bool> sunny;
        
        int lar=0;
        
        for (int i =0; i< candies.size(); ++i)
        {
            if(lar < candies[i])
            {
                lar = candies[i] ;
            }
        }
    
        for (int i =0; i< candies.size(); ++i)
        {            
            if( ( candies[i] + extraCandies ) >= lar  )
            {
            sunny.push_back( true );
            }
            else
                            sunny.push_back( false);
        }
        
        return sunny;
        
    }
};