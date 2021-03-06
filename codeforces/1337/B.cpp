#include<bits/stdc++.h>
#define ll      long long
#define pii     pair<int, int>
#define f       first
#define s       second
#define sf(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define pf(a) printf("%d ", a)
#define pfl(a) printf("%lld\n", a)
#define Case(a) printf("Case %d: ", a)
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const double eps = 1e-9;
const double pi = acos(-1);

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
    return x+eps<y; ///x>y
}

struct point
{
    double x, y, ang;
};





using namespace std;
int main()
{
    FASTIO;
    int t;
    cin>>t;

    for(int tc = 1;tc<=t; tc++){
        ll x, n, m;
        cin>>x>>n>>m;

        while(n && x>20){
            n--;
            x = x/2;
            x += 10;
        }

        while(m--){
            x -= 10;
        }
        if(x <= 0){
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
}


