// 给定一个数字，我们按照如下规则把它翻译为字符串：

// 0 翻译成 a，1 翻译成 b，……，11 翻译成 l，……，25 翻译成 z。

// 一个数字可能有多个翻译。

// 例如 12258
//  有 5 种不同的翻译，它们分别是 bccfi、bwfi、bczi、mcfi 和 mzi。

// 请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。

// 数据范围
// 输入数字位数 [1,101]

// 样例
// 输入："12258"

// 输出：5

//dp[i] 表示以i结尾的字符串个数，只需要考虑s[i]和s[i-1:i]是否合法，合法就加上后者，否则不加

class Solution {
public:
    int getTranslationCount(string s) {
        int len = s.length();
        vector<int> dp(len+1,0);
        dp[0] = 1;
        for(int i = 1 ; i < len ; i ++){
            int c = s[i] - '0';
            int pc = s[i-1] - '0';
            int tg = c + pc * 10;
            dp[i] = dp[i-1];
            if(tg <= 25 && i-2 >= 0 && pc != 0) dp[i] += dp[i-2];
            else if(tg <= 25 && i == 1 && pc != 0) dp[i] += 1;
        }
        return dp[len-1];
    }
};