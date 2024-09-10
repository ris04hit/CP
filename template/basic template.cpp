// template
// template_basic
// basic template for cp in cpp

//
#include <bits/stdc++.h>
using namespace std;

/* UTILS */
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

/* Input Output */
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

template <typename T> T input(){
    T val;
    cin >> val;
    return val;
}

template <typename T> vector<T> input(int n){
    vector<T> v;
    for (int i = 0; i<n; i++) v.push_back(input<T>());
    return v;
}

template <typename T> void output(T val){
    cout << val << "\n";
    return;
}

template <typename T> void output(vector<T> vec){
    for (T elem: vec) cout << elem << " ";
    cout << "\n";
    return;
}

/* End of Input Output */

/* Load Templates Here*/


/* End of Templates */

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

/* End of Main Function */