//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define PI              acos(-1.0)
#define No              cout<<"No\n"
#define Yes             cout<<"Yes\n"
#define no              cout<<"no\n"
#define yes             cout<<"yes\n"
#define NO              cout<<"NO\n"
#define YES             cout<<"YES\n"
#define MOD             (int)1000000007
#define int             long long
#define ll              long long
#define pii             pair<int, int>
#define fi               first
#define se              second
#define sf(a)           scanf("%lld", &a)
#define pf(a)           printf("%lld ", a)
#define case(a)         cout<<"Case "<<a<<": ";
#define FASTIO          ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb              emplace_back
#define mp              make_pair
#define mem(arr)        memset(arr, 0, sizeof(arr))
#define mem1(arr)       memset(arr, -1, sizeof(arr))
#define all(a)          a.begin(),a.end()
#define f(i,a,b)        for (int i = a; i<=b; i++)
#define fr(i,a,b)       for (int i = a; i>=b; i--)
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
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define MX              500005


int gcd(int a, int b)   {return __gcd(a,b);}

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n or (1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }


const double eps = 1e-9;

int dx[5] = {+1, +0, -1, -0};
int dy[5] = {+0, +1, -0, -1};
int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool Equal(double x, double y)
{
    return fabs(x-y)<eps; ///x==y
}

bool Greater(double x, double y)
{
    return x-eps>y; ///x>y
}

bool Lesser(double x, double y)
{
    return x+eps<y; ///x<y
}

struct point
{
    double x, y, ang;
};

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

///Write what you need -->
/// nt, ft, kmp, tri, sufarr, ub_lb, lis
/// dsu


///Template Ends Here////////////////////////////
const int N = 200005;
ll n, s, m, w[N], vis[N], dis[N], deg[N], e[N];
vi g[N], lf;

void dfs2(int s)
{
    for(int x:g[s]){
        if(!vis[x]){
            vis[x] = 1;
            dis[x] = dis[s] + w[x];
//            error(x, dis[x], dis[s], w[x]);
            dfs2(x);
        }
    }
}

int dfs(int v)
{
    int ret = 0;
    for(int x:g[v]){
        if(!vis[x] && x!=s && sz(g[x])<=2){
            vis[x] = 1;
            ret += w[x] + dfs(x);
        }
    }
    return ret;
}

signed main()
{
//    root = new trinode();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    FASTIO

    cin>>n>>m;

    int x, y, ans = 0;
    f(i, 1, n){
        cin>>w[i];
//        error(i, w[i]);
    }
//    print();

    f(i, 1, m){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    cin>>s;

    if(m == n-1){
        dis[s] = w[s];
        vis[s] = 1;


        dfs2(s);
        int mx = 0, s = 0;
        f(i, 1, n){
//            error(dis[i]);
            if(dis[i]>mx){
                mx = dis[i];
                s = i;
            }
        }
        cout<<mx;
        rr;
    }

    int mx = 0;

    queue<int>q;
    f(i, 1, n){
        if(sz(g[i])==1 && i!=s){
            q.push(i);
        }
        deg[i] = sz(g[i]);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 1;

        for(int v:g[u]){
            deg[v]--;
            e[v] = max(e[v], e[u] + w[u]);
            if(deg[v]==1 && v!=s){
                q.push(v);
            }
        }
    }

    f(v, 1, n){
        mx = max(mx, e[v]);
    }

    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 1;
        ans += w[u];
//        error(u);

        for(int v:g[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }




    cout<<ans+mx;































//    tridel(root);
}





