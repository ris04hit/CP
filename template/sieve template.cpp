// template
// template_sieve
// template containing sieve related functions

#include <bits/stdc++.h>
using namespace std;

//
/*The ith element of array contains smallest prime factor of i+1*/
vector<int> sieve(int n){
    vector<int> s (n, 1);
    for (int i = 2; i <= n; i++){
        if (s[i-1] != 1) continue;
        for (int j = i-1; j<n; j+=i){
            if (s[j] == 1) s[j] = i;
        }
    }
    return s;
}
