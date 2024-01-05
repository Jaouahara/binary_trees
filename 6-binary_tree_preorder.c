#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another in a binary tree.
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a right-child, the new node
 *              takes its place and the old right-child is set as
 *              the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *newNode;

    if (parent == NULL)
        return NULL;

    newNode = malloc(sizeof(binary_tree_t));
    if (newNode == NULL)
        return NULL;

    newNode->n = value;
    newNode->parent = parent;
    newNode->left = NULL;
    newNode->right = NULL;

    if (parent->right != NULL)
    {
        newNode->right = parent->right;
        parent->right->parent = newNode;
    }
    parent->right = newNode;

    return newNode;
}

/**
 * custom_function - Custom function to pass into binary_tree_preorder.
 * @n: Value of the node.
 */
void custom_function(int n)
{
    // Perform custom operations with the node value
    printf("%d ", n); // For example, printing the value
}

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    func(tree->n);
    binary_tree_preorder(tree->left, func);
    binary_tree_preorder(tree->right, func);
}
