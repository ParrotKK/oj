// 输入一个 非空 整型数组，数组里的数可能为正，也可能为负。

// 数组中一个或连续的多个整数组成一个子数组。

// 求所有子数组的和的最大值。

// 要求时间复杂度为 O(n)

// 数据范围
// 数组长度 [1,1000]

// 数组内元素取值范围 [−200,200]

// 样例
// 输入：[1, -2, 3, 10, -4, 7, 2, -5]

// 输出：18

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        //dp[i] 表示以i结尾的子数组最大和
        //dp[i] = max(dp[i-1]+nums[i],nums[i])
        vector<int> dp(len+1);
        dp[1] = nums[0];
        int ans = dp[1];
        for(int i = 2 ; i < len+1 ; i ++){
            dp[i] = max(dp[i-1]+nums[i-1],nums[i-1]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};