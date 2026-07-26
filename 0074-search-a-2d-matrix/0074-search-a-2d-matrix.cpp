class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool val=false;
        for (int i=0;i<m;i++){
            if(i!=m-1 && matrix[i+1][0]<target){
                continue;
            }
            for (int j=0;j<n;j++){
                if (matrix[i][j]==target){
                    val=true;
                }
            }
        }
        return val;
    }
};