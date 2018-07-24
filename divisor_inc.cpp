#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
const int maxn = 2e5;
int dp[maxn];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<maxn;i++)dp[i]=1e9;
    dp[n] = 0;
    for(int i=2;i<=m;i++)
    {
        for(int j=2*i;j<=m;j=j+i)
        {
            int d = j/i;
            dp[j + d] = min(dp[j+d] , dp[j] + 1);
            dp[j + i] = min(dp[j+i] , dp[j] + 1);
        }
    }
    if(dp[m]==1e9)dp[m] = -1;
    cout<<dp[m];
}
