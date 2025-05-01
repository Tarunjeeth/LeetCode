class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                for (int k=0;k<n-1;k++){
                    if (grid[i][k]<grid[i][k+1]){
                        int temp=grid[i][k+1];
                        grid[i][k+1]=grid[i][k];
                        grid[i][k]=temp;
                    }
                }
            }
        }
        int sum=0;
        int max;
        for (int i=0;i<n;i++){
            max=-1;
            for (int j=0;j<m;j++){
                if (grid[j][i]>max){
                    max=grid[j][i];
                }
            }
            sum+=max;
            max=-1;
        }
        return sum;
    }
};