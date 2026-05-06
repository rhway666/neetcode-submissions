class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
    
        mp = {}
        for i in range(len(nums)):
            if nums[i] in mp :
                if i > mp[nums[i]] :
                    return [mp[nums[i]],i]
                else : 
                    return [mp[i,nums[i]]]
            else :
                mp[target - nums[i]] = i
        
        return []

