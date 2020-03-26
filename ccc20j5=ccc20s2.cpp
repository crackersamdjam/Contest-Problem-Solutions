#include <bits/stdc++.h>
using namespace std;
const int MM = 1002;

int n, m, a[MM][MM];
bool vis[MM][MM], ans;

void go(int x, int y){
    if(x == n and y == m)
        ans = 1;
    if(ans)
        return;
    vis[x][y] = 1;
    for(int i = 1; i*i <= a[x][y]; i++){
        if(a[x][y]%i == 0){
            int j = a[x][y]/i;
            if(i <= n and j <= m and !vis[i][j]){
                go(i, j);
            }
            if(j <= n and i <= m and !vis[j][i]){
                go(j, i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
        }
    }
    go(1, 1);
    cout<<(ans?"yes":"no");
    
    return 0;
}
