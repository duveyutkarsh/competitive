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
        stack<string> a , b;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')continue;
            if(s[i]>='a' && s[i]<='z')a.push("" + string(1, s[i]));
            else if(s[i]==')')
            {
                string x = a.top();
                a.pop();
                string y = a.top();
                a.pop();
                string z = y + x + b.top();
                b.pop();
                a.push(z);
            }
            else
            {
                b.push("" + string(1,s[i]));
            }
        }
        cout<<a.top()<<"\n";
    }
    return 0;
}