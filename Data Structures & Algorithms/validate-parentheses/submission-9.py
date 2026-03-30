class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        bMap = {'}' : '{',  ']' : '[', ')' : '(' } 

        for ele in s :
            if ele == '{' or ele == '[' or ele == '(' :
                stack.append(ele)
            elif stack and bMap[ele] == stack[-1] :
                stack.pop()
            else :
                return False
        return True if not stack else False
