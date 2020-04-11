#include <bits/stdc++.h>
using namespace std;

pair<double, double> a[100002];
int n;
double ans = 0;

void init(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("err.txt", "w", stderr);
    #endif
}

int main(){
    init();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i].first>>a[i].second;
    sort(a, a+n);
    for(int i = 1; i < n; i++){
        ans = max(ans, abs(a[i].second-a[i-1].second)/(a[i].first-a[i-1].first));
    }
    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}
