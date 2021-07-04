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

int T, n;

int main(){
    scan(T);
    for(int t = 1; t <= T; t++){
        printf("Case #%d:\n", t);
        scan(n);
        n--;
        print(1, 1);
        
        int sub = min(30, n);
        n -= sub;
        int r, rev = 0, sum = 0;
        for(r = 2; r <= sub+1; r++){
            if(n&(1<<(r-1))){
                sum += (1<<(r-1))-1;
                if(!rev){
                    for(int c = 1; c <= r; c++){
                        print(r, c);
                    }
                    rev = 1;
                }
                else{
                    for(int c = r; c; c--){
                        print(r, c);
                    }
                    rev = 0;
                }
            }
            else{
                if(!rev)
                    print(r, 1);
                else
                    print(r, r);
            }
        }
        r--;
        while(sum < n){
            r++;
            if(!rev)
                print(r, 1);
            else
                print(r, r);
            sum++;
        }
    }
    
    
    return 0;
}
