#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}TreeNode;

TreeNode* TreeCreate(char* a, int* pi);

int TreeSize(TreeNode* root);

int TreeLeafSize(TreeNode* root);

int TreeHeight(TreeNode* root);

int TreeLevelK(TreeNode* root, int k);

void PrevOrder(TreeNode* root);

void InOrder(TreeNode* root);

void PostOrder(TreeNode* root);

TreeNode* TreeFind(TreeNode* root, BTDataType x);

void LevelOrder(TreeNode* root);

bool TreeComplete(TreeNode* root);

void TreeDestroy(TreeNode* root);