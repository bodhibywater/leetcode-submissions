class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        # we are given distance to target (target - pos) and speed of each car
        # from this we can calculate time to target
        # say car i takes t time, any car after this that will take > t time

        pairs = [(p, v) for p, v in zip(position, speed)]
        pairs.sort(reverse=True)
        st = []
        for p, v in pairs:
            t = (target - p) / v
            if not st or t > st[-1]:
                st.append(t)
        
        return len(st)
