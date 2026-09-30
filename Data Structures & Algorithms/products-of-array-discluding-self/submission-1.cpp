class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefProd(n), sufProd(n), res(n);

        prefProd[0] = 1;
        sufProd[n - 1] = 1;

        for (int i = 1; i < n; i++) {
            prefProd[i] = nums[i - 1] * prefProd[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            sufProd[i] = nums[i + 1] * sufProd[i + 1];
        }

        for (int i = 0; i < n; i++) {
            res[i] = prefProd[i] * sufProd[i];
        }
        return res;
    }
};
