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
    string s;
    cin>>s;
    int n = s.size();
    int dp[n+1] , ans = 0 , cnt = 1;
    memset(dp,0,sizeof(dp));
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')st.push(i);
        else if(!st.empty())
        {
            dp[i] = i - st.top() + 1;
            if(i>0)dp[i]+= dp[st.top()-1];
            st.pop();
        }
        if(dp[i]>ans)ans = dp[i] , cnt = 1;
        else if(dp[i]==ans)cnt++;
    }
    if(ans==0)cnt=1;
    cout<<ans<<" "<<cnt;
}
