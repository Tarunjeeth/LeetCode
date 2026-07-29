class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1=0,count1=0,candidate2=0,count2=0;
        int n=nums.size();
        for (int i=0;i<n;i++){
            if(count1==0 && candidate2!=nums[i]){
                candidate1=nums[i];
                count1++;
            }else if(count2==0 && candidate1!=nums[i]){
                candidate2=nums[i];
                count2++;
            }else if(nums[i]==candidate1){
                count1++;
            }else if(nums[i]==candidate2){
                count2++;
            }else {
                count1--;
                count2--;
            }
        }
        vector<int> out;
        count1=0;count2=0;
        for (int i=0;i<n;i++){
            if (nums[i]==candidate1){
                count1++;
            }else if (nums[i]==candidate2){
                count2++;
            }
        }

        if (count1>n/3) out.push_back(candidate1);
        if (count2>n/3) out.push_back(candidate2);

        return out;
    }
};