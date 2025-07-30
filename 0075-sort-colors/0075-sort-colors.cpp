class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3]={0};
        int count=nums[0];
        for (int i=0;i<nums.size();i++){
            arr[nums[i]]++;
            if (nums[i]<count){
                count=nums[i];
            }
        }

        for (int i=0;i<nums.size();i++){
            while (arr[count]==0){
                count++;
            }
            nums[i]=count;
            arr[count]--;
        }
    }
};