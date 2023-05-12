/*
 * @Author Jun-an
 * @Date 2023/5/12
 * @Url https://leetcode.com/problems/solving-questions-with-brainpower/description/
 */

class Solution {
public:
    long long dp[100005];
    long long mostPoints(vector<vector<int>>& q) {
        int sz = q.size();

        for (int i = sz - 1; i >= 0; --i) {
            int p = q[i][0], bp = q[i][1];
            dp[i] = max(p + dp[min(sz, i + bp + 1)], dp[i + 1]);
        }

        return dp[0];
    }
};