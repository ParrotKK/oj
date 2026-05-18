// 在一条数轴上有 N 家商店，它们的坐标分别为 A1∼AN。

// 现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。

// 为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。

// 输入格式
// 第一行输入整数 N。

// 第二行 N 个整数 A1∼AN。

// 输出格式
// 输出一个整数，表示距离之和的最小值。

// 数据范围
// 1≤N≤100000,
// 0≤Ai≤40000

// 输入样例：
// 4
// 6 2 9 1
// 输出样例：
// 12

// 选中位数就对了，先排序

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main()
{
    int n; cin>>n;
    vector<int> vec(n+1);
    for(int i = 1 ; i <= n ; i ++) cin>>vec[i];
    sort(vec.begin()+1,vec.end());
    int mid = (n+1)/2;
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++) ans += (vec[i]-vec[mid]) * (vec[i]-vec[mid] > 0 ? 1 : -1);
    cout<<ans;
    return 0;
}