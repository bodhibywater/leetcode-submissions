class MinStack:

    def __init__(self):
        self.pref = []
        self.st = []
        
    def push(self, val: int) -> None:
        self.st.append(val)
        val = min(val, self.pref[-1] if self.pref else val)
        self.pref.append(val)

    def pop(self) -> None:
        self.st.pop()
        self.pref.pop()

    def top(self) -> int:
        return self.st[-1]

    def getMin(self) -> int:
        return self.pref[-1]
        
