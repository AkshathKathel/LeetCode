class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        length = len(s)
        check = False
        for i in range(1,(length//2)+1):
            if length%i == 0:
                check = True
                for j in range(i):
                    x = i
                    while x<length:
                        if s[j] != s[j+x]:
                            check = False
                            break
                        x = x+i
                if check:
                    return check
        return check