#include<bits/stdc++.h>
#define S second
#define F first
#define pb push_back
typedef long long ll;
using namespace std;
const int maxn = 1e5 + 5;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    // (a*b + c )/d - e = f
    int ans = 0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)mp[a[i]*a[j] + a[k]]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)continue;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                int rhs = (a[k] + a[j])*a[i];
                ans += mp[rhs];
            }
        }
    }
    printf("%d",ans);
    return 0;
}