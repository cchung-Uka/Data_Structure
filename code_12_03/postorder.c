int TreeSize(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void postorder(struct TreeNode* root, int* ret, int* returnSize)
{
    if(root == NULL)
    {
        return;
    }

    postorder(root->left, ret, returnSize);
    postorder(root->right, ret, returnSize);
    ret[(*returnSize)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) 
{
    int* ret = (int*)malloc(sizeof(int)*TreeSize(root));

    *returnSize = 0;
    postorder(root, ret, returnSize);
    
    return ret;
}