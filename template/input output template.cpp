// template
// template_i/o
// template containing input output related functions

#include <bits/stdc++.h>
using namespace std;

//
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
