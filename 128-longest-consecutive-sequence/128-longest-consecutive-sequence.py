class Solution(object):
    def longestConsecutive(self, nums):
        numbers=set()
        
        for i in nums:
            numbers.add(i)
        
        res=0
        for i in nums:
            if i-1 not in numbers:
                curr=1
                while(i+curr in numbers):
                    curr=curr+1
                if res<curr:
                    res=curr
        return res