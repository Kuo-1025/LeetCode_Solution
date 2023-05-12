You are given a **0-indexed** 2D integer array `questions` where `questions[i] = [pointsi, brainpoweri]`.

The array describes the questions of an exam, where you have to process the questions **in order** (i.e., starting from question `0`) and make a decision whether to **solve** or **skip** each question. Solving question `i` will **earn** you `pointsi` points but you will be **unable** to solve each of the next `brainpoweri` questions. If you skip question `i`, you get to make the decision on the next question.

- For example, given `questions = [[3, 2], [4, 3], [4, 4], [2, 5]]`:
    - If question `0` is solved, you will earn `3` points but you will be unable to solve questions `1` and `2`.
    - If instead, question `0` is skipped and question `1` is solved, you will earn `4` points but you will be unable to solve questions `2` and `3`.

Return *the **maximum** points you can earn for the exam*.

**Example 1:**

```
Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
```

**Example 2:**

```
Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.
```

**Constraints:**

- `1 <= questions.length <= $10^5$`
- `questions[i].length == 2`
- `1 <= pointsi, brainpoweri <= $10^5$`

$Solution$

To solve this problem, I use Dynamic Programming. I iterate questions from `questions.size() - 1` to `0` . Here, I define `dp[i]` means the maximum points you can earn from `i` to `questions.size() - 1` .

While iterating questions,

- I solve `questions[i]` , `dp[i] = questions[i][0] + dp[min(sz, i + questions[i][1] + 1)]`
- I skip `questions[i]` , `dp[i] = dp[i + 1]`
- `min(sz, i + questions[i][1] + 1)` is to avoid `i + questions[i][1] + 1 > sz` .

![2140_1.png](https://github.com/Kuo-1025/LeetCode_Solution/blob/master/Image/2140_1.png?raw=true)

$Code$

```cpp
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
```