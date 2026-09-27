#include "BinTree.h"
BTNode* CreateTree()
{
    BTNode* nodea = BuyBTNode('a');
    BTNode* nodeb = BuyBTNode('b');
    BTNode* nodec = BuyBTNode('c');
    BTNode* noded = BuyBTNode('d');
    BTNode* nodee = BuyBTNode('e');
    BTNode* nodef = BuyBTNode('f');
    nodea->left = nodeb;
    nodea->right = nodec;
    nodeb->left = noded;
    nodeb->right = nodee;
    nodec->right = nodef;
    return nodea;
}
int main() {
    BTNode* root = CreateTree();
    Preorder(root);
    printf("\n");
    Inorder(root);
    printf("\n");
    Postorder(root);
    printf("\n");
    return 0;
}