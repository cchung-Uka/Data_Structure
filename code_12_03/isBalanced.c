int treeheight(struct TreeNode* root) 
{
	if (root == NULL)
	{
		return 0;
	}

	int left_height = treeheight(root->left);
	int right_height = treeheight(root->right);

	return 1 + (left_height > right_height ? left_height : right_height);
}

bool isBalanced(struct TreeNode* root) 
{
    if(root == NULL)
        return true;

    return abs(treeheight(root->left) - treeheight(root->right)) < 2 
        && isBalanced(root->left) && isBalanced(root->right);
}