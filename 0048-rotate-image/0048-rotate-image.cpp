class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //(n*(n+1))/2;           //(no of swaps needed) or (no of elements below or above diagonal)
        for (int i=0;i<n;i++){      //taking transpose
            for (int j=i;j<n;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }

        for (int i=0;i<n;i++){
            int low=0;
            int high=n-1;
            while(low<=high){
                int temp=matrix[i][low];
                matrix[i][low]=matrix[i][high];
                matrix[i][high]=temp;
                low++;
                high--;
            }
        }
    }
};