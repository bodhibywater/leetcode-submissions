class Solution:
    def __init__(self):
        self.op = {'+' : 0, '-' : 1, '/' : 2, '*' : 3}

    def evalRPN(self, tokens: List[str]) -> int:
        st = []

        for tok in tokens:
            if not tok in self.op:
                st.append(int(tok))
            else:
                second = st.pop()
                first = st.pop()
                temp = self.rpn(first, second, tok)
                st.append(temp)
        return st[0]

    def rpn(self, first: int, second: int, c) -> int:
        if self.op[c] == 0:
            return (first + second)
        elif self.op[c] == 1:
            return (first - second)
        elif self.op[c] == 2:
            return int(first / second)
        else:
            return (first * second)
