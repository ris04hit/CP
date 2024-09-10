// template
// template_sieve
// template containing sieve related functions

#include <bits/stdc++.h>
using namespace std;

//
/*Sieve Template*/

/*The ith element of array contains smallest prime factor of i+1*/
struct Sieve{
    vector<int> sieve;

    Sieve(int n){
        sieve = vector<int> (n, 1);
        for (int i = 2; i <= n; i++){
            if (sieve[i-1] != 1) continue;
            for (int j = i-1; j<n; j+=i){
                if (sieve[j] == 1) sieve[j] = i;
            }
        }
    }
};

/*End of Sieve Template*/