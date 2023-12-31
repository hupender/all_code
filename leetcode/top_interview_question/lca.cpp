#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int,int> parent;
        TreeNode* r=root;
        get_parent(r,parent);
        int a=p->val;
        int b=q->val;
        vector<int> v1,v2;
        v1.push_back(a);
        v2.push_back(b);
        int root_val=root->val;
        while(a!=root_val) {
            a=parent[a];
            v1.push_back(a);
        }
        while(b!=root_val) {
            b=parent[b];
            v2.push_back(b);
        }
        int n=v1.size(),m=v2.size();
        while(n-1>=0 && m-1>=0 && v1[n-1]==v2[m-1]) {
            n--;
            m--;
        }
        int res=v1[n+1];
        TreeNode* ans=get_node(root,res);
        return ans;
    }
    void get_parent(TreeNode* root,unordered_map<int,int>& parent) {
        if(root) {
            if(root->left) {
                parent[root->left->val]=root->val;
                get_parent(root->left,parent);
            }
            if(root->right) {
                parent[root->right->val]=root->val;
                get_parent(root->right,parent);
            }
        }
    }
    TreeNode* get_node(TreeNode* root,int res) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node=q.front();
            q.pop();
            if(node->val==res) {
                return node;
            }
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
        return 0;
    }
};