class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # zxyzxyz
        deq = deque()
        ans = 0
        hash = set()

        n = len(s)
        for i in range(n):
            if s[i] not in hash:
                hash.add(s[i])
                deq.append(s[i])
                ans = max(len(deq), ans)
            else :
                while deq and deq[0] != s[i]:
                    hash.remove(deq.popleft())
                    continue
                
                deq.popleft()
                deq.append(s[i])
                ans = max(len(deq), ans)

        return ans
                    