class Solution:
    def isValid(self, s: str) -> bool:
        closeToOpen = { ")" : "(", "]" : "[", "}" : "{" }
        st = []

        for c in s:
            if c in closeToOpen:
                if st and st[-1] == closeToOpen[c]:
                    st.pop()
                else:
                    return False
            else:
                st.append(c)

        return True if not st else False