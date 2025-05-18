int TreeSize(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void inorder(struct TreeNode* root, int* ret, int* returnSize)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left, ret, returnSize);
    ret[(*returnSize)++] = root->val;
    inorder(root->right, ret, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) 
{
    int* ret = (int*)malloc(sizeof(int)*TreeSize(root));

    *returnSize = 0;
    inorder(root, ret, returnSize);
    
    return ret;
}