#include<iostream>
using namespace std;

// A Tree definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : val(0), left(NULL), right(NULL) {}
};

void MorrisInorderTravl(TreeNode* root) {
    TreeNode *cur = root, *pre = nullptr;
    while (cur) {
        if (!cur->left) {
            // ...traversal cur
            cur = cur->right;
            continue;
        }
        pre = cur->left;
        while (pre->right && pre->right != cur) {
            pre = pre->right;
        }
        if (!pre->right) {
            pre->right = cur;
            cur = cur->left;
        } else {
            pre->right = nullptr;
            // ...traversal cur
            cur = cur->right;
        }
    }
}

int main() 
{
    TreeNode* root = new TreeNode();
    // ...construct a tree
    MorrisInorderTravl(root);
    return 0;
}
