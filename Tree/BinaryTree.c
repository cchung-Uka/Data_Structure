#include "Tree.h"
#include "Queue.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
TreeNode* TreeCreate(char* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	if (root == NULL)
	{
		perror("malloc failed!");
		exit(-1);
	}

	root->data = a[(*pi)++];

	root->left = TreeCreate(a, pi);
	root->right = TreeCreate(a, pi);

	return root;
}

int TreeSize(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

int TreeLeafSize(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (!root->left && !root->right)
	{
		return 1;
	}

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeHeight(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int left_height = TreeHeight(root->left);
	int right_height = TreeHeight(root->right);

	return 1 + (left_height > right_height ? left_height : right_height);
}

int TreeLevelK(TreeNode* root, int k)
{
	assert(k > 0);

	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}
	
	return TreeLevelK(root->left, k - 1) + TreeLevelK(root->right, k - 1);
}

void PrevOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

TreeNode* TreeFind(TreeNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}

	TreeNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;

	TreeNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}

void LevelOrder(TreeNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%d ", front->data);

		if (front->left)
			QueuePush(&q, front->left);

		if (front->right)
			QueuePush(&q, front->right);
	}

	QueueDestroy(&q);
}

//void LevelOrder(TreeNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	
//	if (root)
//		QueuePush(&q, root);
//
//	int LevelSize = 1;
//	while (!QueueEmpty(&q))
//	{
//		while (LevelSize--) 
//		{
//			TreeNode* front = QueueFront(&q);
//			QueuePop(&q);
//
//			printf("%d ", front->data);
//
//			if (front->left)
//				QueuePush(&q, front->left);
//
//			if (front->right)
//				QueuePush(&q, front->right);
//		}
//		printf("\n");
//
//		LevelSize = QueueSize(&q);
//	}
//
//	QueueDestroy(&q);
//}

bool TreeComplete(TreeNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
			break;

		QueuePush(&q, root->left);
		QueuePush(&q, root->right);
	}

	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueueDestroy(&q);

			return false;
		}
	}

	QueueDestroy(&q);

	return true;
}

void TreeDestroy(TreeNode* root)
{
	if (root == NULL)
		return;

	TreeDestroy(root->left);
	TreeDestroy(root->right);

	free(root);
}