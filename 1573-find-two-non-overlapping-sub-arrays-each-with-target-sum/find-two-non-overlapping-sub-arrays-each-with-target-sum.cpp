class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, 1e9);

        int left = 0, sum = 0;
        int ans = 1e9;
        int minLength = 1e9;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int length = right - left + 1;

                if (left > 0 && best[left - 1] != 1e9) {
                    ans = min(ans, length + best[left - 1]);
                }

                minLength = min(minLength, length);
            }

            best[right] = minLength;
        }

        return ans == 1e9 ? -1 : ans;
    }
};