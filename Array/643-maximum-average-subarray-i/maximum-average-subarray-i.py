class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        l, r = 0, k-1
        add = sum(nums[l:r+1])
        maxAdd = add
        while r < len(nums)-1:
            add -= nums[l]
            l += 1
            r += 1
            add += nums[r]
            maxAdd = max(maxAdd, add)
        return maxAdd/k