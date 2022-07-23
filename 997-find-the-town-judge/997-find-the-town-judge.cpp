class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
          if(trust.size() < n-1)
            return -1;

        vector<int> judge(n+1, 0) ;

        for(int i=0; i<trust.size(); i++){

            judge[ trust[i][0] ] = -1;

            if(judge[ trust[i][1] ] != -1)
                judge[ trust[i][1] ] ++;
        }

        for(int i=1; i<judge.size(); i++){
            if(judge[i] == n-1)
                return i;
        }

        return -1;
    }
};