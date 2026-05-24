// 题目描述
// 有 n 个人在一个水龙头前排队接水，假如每个人接水的时间为 Ti ，请编程找出这 n 个人排队的一种顺序，使得 n 个人的平均等待时间最小。

// 一个人的等待时间不包括他的接水时间。
// 如果两个人接水的时间相同，编号更小的人应当排在前面。

// 输入格式
// 第一行为一个整数 n。

// 第二行 n 个整数，第 i 个整数 Ti​  表示第 i 个人的接水时间 Ti​ 。

// 输出格式
// 输出文件有两行，第一行为一种平均时间最短的排队顺序；第二行为这种排列方案下的平均等待时间（输出结果精确到小数点后两位）。

// 输入输出样例
// 输入
// 10 
// 56 12 1 99 1000 234 33 55 99 812

// 输出
// 3 2 7 8 1 4 9 6 10 5
// 291.90

// 说明/提示
// 1≤n≤1000，1≤ti ≤10^6 ，不保证 ti 不重复。

//贪心策略：将所有人的打水时间排序，然后依次计算前缀和，累加即为总等待时间

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cmp(pair<int,int> a,pair<int,int> b){
    return a.first < b.first;
}

int main()
{
    int n; cin>>n;
    vector<pair<int,int> > vec;
    for(int i = 0 ; i < n ; i ++){
        int x; cin>>x;
        vec.push_back({x,i+1});
    }
    sort(vec.begin(),vec.end(),cmp);
    long long ans = 0;
    for(int i = 1 ; i < n ; i ++){
        vec[i].first += vec[i-1].first;
        ans += vec[i-1].first;
        cout<<vec[i-1].second<<' ';
    }
    cout<<vec[n-1].second<<endl;
    printf("%.2f",(double)ans/n);
    return 0;
}