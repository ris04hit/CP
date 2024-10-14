// template
// template_binary_search
// template containing binary search related function

#include <bits/stdc++.h>
using namespace std;

//
/*Binary Search Template*/

struct BinarySearch{
    int binary_search(vector<int>& v, int target){
        int l = 0, r = v.size()-1;
        while (l <= r){
            int m = l + (r-l)/2;
            if (v[m] == target) return m;
            if (v[m] < target) l = m+1;
            else r = m-1;
        }
        return -1;
    }

    int binary_search(vector<int>& v, int target, int l, int r){
        while (l <= r){
            int m = l + (r-l)/2;
            if (v[m] == target) return m;
            if (v[m] < target) l = m+1;
            else r = m-1;
        }
        return -1;
    }

    int lower_bound(vector<int>& v, int target){    // Assumes lower bound exists
        int l = 0, r = v.size()-1;
        while (l < r){
            int m = l + (r-l)/2;
            if (v[m] < target) l = m+1;
            else r = m;
        }
        return l;
    }

    int upper_bound(vector<int>& v, int target){    // Assumes upper bound exists
        int l = 0, r = v.size()-1;
        while (l < r){
            int m = l + (r-l)/2;
            if (v[m] <= target) l = m+1;
            else r = m;
        }
        return l;
    }

    int lower_bound(vector<int>& v, int target, int l, int r){  // Assumes lower bound exists
        while (l < r){
            int m = l + (r-l)/2;
            if (v[m] < target) l = m+1;
            else r = m;
        }
        return l;
    }

    int upper_bound(vector<int>& v, int target, int l, int r){  // Assumes upper bound exists
        while (l < r){
            int m = l + (r-l)/2;
            if (v[m] <= target) l = m+1;
            else r = m;
        }
        return l;
    }

    int count_occurence(vector<int>& v, int target){
        return upper_bound(v, target) - lower_bound(v, target);
    }

    int count_occurence(vector<int>& v, int target, int l, int r){
        return upper_bound(v, target, l, r) - lower_bound(v, target, l, r);
    }

    int find_first_occurence(vector<int>& v, int target){
        int l = 0, r = v.size()-1;
        while (l < r){
            int m = l + (r-l)/2;
            if (v[m] < target) l = m+1;
            else r = m;
        }
        if (v[l] == target) return l;
        return -1;
    }

    int find_first_occurence(vector<int>& v, int target, int l, int r){
        while (l < r){
            int m = l + (r-l)/2;
            if (v[m] < target) l = m+1;
            else r = m;
        }
        if (v[l] == target) return l;
        return -1;
    }

    int find_last_occurence(vector<int>& v, int target){
        int l = 0, r = v.size()-1;
        while (l < r){
            int m = l + (r-l)/2;
            if (v[m] <= target) l = m+1;
            else r = m;
        }
        if (v[l] == target) return l;
        return -1;
    }

    int find_last_occurence(vector<int>& v, int target, int l, int r){
        while (l < r){
            int m = l + (r-l)/2;
            if (v[m] <= target) l = m+1;
            else r = m;
        }
        if (v[l] == target) return l;
        return -1;
    }

    int find_first_greater_than(vector<int>& v, int target){
        int l = 0, r = v.size()-1;
        while (l < r){
            int m = l + (r-l)/2;
            if (v[m] <= target) l = m+1;
            else r = m;
        }
        if (v[l] > target) return l;
        return -1;
    }

    int find_first_greater_than(vector<int>& v, int target, int l, int r){
        while (l < r){
            int m = l + (r-l)/2;
            if (v[m] <= target) l = m+1;
            else r = m;
        }
        if (v[l] > target) return l;
        return -1;
    }

    int find_last_less_than(vector<int>& v, int target){
        int l = 0, r = v.size()-1;
        while (l < r){
            int m = l + (r-l)/2;
            if (v[m] < target) l = m+1;
            else r = m;
        }
        if (v[l] >= target) return l-1;
        return -1;
    }

    int find_last_less_than(vector<int>& v, int target, int l, int r){
        while (l < r){
            int m = l + (r-l)/2;
            if (v[m] < target) l = m+1;
            else r = m;
        }
        if (v[l] >= target) return l-1;
        return -1;
    }

    int count_more_than(vector<int>& v, int target){
        int first_greater = find_first_greater_than(v, target);
        if (first_greater == -1) return 0;
        return v.size() - first_greater;
    }

    int count_more_than(vector<int>& v, int target, int l, int r){
        int first_greater = find_first_greater_than(v, target, l, r);
        if (first_greater == -1) return 0;
        return r - first_greater + 1;
    }

    int count_more_than_equal_to(vector<int>& v, int target){
        int first_less = find_last_less_than(v, target);
        if (first_less == -1) return v.size();
        return v.size() - first_less - 1;
    }

    int count_more_than_equal_to(vector<int>& v, int target, int l, int r){
        int first_less = find_last_less_than(v, target, l, r);
        if (first_less == -1) return r - l + 1;
        return r - first_less;
    }

    int count_less_than(vector<int>& v, int target){
        int first_less = find_last_less_than(v, target);
        if (first_less == -1) return 0;
        return first_less + 1;
    }

    int count_less_than(vector<int>& v, int target, int l, int r){
        int first_less = find_last_less_than(v, target, l, r);
        if (first_less == -1) return 0;
        return first_less - l + 1;
    }

    int count_less_than_equal_to(vector<int>& v, int target){
        int first_greater = find_first_greater_than(v, target);
        if (first_greater == -1) return v.size();
        return first_greater;
    }

    int count_less_than_equal_to(vector<int>& v, int target, int l, int r){
        int first_greater = find_first_greater_than(v, target, l, r);
        if (first_greater == -1) return r - l + 1;
        return first_greater - l;
    }
} binary_search;

/*End of Binary Search Template*/