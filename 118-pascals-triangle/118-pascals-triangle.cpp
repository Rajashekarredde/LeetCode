class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector< vector<int> >answer;
        
        for( int i = 0; i< numRows; ++i )
        {
            vector<int> temp(i+1);
            temp[0] = 1;
            temp[i] = 1;
            if( i == 0 || i == 1 )
            {
                answer.push_back( temp );
                continue;
            }
            
            for( int j = 1; j < i; j++ )
            {
                temp[j] = answer[i-1][j-1] + answer[i-1][j];
            }
            answer.push_back( temp );
        }
        return answer;
    }
};