#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
constexpr int MM = 1000001;

int n, m;
bool vis[MM];
std::vector<int> adj[MM];

void go(int u){
    if(u == n){
        puts("yes");
        exit(0);
    }
    vis[u] = 1;
    for(const int &i: adj[u])
        if(!vis[i])
            go(i);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin>>n>>m;
    for(int i = 1,v,k; i <= n; i++){
        k = i;
        for(int j = 1; j <= m; j++, k += i){
            std::cin>>v;
            adj[k].emplace_back(v);
        }
    }
    n *= m;
    go(1);
    puts("no");
    exit(0);
}
