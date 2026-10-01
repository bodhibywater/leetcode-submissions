class TimeMap:

    def __init__(self):
        self.store = {} # key -> [(timestamp, value), ...]

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.store:
            self.store[key].append((timestamp, value))
        else:
            self.store[key] = [(timestamp, value)]

    def get(self, key: str, timestamp: int) -> str:
        # we need ts <= timestamp, but closest to, so bsearch then take l??
        vals = self.store.get(key, [])

        l, r = 0, len(vals) - 1
        res = ""

        while l <= r:
            m = (l + r) // 2

            if vals[m][0] <= timestamp:
                res = vals[m][1]
                l = m + 1
            else:
                r = m - 1

        return res

        
