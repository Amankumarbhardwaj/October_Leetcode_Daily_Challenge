class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = nums[0];
        priority_queue<pair<int, int>>pq;
        for (int i = 0; i < n; ++i) {
            int tmp = 0;
            while (!pq.empty() && i - pq.top().second > k) {
                pq.pop();
            }
            if (!pq.empty()) {
                tmp = max(tmp, pq.top().first);
            }
            ret = max(ret, tmp + nums[i]);
            pq.emplace(tmp + nums[i], i);
        }
        return ret;
    }
};
