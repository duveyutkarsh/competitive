#include<bits/stdc++.h>
#define S second
#define F first
#define pb push_back
typedef long long ll;
using namespace std;
const int maxn = 30005;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    std::vector<int> x , y;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)x.pb(a[i]*a[j] + a[k]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)continue;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)y.pb(a[i]*(a[j] + a[k]));
        }
    }
    int ans = 0;
    sort(x.begin() , x.end());
    sort(y.begin() , y.end());
    for(auto e : x)
    {
        ans += upper_bound(y.begin() , y.end() , e) - lower_bound(y.begin() , y.end() , e);
    }
    printf("%d",ans);
    return 0;
} 