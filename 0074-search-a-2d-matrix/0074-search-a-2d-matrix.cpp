class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0;
        int bottom=m-1;
        while(top<=bottom){
            int mid=top+(bottom-top)/2;
            if (matrix[mid][0]>target){
                bottom=mid-1;
            }else if(matrix[mid][n-1]<target){
                top=mid+1;
            }else{
                int left=0;
                int right=n-1;
                int mid1;
                while(left<=right){
                    mid1=left+(right-left)/2;
                    if (matrix[mid][mid1]==target){
                        return true;
                    }
                    if(matrix[mid][mid1]<target){
                        left=mid1+1;
                    }else if(matrix[mid][mid1]>target){
                        right=mid1-1;
                    }
                }
                return false;
            }

        }
        return false;
    }
};