class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3]={0};

        for (int i=0;i<nums.size();i++){
            arr[nums[i]]+=1;
        }

        int index=0;

        for (int i=0;i<nums.size();i++){
            while (arr[index]==0){
                index++;
            }
            nums[i]=index;
            arr[index]--;
        }
    }
};