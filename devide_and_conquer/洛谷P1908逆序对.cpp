// P1908 逆序对

// 题目描述
// 猫猫 TOM 和小老鼠 JERRY 最近又较量上了，但是毕竟都是成年人，他们已经不喜欢再玩那种你追我赶的游戏，现在他们喜欢玩统计。
// 最近，TOM 老猫查阅到一个人类称之为“逆序对”的东西，这东西是这样定义的：对于给定的一段正整数序列，逆序对就是序列中 a_i>a_j 且 i<j 的有序对。知道这概念后，他们就比赛谁先算出给定的一段正整数序列中逆序对的数目。注意序列中可能有重复数字。

// 输入格式
// 第一行，一个数 n，表示序列中有 n 个数。
// 第二行 n 个数，表示给定的序列。序列中每个数字不超过 10^9。

// 输出格式
// 输出序列中逆序对的数目。

// 输入输出样例
// 输入
// 6
// 5 4 2 6 3 1

// 输出
//11

// 说明/提示
// 对于 25% 的数据，n <= 2500。
// 对于 50% 的数据，n <= 4 * 10^4。
// 对于所有数据，1 <= n <= 5 * 10^5。

// 1、记得long long
// 2、归并排序
// 3、在归并排序合并的时候计算答案累加值，如果左边一个数大于右边一个数，那么左边剩下的数一定比右边的这个数还大，因此答案直接累加mid - s1 + 1
// 相当于每次考虑局部小区间，比如，第1个数会考虑到后面的所有区间的情况的，第一次考虑第二个数，第二次考虑1234个数，然后是1-8个数，最后全部考虑完，因此不重不漏

#include<iostream>
#include<vector>
using namespace std;

long long merge(vector<int> &t,vector<int> &s,int l,int r,int m)
{
    long long ans = 0;
    int s1 = l,s2 = m+1,cur = 0;
    while(s1 <= m && s2 <= r){
        if(t[s1] <= t[s2]) s[cur++] = t[s1++];
        else{
            ans += m - s1 + 1;
            s[cur++] = t[s2++]; 
        }
    }
    while(s1 <= m) s[cur++] = t[s1++];
    while(s2 <= r) s[cur++] = t[s2++];
    for(int i = 0,j = l ; i < r-l+1 ; i ++) t[j++] = s[i];
    return ans;
}

void mergesort(vector<int> &t,vector<int> &s,int l,int r,long long &ans)
{
    if(l >= r) return; 
    if(r == l+1){
        if(t[r] >= t[l]) return ;
        int tmp = t[r];
        t[r] = t[l];
        t[l] = tmp;
        ans ++;
    }
    else{
        int mid = (l+r) >> 1;
        mergesort(t,s,l,mid,ans);
        mergesort(t,s,mid+1,r,ans);
        ans += merge(t,s,l,r,mid);
    }
}

int main()
{
    int n; cin>>n;
    vector<int> vec(n+1);
    vector<int> tmp(n+1);
    for(int i = 1 ; i <= n ; i ++) cin>>vec[i];
    long long ans = 0;
    mergesort(vec,tmp,1,n,ans);
    cout<<ans;
    return 0;
}