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
    int n  = s.size();
    char a[n+1];
    a[n] = 'z' + 1;
    for(int i=n-1;i>=0;i--)
    {
        a[i] = min(a[i+1] , s[i]);
    }
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        st.push(s[i]);
        while(!st.empty() && st.top() <= a[i+1])
        {
            cout<<st.top();
            st.pop();
        }
    }
    return 0;
}
