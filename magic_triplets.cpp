#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
const int maxn = 1<<13;
int tree[maxn+5];
int getsum(int idx)
{
    int ans = 0;
    for(;idx>0;idx -= idx&(-idx) )ans += tree[idx];
    return ans;
}
void update(int idx)
{
    for(;idx<maxn;idx += idx&(-idx) )tree[idx]++;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+1];
        memset(tree , 0 , sizeof(tree));
        ll ans = 0;
        for(int i=1;i<=n;i++)cin>>a[i];
        int left[n+1] , right[n+1];
        for(int i=1;i<=n;i++)
        {
            left[i] = getsum(a[i] - 1);
            update(a[i]);
        }
        memset(tree,0,sizeof(tree));
        for(int i=n;i>=1;i--)
        {
            right[i] = n - i - getsum(a[i]);
            update(a[i]);
        }
        for(int i=1;i<=n;i++)ans += left[i]*1ll*right[i];
        cout<<ans<<"\n";
    }
    return 0;
}