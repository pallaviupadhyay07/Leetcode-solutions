class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k);
        vector<long long> dp(k);

        for (int num : nums) {
            vector<long long> next(k);
            int rem = num % k;

            next[rem] = 1;

            for (int i = 0; i < k; i++) {
                int newRem = (i * rem) % k;
                next[newRem] += dp[i];
            }

            for (int i = 0; i < k; i++) {
                ans[i] += next[i];
            }

            dp = next;
        }

        return ans;
    }
};