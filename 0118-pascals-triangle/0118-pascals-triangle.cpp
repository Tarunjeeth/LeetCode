class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> pascal;
        for (int i=1;i<(numRows+1);i++){
            vector <int> row;
            int divi_num=0;
            int ans=1;
            for (int j=i;j>0;j--){
                if (divi_num==0){
                    row.push_back(1);
                    divi_num++;
                    
                }else{
                    ans*=j;
                    ans/=divi_num;
                    row.push_back(ans);
                    divi_num++;
                }
            }
            pascal.push_back(row);
        }
        return pascal;
    }
};