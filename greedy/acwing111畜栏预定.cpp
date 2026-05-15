// 有 N 头牛在畜栏中吃草。

// 每个畜栏在同一时间段只能提供给一头牛吃草，所以可能会需要多个畜栏。

// 给定 N 头牛和每头牛开始吃草的时间 A 以及结束吃草的时间 B，每头牛在 [A,B] 这一时间段内都会一直吃草。

// 当两头牛的吃草区间存在交集时（包括端点），这两头牛不能被安排在同一个畜栏吃草。

// 求需要的最小畜栏数目和每头牛对应的畜栏方案。

// 输入格式
// 第 1 行：输入一个整数 N。

// 第 2..N+1 行：第 i+1 行输入第 i 头牛的开始吃草时间 A 以及结束吃草时间 B，数之间用空格隔开。

// 输出格式
// 第 1 行：输出一个整数，代表所需最小畜栏数。

// 第 2..N+1 行：第 i+1 行输出第 i 头牛被安排到的畜栏编号，编号是从 1 开始的 连续 整数，只要方案合法即可。

// 数据范围
// 1≤N≤50000,
// 1≤A,B≤1000000

// 输入样例：
// 5
// 1 10
// 2 4
// 3 6
// 5 8
// 4 7
// 输出样例：
// 4
// 1
// 2
// 3
// 2
// 4


//按开始时间排序，每次优先复用“结束时间最早且已经结束”的畜栏；如果最早结束的都没结束，那其他畜栏更不可能结束，只能新开

#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<algorithm>

int cmp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b)
{
    return a.second.first < b.second.first;
}

int main()
{
    int n; cin>>n;
    vector<pair<int,pair<int,int> > > cow(n+1);
    for(int i = 0 ; i < n ; i ++){
        int x,y; cin>>x>>y;
        cow[i].first = i;
        cow[i].second.first = x;
        cow[i].second.second = y;
    }
    sort(cow.begin(),cow.end()-1,cmp);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector<int> ans(n+1);
    int cnt = 0;
    for(int i = 0 ; i < n ; i ++){
        int bg = cow[i].second.first;
        int ed = cow[i].second.second;
        int id = cow[i].first;
        if(cnt == 0){
            cnt ++;
            pq.push({ed,cnt});
            ans[id] = cnt;
        }
        else{
            int earliest = pq.top().first;
            int f_id = pq.top().second;
            if(earliest >= bg){
                cnt ++;
                ans[id] = cnt;
                pq.push({ed,cnt});
            }
            else{
                pq.pop();
                ans[id] = f_id;
                pq.push({ed,f_id});
            }
        }
    }
    cout<<cnt<<endl;
    for(int i = 0 ; i < n ; i ++) cout<<ans[i]<<endl;
    return 0;
}