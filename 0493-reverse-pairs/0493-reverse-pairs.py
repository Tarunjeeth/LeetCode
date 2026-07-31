class Solution:
    def mergeSort(self,nums: List[int],low :int, high :int):
        if (low>=high):
            return 0
        mid=low+(high-low)//2
        count=0
        count+=self.mergeSort(nums,low,mid)
        count+=self.mergeSort(nums,mid+1,high)
        count+=self.count(nums,low,mid,high)
        self.merge(nums,low,mid,high)

        return count
    
    def count(self,nums: List[int],low :int,mid :int,high:int):
        left=low
        right=mid+1
        count=0

        while(left<=mid and right<=high):
            if (nums[left]>2*nums[right]):
                count+=((mid+1)-left)
                right+=1
            else:
                left+=1
        return count
    
    def merge(self,nums: List[int],low :int,mid :int,high:int):
        temp=[]
        left=low
        right=mid+1
        while(left<=mid and right<=high):
            if(nums[left]<=nums[right]):
                temp.append(nums[left])
                left=left+1
            else:
                temp.append(nums[right])
                right=right+1
        while(left<=mid):
            temp.append(nums[left])
            left+=1
        while(right<=high):
            temp.append(nums[right])
            right+=1
        
        for i in range (low,high+1):
            nums[i]=temp[i-low]

    def reversePairs(self, nums: List[int]) -> int:
        count=self.mergeSort(nums,0,len(nums)-1)
        print(nums)
        print(count)
        return count

        