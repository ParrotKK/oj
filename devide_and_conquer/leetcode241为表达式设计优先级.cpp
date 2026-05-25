// 给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。
// 生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 104 。

// 示例 1：

// 输入：expression = "2-1-1"
// 输出：[0,2]
// 解释：
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
// 示例 2：

// 输入：expression = "2*3-4*5"
// 输出：[-34,-14,-10,-10,10]
// 解释：
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10
 
// 提示：
// 1 <= expression.length <= 20
// expression 由数字和算符 '+'、'-' 和 '*' 组成。
// 输入表达式中的所有整数值在范围 [0, 99] 
// 输入表达式中的所有整数都没有前导 '-' 或 '+' 表示符号。


// 分治思想
// 枚举每一个符号，当作是最后计算的符号，那么就是说左边算完，然后右边算完，再算这一步
// 左右两边的结果应该分别都是一个数组，然后O2复杂度计算总的结果
// 记得考虑当前区间只有数字的情况

class Solution {
public:
    int table(int x, char c, int y)
    {
        if(c == '+') return x + y;
        if(c == '-') return x - y;
        if(c == '*') return x * y;
        return 0;
    }
    bool isop(char c)
    {
        if(c == '+' || c == '-' || c == '*') return true;
        return false;
    }
    vector<int> dfs(string &s, int l, int r)
    {
        vector<int> res;
        int flag = 0;
        for(int i = l; i <= r; i++)
        {
            if(isop(s[i]))
            {
                flag = 1;
                vector<int> s1, s2;
                char c = s[i];
                s1 = dfs(s, l, i - 1);
                s2 = dfs(s, i + 1, r);
                for(int j = 0; j < s1.size(); j++)
                {
                    for(int k = 0; k < s2.size(); k++)
                    {
                        int ans = table(s1[j], c, s2[k]);
                        res.push_back(ans);
                    }
                }
            }
        }
        if(!flag)
        {
            int cur = 0;
            for(int i = l; i <= r; i++)
            {
                cur = cur * 10 + (s[i] - '0');
            }
            res.push_back(cur);
        }
        return res;
    }

    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression, 0, expression.length() - 1);
    }
};