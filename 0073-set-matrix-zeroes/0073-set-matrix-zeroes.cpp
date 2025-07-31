class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector <int> rows;
        vector <int> columns;

        int m=matrix.size();
        int n=matrix[0].size();

        vector <vector<int>> flags(m,vector<int>(n,0));

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (matrix[i][j]==0){
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }

        for (int i=0;i<rows.size();i++){
            for (int j=0;j<n;j++){
                matrix[rows[i]][j]=0;
            }
        }

        for (int i=0;i<columns.size();i++){
            for (int j=0;j<m;j++){
                matrix[j][columns[i]]=0;
            }
        }
    }
};