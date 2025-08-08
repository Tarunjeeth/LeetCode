class Solution {
public:
    int findind1(vector<int>& nums,int size){
        for (int i=size-2;i>=0;i--){
            if (nums[i]<nums[i+1]){
                return i;
            }
        }
        return -1;
    }

    int findind2(vector<int>& nums,int size,int ind1){
        for (int i=size-1;i>=0;i--){
            if (nums[i]>nums[ind1]){
                return i;
            }
        }
        return -1;
    }

    void reverse(vector<int>&nums,int start,int end){
        int rp=end;
        int lp=start;

        while(rp>lp){
            int temp=nums[lp];
            nums[lp]=nums[rp];
            nums[rp]=temp;
            rp--;
            lp++;
        }
    }

    

    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        int ind1=findind1(nums,size);
        cout<<findind1(nums,size)<<endl;
        if (ind1==-1){
            reverse(nums,0,nums.size()-1);
        }
        else{
            int ind2=findind2(nums,size,ind1);
            int temp=nums[ind1];
            nums[ind1]=nums[ind2];
            nums[ind2]=temp;
            reverse(nums,ind1+1,nums.size()-1);
        }
    }
};