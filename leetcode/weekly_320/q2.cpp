#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int get_min_large(TreeNode* root,int a) {
    TreeNode* curr=root;
    int res=-1;
    while(curr) {
        if(curr->val==a) {
            return a;
        }
        else if(curr->val>a) {
            curr=curr->left;
        }
        else {
            res=curr->val;
            curr=curr->right;
        }
    }
    return res;
}
int get_max_small(TreeNode* root,int b) {
    TreeNode* curr=root;
    int res=1000001;
    while(curr) {
        if(curr->val==b) {
            return b;
        }
        else if(curr->val<b) {
            curr=curr->right;
        }
        else {
            res=min(res,curr->val);
            curr=curr->left;
        }
    }
    if(res==1000001) {
        return -1;
    }
    else {
        return res;
    }
}

vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
    vector<vector<int>> v;
    int n=queries.size();
    for(int i=0;i<n;i++) {
        vector<int> v1;
        int a=get_min_large(root,queries[i]);
        int b=get_max_small(root,queries[i]);
        v1.push_back(a);
        v1.push_back(b);
        v.push_back(v1);
    }
    return v;
}