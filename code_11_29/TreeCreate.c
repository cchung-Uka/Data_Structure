#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}TreeNode;

TreeNode* TreeCreate(char* a, int* pi)
{
    if(a[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }

    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = a[(*pi)++];

    root->left = TreeCreate(a, pi);
    root->right = TreeCreate(a, pi);

    return root;
}

void InOrder(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}

int main() 
{
    char a[101];
    gets(a);

    int i = 0;

    TreeNode* root = TreeCreate(a, &i);

    InOrder(root);

    return 0;
}