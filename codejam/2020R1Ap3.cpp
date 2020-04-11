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

struct st{
    int val, day, x, y;
    bool operator<(const st &o) const{
        return val > o.val;
        // pq reverse
    }
};
struct pt{
    int x, y;
};
vector<pt> add;
priority_queue<st> all;
vector<vector<int>> a;
vector<set<int>> inx, iny;
int T, n, m, day;

void update(int i, int j){
    if(!inx[i].count(j))
        return;
    int sum = 0;
    auto ptr = inx[i].upper_bound(j);
    if(ptr != inx[i].end())
        sum += a[i][j]-a[i][*ptr];
    if(--ptr != inx[i].begin())
        sum += a[i][j]-a[i][*--ptr];
    
    ptr = iny[j].upper_bound(i);
    if(ptr != iny[j].end())
        sum += a[i][j]-a[*ptr][j];
    if(--ptr != iny[j].begin())
        sum += a[i][j]-a[*--ptr][j];
    
    all.push({sum, day, i, j});
}

int main(){
    scan(T);
    for(int t = 1; t <= T; t++){
        scan(n, m);
        while(all.size())
            all.pop();
        day = 0;
        a.clear();
        a.resize(n);
        inx.clear();
        inx.resize(n);
        iny.clear();
        iny.resize(m);
        for(int i = 0; i < n; i++){
            a[i].resize(m);
            for(int j = 0; j < m; j++){
                scan(a[i][j]);
                inx[i].insert(j);
                iny[j].insert(i);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                update(i, j);
            }
        }
        ll ans = 0;
        for(day = 1;; day++){
            while(all.size() and all.top().val < 0){
                auto rm = all.top(); all.pop();
                if(!inx[rm.x].count(rm.y) || rm.day != day-1)
                    continue;
                
                ans += (ll)a[rm.x][rm.y]*day;
                
                add.push_back({rm.x, rm.y});
                inx[rm.x].erase(rm.y);
                iny[rm.y].erase(rm.x);
            }
            if(add.empty())
                break;
            
            for(pt rm: add){
                auto ptr = inx[rm.x].upper_bound(rm.y);
                if(ptr != inx[rm.x].end())
                    update(rm.x, *ptr);
                if(ptr != inx[rm.x].begin())
                    update(rm.x, *--ptr);
                
                ptr = iny[rm.y].upper_bound(rm.x);
                if(ptr != iny[rm.y].end())
                    update(*ptr, rm.y);
                if(ptr != iny[rm.y].begin())
                    update(*--ptr, rm.y);
            }
            add.clear();
        }
        for(int i = 0; i < n; i++){
            for(int j: inx[i]){
                ans += (ll)a[i][j]*day;
            }
        }
        
        printf("Case #%d: %lld\n", t, ans);
    }
    
    return 0;
}
