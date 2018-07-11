#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
const int maxn = 1e5+5;
ll mod = 1e9+7;
ll p[maxn] , dp[maxn][44] , a[maxn];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int j=0;j<=42;j++)
    {
        for(int i=1;i<=n;i++)
        {
            dp[i][j] = dp[i-1][j];
            if(a[i]&(1LL<<j))dp[i][j]++;
        }
    }
    p[0] = 1;
    for(int i=1;i<maxn;i++)p[i] = (p[i-1]*2)%mod;
    int q,x;
    cin>>q>>x;
    while(q--)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        ll ans = 0;
        for(int j=0;j<=42;j++)
        {
            ll u = dp[r][j] - dp[l-1][j];
            ll v = r-l+1-u;
            ll res = (u*(u-1)*(u-2))/6;
            res = res%mod;
            res = (res + (u*(v*(v-1))/2)%mod )%mod;
            res = (res*p[j])%mod;
            ans = (ans+res)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}