class Solution {
public:
    int firstOccurance(vector<int>& nums,int low,int lowIndex){
        int size=nums.size();
        int index=-1;
        for (int i=size-1;i>=lowIndex;i--){
            if (low<nums[i]){
                index=i;
                break;
            }
        }
        return index;
    }

    void reverseArray(vector<int>& nums,int stIndex,int endIndex){
        int left=stIndex;
        int right=endIndex;

        while (left<right){
            int temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;

            left++;
            right--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        int stIndex=-1;
        for(int i=(size-1);i>0;i--){
            if (nums[i]>nums[i-1]){         //high to low
                int index=firstOccurance(nums,nums[i-1],i);     //replace nums[i-1] - low
                printf("first occ %d i:%d low:%d ",index,i,nums[i-1]);
                int temp=nums[index];
                nums[index]=nums[i-1];
                nums[i-1]=temp;
                stIndex=i;            //for reversing array from i, stIndex denotes high
                break;
            }
        }
        for (int i=0;i<size;i++){
            printf("%d ",nums[i]);
        }
        if (stIndex==-1){
            reverseArray(nums,0,size-1);
        }else{
            reverseArray(nums,stIndex,size-1);
        }
    }
};