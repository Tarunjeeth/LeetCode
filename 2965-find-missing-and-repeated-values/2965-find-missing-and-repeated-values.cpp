class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        long long n2=n*n;
        vector <int> array(n*n,0);
        vector <int> out(2,0);
        int expected_sum=n2*(n2+1)/2;
        long long expected_sq_sum=n2*(n2+1)*(2*n2+1)/6;
        int actual_sum=0;
        long long actual_sq_sum=0;
        
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                actual_sq_sum+=(grid[i][j])*(grid[i][j]);
                actual_sum+=(grid[i][j]);
            }
        }
        int c1=actual_sum-expected_sum;
        int c2=actual_sq_sum-expected_sq_sum;
        int c3=c2/c1;
        int miss=(c3-c1)/2;
        int repeat=c3-miss;
        out[0]=repeat;
        out[1]=miss;
        return out;
    }
};