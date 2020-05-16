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
using ll =  __int128;

int t;

int main(){
    scan(t);
    for(int tt = 1; tt <= t; tt++){
        ll n,a,b,l,m,r;
        scan(a, b);
        
        ll dif = a-b;
        if(dif < 0)
            dif = -dif;
        
        // drops the largest one > smaller one
        l = 0, r = dif;
        while(l <= r){
            m = (l+r)/2;
            if(m*(m+1)/2 <= dif)
                l = m+1;
            else
                r = m-1;
        }
        ll v = r;
        
        if(a >= b){
            a -= v*(v+1)/2;
            n = v+1;
        }
        else{
            b -= v*(v+1)/2;
            n = v+1;
        }
        
        // make a <= b so that a drops first
        if(b > a){
            if(b < n)
                goto out;
            b -= n;
            n++;
        }
        
        {
            // now which one drops faster
            // a drop
            l = 1, r = a;
            while(l <= r){
                m = (l+r)/2;
                if((n + n+2*(m-1))/2 *m <= a)
                    l = m+1;
                else
                    r = m-1;
            }
            ll av = r;
            
            
            // b drop
            l = 1, r = b;
            while(l <= r){
                m = (l+r)/2;
                if((n+1 + n+1+2*(m-1))/2 *m <= b)
                    l = m+1;
                else
                    r = m-1;
            }
            ll bv = r;
            
            // drop both
            if(av <= bv){
                bv = av;
                a -= (n + n+2*(av-1))/2*av;
                b -= (n+1 + n+1+2*(bv-1))/2*bv;
                n += av+bv;
            }
            else{
                av = bv+1; //one extra
                a -= (n + n+2*(av-1))/2*av;
                b -= (n+1 + n+1+2*(bv-1))/2*bv;
                n += av+bv;
            }
        }
        
        out:;
        printf("Case #%d: ", tt);
        print(n-1, a, b);
    }
    
    
    return 0;
}