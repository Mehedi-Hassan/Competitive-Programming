#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define MOD             (int)998244353
#define int             long long
#define ll              long long
#define pii             pair<int, int>
#define fi              first
#define se              second
#define sf(a)           scanf("%lld", &a)
#define pf(a)           printf("%lld ", a)
#define Case(a)         printf("Case %lld: ", a)
#define FASTIO          ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb              emplace_back
#define mp              make_pair
#define mem(arr)        memset(arr, 0, sizeof(arr))
#define mem1(arr)       memset(arr, -1, sizeof(arr))
#define all(a)          a.begin(),a.end()
#define for0(i, n)      for (int i = 0; i < n; i++)
#define for1(i, n)      for (int i = 1; i <= n; i++)
#define loop(i,a,b)     for (int i = a; i < b; i++)
#define bloop(i,a,b)    for (int i = a ; i>=b;i--)
#define rr              return 0
#define prec(n)         fixed<<setprecision(n)
#define maxpq           priority_queue<int>
#define minpq           priority_queue<int, vector<int>, greater<int> >
#define inf             (int)(1e18)
#define vi              vector<int>
#define endl            "\n"
#define vii             vector<pii>
#define sz(s)           s.size()
#define bits(n)         __builtin_popcount(n)
#define MX              500005
#define svMX            200005

int gcd(int a, int b)   {return __gcd(a,b);}
void pr(int x)          {cout << x;}
void prl(int x)         {cout << x << endl;}

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
//inline bool isLeapYear(ll year) { return (year%400==0)  (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

int p[svMX+9];
vector<ll>prime;

void sieve()
{
    int sq = sqrt(svMX);

    for(int i=3;i<=sq;i+=2){
        if(p[i] == 0){
            for(int j=i*i;j<=svMX;j+=2*i){
                p[j] = 1;
            }
        }
    }

    prime.pb(2);
    for(int i=3;i<=svMX;i+=2){
        if(p[i] == 0){
            prime.pb(i);
//            cout<<i<<" ";
        }
    }
}

const long double eps = 1e-20;
const double pi = acos(-1);

int dx[5] = {+1, +0, -1, -0};
int dy[5] = {+0, +1, -0, -1};
int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool Equal(double x, double y)
{
    return fabs(x-y)<eps; ///x==y
}

bool Greater(long double x, long double y)
{
    return x-eps>y; ///x>y
}

bool Lesser(double x, double y)
{
    return x+eps<y; ///x>y
}

struct point
{
    double x, y, ang;
};
#define ftmx            1000006

int ft[ftmx];
void ftupdate(int i, int add)
{
    while(i>0 && i<ftmx){
        ft[i] += add;
        i += (i&(-i));
    }
}

int ftsum(int i)
{
    int s = 0;
    while(i>0){
        s += ft[i];
        i -= (i&(-i));
    }
    return s;
}
int ftfind(int k)
{
    int curr=0, ans =0, prevsum=0;
    for(int i= 20; i>= 0;i--){
        if(curr+(1<<i)<ftmx && ft[curr+(1<<i)]+prevsum < k){
            curr += 1<<i;
            ans = curr;
            prevsum += ft[curr];
        }
    }

    return ans+1;
}


long double Log(long double n)
{
    long double ten = 10.00000000000000000000;
    return log(n)/log(ten);
}
signed main()
{
//    FASTIO
//    int T;
//    cin>>T;
//
//    for(int tc = 1;tc<=T; tc++){

//        cout<<log(100)/log(10);
        int n;
        cin>>n;

        int a[n], ans = 1, prev = 1;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        sort(a, a+n);

        for(int i=0;i<n;i++){
//            cin>>a[i];
//            printf("%.20Lf\n", Log(ans)+Log(a[i]));
            if(Greater(Log(ans)+Log(a[i]), 18.00000000000000000000)){
                cout<<-1;
                rr;
            }
            ans *= a[i];
            if(ans == 0){
                cout<<0;
                rr;
            }
//            cout<<ans<<endl;
            if(ans>inf || ans<0 || ans/a[i] != prev){
                cout<<-1;
                rr;
            }
            prev = ans;
        }

//        printf("%.20Lf\n", Log(ans));
        cout<<ans;














//    }
}
//3
//1000000000000000 1000000000000000 0
