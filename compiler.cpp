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
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        stack<int> st;
        int ans = 0 , op = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='<')op++;
            else
            {
                op--;
                if(op==0)ans = max(ans , i+1);
                else if(op<0)
                {
                    break;
                }
            }
        }
        cout<<ans<<"\n";
    }
}
