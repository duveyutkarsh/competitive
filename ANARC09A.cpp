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
    int cs = 0;
    while(cin>>s)
    {
        if(s[0]=='-')break;
        int n = s.size();
        stack<int> st;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='{')st.push(i);
            else
            {
                if(st.empty())cnt++;
                else st.pop();
            }
        }
        cs++;
        cout<<cs<<". ";
        int k = st.size();
        cout<<cnt/2 + cnt%2 + k/2 + k%2<<"\n";
    }
    return 0;
}
