class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # stack / two pointers
        # go through adding elems to the stack, if elem < [-1] then add to the stack and do nothing,
        # if > [-1] pop and write to res list, acc some value and keep popping and adding to list until <
        res = [0] * len(temperatures)
        st = []

        st.append(0)

        for i in range(1, len(temperatures)):
            while st and temperatures[i] > temperatures[st[-1]]:
                temp = st.pop()
                res[temp] = i - temp
            st.append(i)

        return res

