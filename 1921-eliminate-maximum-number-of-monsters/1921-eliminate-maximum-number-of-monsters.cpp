class Solution 
{

    public:
    
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        vector<int>timeArray;
        
        int count = dist.size();
        int temp=0; 
        int element = 0;
        int var=0;
        
        for(int i=0;i < count;i++)
        {
            timeArray.push_back( ceil( (double)dist[i] / (double)speed[i]) );
        }
        
        sort( timeArray.begin(), timeArray.end() );
                
        while( temp < timeArray.size())
        {
            if( element >= timeArray[temp])
            {
                break;
            }
            
            temp++; 
            element++; 
            var++;
        }
        
        return var;
        
    }
};