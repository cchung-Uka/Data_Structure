bool _isSymmetric(struct TreeNode* p,struct TreeNode* q)
{
    if(!p && !q)
    {
        return true;
    }

    if(!p || !q)
    {
        return false;
    }

    return p->val == q->val 
        && _isSymmetric(p->left, q->right) && _isSymmetric(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) 
{
    return _isSymmetric(root->left, root->right);
}