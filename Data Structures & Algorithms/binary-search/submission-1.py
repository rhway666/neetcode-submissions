class Solution:
    def search(self, nums: List[int], target: int) -> int:
        front = 0
        back = len(nums) - 1
        while front <= back:
            mid = (front + back) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                back = mid - 1
            else :
                front = mid + 1
        return -1