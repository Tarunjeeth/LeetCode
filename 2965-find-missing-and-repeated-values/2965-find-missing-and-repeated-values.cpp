class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();

        vector <int> array(n*n,0);
        vector <int> out(2,0);
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (array[grid[i][j]-1]!=0){
                    out[0]=grid[i][j];
                }
                else{
                    array[grid[i][j]-1]++;
                }
            }
        }
        for (int i=0;i<n*n;i++){
            if (array[i]==0){
                out[1]=i+1;
            }
        }
        return out;
    }
};