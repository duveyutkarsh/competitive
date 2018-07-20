#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
const int maxn = 1e5+5;
int ans = 0 , n , a[maxn];
void solve()
{
    stack<int> s;
    s.push(a[0]);
    for(int i=1;i<n;i++)
    {
        while(!s.empty() && s.top()<a[i])
        {
            ans = max(ans , a[i]^(s.top()));
            s.pop();
        }
        s.push(a[i]);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    solve();
    reverse(a,a+n);
    solve();
    cout<<ans;
}
