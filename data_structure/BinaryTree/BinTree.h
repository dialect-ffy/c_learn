#include <stdio.h>
#include <stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
    struct BinaryTreeNode* left;
     struct BinaryTreeNode* right;
     BTDataType val;
}BTNode;
 //1.获取结点
BTNode * BuyBTNode(BTDataType val);
 //1. 前序遍历
void Preorder(BTNode* root);
//2. 中序遍历 左子树 根结点 右子树
void Inorder(BTNode* root);
//3.后序遍历 左子树 右子树 根节点
void Postorder(BTNode* root);