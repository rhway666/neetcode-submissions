class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        for ch in s:
            if ch == '(' or ch == '[' or ch == '{':
                stk.append(ch)
            else :
                if not stk:
                    return False
                if ch == ')' and stk:
                    if stk[-1] != '(':
                        return False
                    else :
                        stk.pop()
                elif ch == ']' and stk:
                    if stk[-1] != '[':
                        return False
                    else :
                        stk.pop()
                else :
                    if not stk :
                        continue
                    if stk[-1] != '{':
                        return False
                    else :
                        stk.pop()
        return stk == []
                