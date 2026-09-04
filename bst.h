#ifndef BST_H
#define BST_H

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct {
    TreeNode *root;
    int size;
} Tree;

void tree_init(Tree *tree);
void insert(Tree *tree, int value);
int contains(const Tree *tree, int value);
void print_inorder(const Tree *tree);
void tree_free(Tree *tree);

#endif