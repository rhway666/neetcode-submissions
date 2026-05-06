class Solution:
    def isPalindrome(self, s: str) -> bool:
        n = len(s)
        i = 0
        j = n - 1
        # cnt_not_alpha = 0
        # for ss in s:
        #     if not ss.isalpha():
        #         cnt_not_alpha += 1
        # # 5 -> 2 ,  6 -> 3
        # half = (n - cnt_not_alpha) // 2

        while i < j:
            while i < j and not s[i].isalnum():
                i += 1
            
            while i < j and not s[j].isalnum():
                j -= 1  

            if s[i].lower() != s[j].lower():
                return False
            
            i += 1
            j -= 1
        
        return True
