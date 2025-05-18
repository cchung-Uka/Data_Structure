int TreeSize(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void preorder(struct TreeNode* root, int* ret, int* returnSize)
{
    if(root == NULL)
    {
        return;
    }

    ret[(*returnSize)++] = root->val;
    preorder(root->left, ret, returnSize);
    preorder(root->right, ret, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) 
{
    int* ret = (int*)malloc(sizeof(int)*TreeSize(root));

    *returnSize = 0;
    preorder(root, ret, returnSize);
    
    return ret;
}