// 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

// 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。

// 示例 1：
// 输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
// 输出：4 
// 解释：最长递增路径为 [1, 2, 6, 9]。

// 示例 2：
// 输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
// 输出：4 
// 解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。

// 示例 3：
// 输入：matrix = [[1]]
// 输出：1
 
// 提示：
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// 0 <= matrix[i][j] <= 231 - 1

// dp[i][j]表示从i，j为起点的最长递增路径，可以从四个方向转移过来
// 记得初始化为1
// 记忆化搜索

class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    vector<vector<int> > dp;
    int dfs(vector<vector<int> >& mp,int x,int y)
    {   
        if(dp[x][y]) return dp[x][y];
        int n,m;
        n = mp.size();
        m = mp[0].size();
        dp[x][y] = 1;
        for(int i = 0 ; i < 4 ; i ++){
            int nx,ny;
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(mp[nx][ny] > mp[x][y])
                dp[x][y] = max(dp[x][y], dfs(mp, nx, ny) + 1);
        }
        return dp[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n,m;
        n = matrix.size();
        m = matrix[0].size();
        dp = vector<vector<int> >(201,vector<int> (201,0));
        int ans = 0;
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                ans = max(ans,dfs(matrix,i,j));
        return ans;
    }
};