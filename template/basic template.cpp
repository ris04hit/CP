// template
// template_basic
// basic template for cp in cpp

//
#include <bits/stdc++.h>
using namespace std;

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
long long min(long long a,int b) { if (a<b) return a; return b; }
long long min(int a,long long b) { if (a<b) return a; return b; }
long long max(long long a,int b) { if (a>b) return a; return b; }
long long max(int a,long long b) { if (a>b) return a; return b; }
long long gcd(long long a,long long b) { if (b==0) return a; return gcd(b, a%b); }
long long lcm(long long a,long long b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(long long a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/* Main()  function */
int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int tc;
    cin >> tc;

    while(tc--){
        ;
    }
    return 0;
}