class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Return a vector of ints (output), where ouput[i] equals product of all ints in nums
        // except nums[i]
        // Initial thoughts, create hashmap where key is index and value is 
        // product of all nums / nums[i]
        int prod = 1;
        int zeroCount = 0;

        for (int num : nums) {
            if (num != 0) {
                prod *= num;
            } else {
                zeroCount++;
            }
        }

        if (zeroCount > 1) {
            return vector<int> (nums.size(), 0);
        }
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount > 0) {
                res[i] = (nums[i] == 0) ? prod : 0;
            } else {
                res[i] = prod / nums[i];
            }
        }
        return res;
    }
};
