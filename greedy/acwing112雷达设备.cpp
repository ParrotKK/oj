// 假设海岸是一条无限长的直线，陆地位于海岸的一侧，海洋位于另外一侧。

// 每个小岛都位于海洋一侧的某个点上。

// 雷达装置均位于海岸线上，且雷达的监测范围为 d，当小岛与某雷达的距离不超过 d 时，该小岛可以被雷达覆盖。

// 我们使用笛卡尔坐标系，定义海岸线为 x 轴，海的一侧在 x 轴上方，陆地一侧在 x 轴下方。

// 现在给出每个小岛的具体坐标以及雷达的检测范围，请你求出能够使所有小岛都被雷达覆盖所需的最小雷达数目。

// 输入格式
// 第一行输入两个整数 n 和 d，分别代表小岛数目和雷达检测范围。
// 接下来 n 行，每行输入两个整数，分别代表小岛的 x，y 轴坐标。
// 同一行数据之间用空格隔开。

// 输出格式
// 输出一个整数，代表所需的最小雷达数目，若没有解决方案则所需数目输出 −1。

// 数据范围
// 1≤n≤1000,
// 1≤d≤200,
// −1000≤x,y≤1000

// 输入样例：
// 3 2
// 1 2
// -3 1
// 2 1
// 输出样例：
// 2

// 贪心策略：排序点，然后从右往左推雷达，使得雷达能覆盖最左边的点，然后跳过雷达覆盖范围的点，一直处理直到结束即可
// 如何排序：按照r排序，也就是这个点能确定的最靠右的雷达xr
// 记得double

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<cmath>

int d;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    int x1 = a.first,x2 = b.first,y1 = a.second,y2 = b.second;
    double r1 = x1 + sqrt(d*d - y1*y1),r2 = x2 + sqrt(d*d - y2*y2);
    return r1 < r2;
}

bool check(int xx,int yy,double xr,int d)
{
    double dis = (xx-xr)*(xx-xr) + yy*yy;
    if(dis <= d*d) return true;
    else return false;
}

int main()
{
    int n; cin>>n>>d;
    int flag = 0;
    vector<pair<int,int> > mp(n+1);
    for(int i = 0 ; i < n ; i ++){
        int x,y; cin>>x>>y;
        mp[i] = {x,y};
        if(y > d) flag = 1;
    }
    if(flag) cout<<-1;
    else{
        sort(mp.begin(),mp.end()-1,cmp);
        int cnt = 0;
        for(int i = 0 ; i < n ; ){
            // (xr,0) d^2 = (x-xr)^2 + y^2
            // xr = sqrt(d^2 - y^2) + x
            int x = mp[i].first,y = mp[i].second;
            double xr = sqrt(d*d - y*y) + x;
            cnt ++;
            int j = i+1;
            while(j < n){
                int xx = mp[j].first,yy = mp[j].second;
                if(check(xx,yy,xr,d)) j ++;
                else break;
            }
            i = j;
        }
        cout<<cnt;
    }
    return 0;
}