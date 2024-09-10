// template
// template_segment_tree
// template containing segment tree related functions

#include <bits/stdc++.h>
using namespace std;

//
/* Segment Tree Template */

template <typename T> struct SegmentTreeNode{
    T val;
    int l, r;
    SegmentTreeNode *left, *right;

    SegmentTreeNode(T val, int l, int r, SegmentTreeNode *left, SegmentTreeNode *right): val(val), l(l), r(r), left(left), right(right) {}
    SegmentTreeNode(T val, int l, int r): val(val), l(l), r(r), left(nullptr), right(nullptr) {}
    SegmentTreeNode(int l, int r): l(l), r(r), left(nullptr), right(nullptr) {}
    SegmentTreeNode(T val): val(val), left(nullptr), right(nullptr) {}
    SegmentTreeNode(): left(nullptr), right(nullptr) {}

    void print(){
        cout << "val: " << val << " l: " << l << " r: " << r << endl;
    }

    void print_subtree(int depth){
        cout << "val: " << val << " l: " << l << " r: " << r << " depth: " << depth << endl;
        if(left != nullptr) left->print_subtree(depth+1);
        if(right != nullptr) right->print_subtree(depth+1);
    }

    bool is_leaf(){
        return r-l == 1;
    }
};

template <typename T> struct SegmentTree{
    SegmentTreeNode<T> *root;
    T (*combine)(T, T);
    T zero;

    SegmentTree(): root(nullptr) {}
    SegmentTree(vector<T> &arr, T (*combine)(T, T) = [](T a, T b){return a+b;}, T zero = 0): combine(combine), zero(zero){
        root = build(arr, 0, arr.size());
    }

    SegmentTreeNode<T>* build(vector<T> &arr, int l, int r){
        if(l >= r) return nullptr;
        if(r-l == 1) return new SegmentTreeNode<T>(arr[l], l, r);
        int m = l + (r-l)/2;
        SegmentTreeNode<T> *left = build(arr, l, m);
        SegmentTreeNode<T> *right = build(arr, m, r);
        return new SegmentTreeNode<T>(this->combine(left->val, right->val), l, r, left, right);
    }

    T query(int l, int r){
        return query(root, l, r);
    }

    T query(SegmentTreeNode<T> *node, int l, int r){
        if(node == nullptr || node->r <= l || node->l >= r) return zero;
        if(node->l >= l && node->r <= r) return node->val;
        return combine(query(node->left, l, r), query(node->right, l, r));
    }

    void update(int idx, T val){
        update(root, idx, val);
    }

    void update(SegmentTreeNode<T> *node, int idx, T val){
        if(node->r <= idx || node->l > idx) return;
        if(node->is_leaf()){
            node->val = val;
            return;
        }
        update(node->left, idx, val);
        update(node->right, idx, val);
        node->val = combine(node->left->val, node->right->val);
    }

    void print(){
        root->print_subtree(0);
    }
};

/* End of Segment Tree Template */
