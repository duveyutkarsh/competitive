#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
const int maxn = 1e5+5;
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        int a[n+2];
        for(int i=0;i<n;i++)cin>>a[i];
        a[n] = 0;
        stack<int> s;
        int ans = 0;
        for(int i=0;i<=n;i++)
        {
            while(!s.empty() && a[s.top()]>=a[i])
            {
                int h = s.top();
                s.pop();
                if(!s.empty())ans = max(ans , (i- s.top()-1)*a[h]);
                else ans = max(ans , i*a[h]);
            }
            s.push(i);
        }
        cout<<ans<<"\n";
    }   
}
