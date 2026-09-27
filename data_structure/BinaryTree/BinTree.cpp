#include "BinTree.h"
//一.获取结点
 BTNode * BuyBTNode(BTDataType val)
 {
    BTNode * newNode = (BTNode*)malloc(sizeof(BTNode));
    if(NULL == newNode)
    {
        perror("malloc fail");
        return NULL;
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right  = NULL;
    return newNode;
 }
//1. 前序遍历 根结点 左子树  右子树
void Preorder(BTNode* root)
{
    if(root == NULL)
    return ;
    printf("%c ",root->val);
    Preorder(root->left);
    Preorder(root->right);
   

}
//2. 中序遍历 左子树 根结点 右子树
void Inorder(BTNode* root)
{
    if(root == NULL)
    return ;
    Inorder(root->left);
    printf("%c ",root->val);
    Inorder(root->right);
   

}
//3.后序遍历 左子树 右子树 根节点
void Postorder(BTNode* root)
{
    if(root == NULL)
    return ;
    Postorder(root->left);
    Postorder(root->right);
    printf("%c ",root->val);
   
}
//4层序遍历 借助队列实现 队列不为空 出头结点 frontNode 并将frontNode的孩子入队列
void Levelorder(BTNode* root)
{
    //这里使用简单的数组实现队列
    BTNode ** queueArr = (BTNode **)malloc(sizeof(BTNode*) * 100);
    
    if(queueArr == NULL)
    {
        printf("malloc fail");
       
        return ;
    }
    int front = 0,rear = 0;
    if(root != NULL)
  
    queueArr[rear++] = root; //根入队
    int levelsize = 1;
    while(rear - front !=0)  // rear - front 时队列中的数据个数
    {
        while(level--)
        {
            BTNode * frontNode = queueArr[front++];
            printf("%c ",frontNode->data);
            if(frontNode->left)
            queueArr[rear++] = frontNode->left;
            if(frontNode->right)
            queueArr[rear++] = frontNode->right;
        }
        printf("\n");
        level = rear - front;
    }
    printf("\n");
    free(queueArr);
}
//为了实现一层一层的出现 我们可以用levelsize计数