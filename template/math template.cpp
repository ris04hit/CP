// template
// template_math
// template containing mathematics related function

#include <bits/stdc++.h>
using namespace std;

//
/*Math Template*/

struct Math {
    #define MOD 1000000007
    #define PI 3.1415926535897932384626433832795
    int min(int a,int b) { if (a<b) return a; return b; }
    long long min(long long a,long long b) { if (a<b) return a; return b; }
    long long min(long long a,int b) { if (a<b) return a; return b; }
    long long min(int a,long long b) { if (a<b) return a; return b; }
    int max(int a,int b) { if (a>b) return a; return b; }
    long long max(long long a,long long b) { if (a>b) return a; return b; }
    long long max(long long a,int b) { if (a>b) return a; return b; }
    long long max(int a,long long b) { if (a>b) return a; return b; }
    long long gcd(long long a,long long b) { if (b==0) return a; return gcd(b, a%b); }
    long long lcm(long long a,long long b) { return a/gcd(a,b)*b; }

    bool is_prime(long long a) {
        if (a==1) return 0; 
        for (int i=2;i<=round(sqrt(a));++i) {
            if (a%i==0) return 0;
            return 1; 
        }
    }

    int max(vector<int> v){
        int m = numeric_limits<int>::min();
        for (int& x: v) m = max(x, m);
        return m;
    }

    long long max(vector<long long> v){
        long long m = numeric_limits<long long>::min();
        for (long long& x: v) m = max(x, m);
        return m;
    }

    int min(vector<int> v){
        int m = numeric_limits<int>::max();
        for (int& x: v) m = min(x, m);
        return m;
    }

    long long min(vector<long long> v){
        int m = numeric_limits<long long>::max();
        for (long long& x: v) m = min(x, m);
        return m;
    }
} math;

/* End of Math template */