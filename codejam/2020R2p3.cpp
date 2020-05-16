#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 100;

int t, n, par[MM], sz[MM];
ll a[MM], b[MM];

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

int main(){
    scan(t);
    for(int tt = 1; tt <= t; tt++){
        scan(n);
        for(int i = 0; i < n; i++)
            scan(a[i], b[i]);
        
        int ans = 1;
        map<pair<ll, ll>, vector<pair<int, int>>> mp;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                ll dx = a[i]-a[j], dy = b[i]-b[j];
                ll gcd = abs(__gcd(abs(dx), abs(dy)));
                dx /= gcd, dy /= gcd;
                
                if(dx < 0)
                    dx = -dx, dy = -dy;
                if(dx == 0)
                    dy = abs(dy);
                
                mp[{dx, dy}].emplace_back(i, j);
            }
        }
        for(auto &p: mp){
            for(int i = 0; i < n; i++){
                par[i] = i;
                sz[i] = 1;
            }
            for(auto i: p.second){
                int fa = find(i.first), fb = find(i.second);
                if(fa != fb){
                    par[fa] = fb;
                    sz[fb] += sz[fa];
                }
            }
            int cnt = 0, one = 0;
            for(int i = 0; i < n; i++){
                int id = find(i);
                if(sz[id] == 1)
                    one++;
                else
                    cnt += sz[id];
                sz[id] = 0;
            }
            if(cnt % 2) cnt += min(1, one);
            else cnt += min(2, one);
            ans = max(ans, cnt);
        }
        printf("Case #%d: %d\n", tt, ans);
    }
    
    return 0;
}