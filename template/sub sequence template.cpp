// template
// template_subseq
// template containing sub sequence related functions

#include <bits/stdc++.h>
using namespace std;

//
/* Subsequence Template */

// Length of longest common subsequence. Time Complexity: O(s1.size() * s2.size())
template <typename T> int longest_common_subsequence(T s1, T s2){
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    for (int i = 1; i<= s1.size(); i++){
        for (int j = 1; j<= s2.size(); j++){
            if (s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}

/*End of Subsequence Template*/