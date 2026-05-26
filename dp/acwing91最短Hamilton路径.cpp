// 给定一张 n 个点的带权无向图，点从 0∼n−1 标号，求起点 0 到终点 n−1 的最短 Hamilton 路径。

// Hamilton 路径的定义是从 0 到 n−1 不重不漏地经过每个点恰好一次。

// 输入格式
// 第一行输入整数 n。

// 接下来 n 行每行 n 个整数，其中第 i 行第 j 个整数表示点 i 到 j 的距离（记为 a[i,j]）。

// 对于任意的 x,y,z，数据保证 a[x,x]=0，a[x,y]=a[y,x] 并且 a[x,y]+a[y,z]≥a[x,z]。

// 输出格式
// 输出一个整数，表示最短 Hamilton 路径的长度。

// 数据范围
// 1≤n≤20
// 0≤a[i,j]≤107

// 输入样例：
// 5
// 0 2 4 5 1
// 2 0 6 5 3
// 4 6 0 8 3
// 5 5 8 0 5
// 1 3 3 5 0
// 输出样例：
// 18

// 状态压缩dp[i][j]表示状态为i，停在j的最短路径
// dp[nx][i] = min(dp[nx][i],dp[s][j]+mp[j][i])
// 状态为nx，停在i的最短路径，等于上一个状态s，停在j的最短路径+j和i之间的距离
// 遍历状态s，遍历下一个停留的点i，然后用更新为nx，假设是从j转移过来的，j是已经访问过的点

#include<iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    int mp[10][10];
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            cin>>mp[i][j];
    int dp[1<<10][10];
    for(int i = 0 ; i < 1<<n ; i ++)
        for(int j = 0 ; j <= n ; j ++)
            dp[i][j] = 1e9;
    dp[1][1] = 0;
    for(int s = 0 ; s <= (1<<n)-1 ; s ++){
        for(int i = 1 ; i <= n ; i ++){
            if(s & (1<<(i-1))) continue;
            int nx = s | (1<<(i-1));
            for(int j = 1 ; j <= n ; j ++){
                if(!(s & (1<<(j-1)))) continue;
                if(dp[s][j] == 1e9) continue;
                dp[nx][i] = min(dp[nx][i],dp[s][j]+mp[j][i]);
            }
        }
    }
    cout<<dp[(1<<n)-1][n];
    return 0;
}