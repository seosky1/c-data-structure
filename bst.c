#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

void print_inorder_node(const TreeNode *node);
void free_node(TreeNode *node);

int main(void) {
    Tree tree;

    tree_init(&tree);

    insert(&tree, 10);
    insert(&tree, 5);
    insert(&tree, 15);
    insert(&tree, 3);
    insert(&tree, 7);

    print_inorder(&tree);

    printf("has 7: %d\n", contains(&tree, 7));
    printf("has 99: %d\n", contains(&tree, 99));

    tree_free(&tree);
    return 0;
}

void tree_init(Tree *tree) {
    // TODO
    tree->root = NULL;
    tree->size = 0;
}

void insert(Tree *tree, int value) {
    // TODO
    TreeNode* new = malloc(sizeof(TreeNode));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    if(tree->size == 0) {
        tree->root = new;
        tree->size++;
        return;
    }
    TreeNode* cur = tree->root;
    while(cur!=NULL) {
        if(cur->data == value) {
            free(new);
            return;
        }
        else if (cur->data > value) {
            if(cur->left != NULL) {cur = cur->left;}
            else {
                cur->left = new;
                tree->size++;
                return;
            }
        }
        else {
            if(cur->right != NULL) {cur = cur->right;}
            else {
                cur->right = new;
                tree->size++;
                return;
            }
        }
    }
    tree->size++;
}

int contains(const Tree *tree, int value) {
    // TODO
    TreeNode* cur = tree->root;
    while(cur!=NULL) {
        if(cur->data == value) {return 1;}
        else if (cur->data > value) {
            if(cur->left != NULL) {cur = cur->left;}
            else return 0;
        }
        else {
            if(cur->right != NULL) {cur = cur->right;}
            else return 0;
        }
    }
    return 0;
}

void print_inorder(const Tree *tree) {
    // TODO
    print_inorder_node(tree->root);
    printf("\n");
}

void print_inorder_node(const TreeNode *node) {
    // TODO
    if(node == NULL) return;
    
    print_inorder_node(node->left);
    printf("%d ",node->data);
    print_inorder_node(node->right);
}

void tree_free(Tree *tree) {
    // TODO
    free_node(tree->root);
    tree->root = NULL;
    tree->size = 0;
}

void free_node(TreeNode *node) {
    // TODO
    if(node == NULL) return;

    free_node(node->left);
    free_node(node->right);
    free(node);
}