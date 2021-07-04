#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef __gnu_pbds::tree<pair<int,int>, __gnu_pbds::null_type, less<pair<int,int>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> bbst;
const int MM = 1002, inf = 1e6;

int par[MM];

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

int t, n, m, a[MM], b[MM], x[MM];

int main(){
    scan(t);
    for(int tt = 1; tt <= t; tt++){
        scan(n, m);
        vector<pair<int, int>> v;
        v.emplace_back(0, 1);
        for(int i = 2; i <= n; i++){
            scan(x[i]);
            v.emplace_back(x[i], i);
        }
        bbst T;
        sort(all(v));
        for(auto i: v){
            if(i.first >= 0){
                T.insert(i);
            }
        }
        reverse(all(v));
        for(auto i: v){
            if(i.first < 0){
                auto pre = T.find_by_order(-i.first -1);
                int val = pre->first+1;
                
                T.insert({val, i.second});
                x[i.second] = val;
            }
        }
        
        for(int i = 1; i <= n; i++)
            par[i] = i;
        
        printf("Case #%d: ", tt);
        
        for(int i = 0; i < m; i++){
            scan(a[i], b[i]);
            if(x[a[i]] > x[b[i]])
                swap(a[i], b[i]);
            int fa = find(a[i]), fb = find(b[i]);
            if(x[a[i]] != x[b[i]] and fa != fb){
                par[fb] = fa;
                printf("%d ", abs(x[a[i]] - x[b[i]]));
            }
            else printf("%d ", inf);
        }
        pc(10);
    }
    
    
    return 0;
}