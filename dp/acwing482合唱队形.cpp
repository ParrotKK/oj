// N 位同学站成一排，音乐老师要请其中的 (N−K) 位同学出列，使得剩下的 K 位同学排成合唱队形。     

// 合唱队形是指这样的一种队形：设 K 位同学从左到右依次编号为 1，2…，K，他们的身高分别为 T1，T2，…，TK，  则他们的身高满足 T1<…<Ti>Ti+1>…>TK(1≤i≤K)。     

// 你的任务是，已知所有 N 位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

// 输入格式
// 输入的第一行是一个整数 N，表示同学的总数。

// 第二行有 N 个整数，用空格分隔，第 i 个整数 Ti 是第 i 位同学的身高(厘米)。

// 输出格式
// 输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。

// 数据范围
// 2≤N≤100,
// 130≤Ti≤230

// 输入样例：
// 8
// 186 186 150 200 160 130 197 220
// 输出样例：
// 4


#include<iostream>
using namespace std;

// 不能用这个nlogn的dp+贪心的方法，因为需要知道每一位的最长上升和倒序上升子序列长度
// solve的方法是贪心，如果一个更小的数也可以使得最长子序列的长度不减，那么选择一个更小的数是更有优势的

int solve(int n,int *arr,int *tail)
{
    tail[1] = arr[1];
    int cnt = 1;
    for(int i = 2 ; i <= n ; i ++){
        if(arr[i] > tail[cnt]) tail[++cnt] = arr[i];
        else{
            int l = 1,r = cnt;
            while(l < r){
                int mid = (l+r) >> 1;
                if(tail[mid] < arr[i]) l = mid+1;
                else r = mid;
            }
            tail[r] = arr[i];
        }
    }
    return cnt;
}

void solve2(int n,int *arr,int *dp)
{
    for(int i = 1 ; i <= n ; i ++){
        dp[i] = 1;
        for(int j = 1 ; j < i ; j ++)
            if(arr[i] > arr[j]) dp[i] = max(dp[i],dp[j]+1);
    }
}

// 注意这个是倒序上升，不是正序下降子序列，必须从后往前更新
void solve3(int n,int *arr,int *dp)
{
    for(int i = n ; i >= 1 ; i --){
        dp[i] = 1;
        for(int j = n ; j >= i+1 ; j --)
            if(arr[i] > arr[j]) dp[i] = max(dp[i],dp[j]+1);
    }
}

int main()
{
    int n; cin>>n;
    int hi[240];
    for(int i = 1 ; i <= n ; i ++) cin>>hi[i];
    int up[240];
    int dn[240];
    solve2(n,hi,up);
    solve3(n,hi,dn);
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++)
        ans = max(ans,up[i]+dn[i]-1);
    cout<<n-ans;
    return 0;
}