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
string s[51];

bool match(string a, string b){
    int l = min(a.size(), b.size());
    return a.substr(0, l) == b.substr(0, l);
}
string longer(string a, string b){
    if(a.size() > b.size())
        return a;
    return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t = 1; t <= T; t++){
        cin>>n;
        bool no = 0;
        string pre, suf, mid;
        for(int i = 0; i < n; i++){
            cin>>s[i];
            mid += s[i];
            string p = s[i].substr(0, s[i].find('*'));
            if(!match(p, pre))
                no = 1;
            else
                pre = longer(pre, p);
            
            reverse(all(s[i]));
            p = s[i].substr(0, s[i].find('*'));
            if(!match(p, suf))
                no = 1;
            else
                suf = longer(suf, p);
        }
        cout<<"Case #"<<t<<": ";
        if(no){
            cout<<"*\n";
            continue;
        }
        reverse(all(suf));
        for(auto &c: mid){
            if(c == '*')
                c = 'A';
        }
        cout<<pre<<mid<<suf<<'\n';
    }
    return 0;
}