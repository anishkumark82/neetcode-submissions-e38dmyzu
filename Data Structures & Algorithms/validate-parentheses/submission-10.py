class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        bdict = { ']' : '[', '}' : '{', ')' : '('}

        for ch in s :
            if ch == '(' or ch == '{' or ch == '[' :
                stack.append(ch)
            elif stack and bdict[ch] == stack[-1]:
                stack.pop()
            else:
                return False
        return True if not stack else False
