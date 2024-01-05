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

    if (parent == NULL || !binary_tree_is_root(parent))
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
 * binary_tree_is_root - Checks if a node is a root of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a root - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
    if (node == NULL || node->parent != NULL)
        return 0;
    return 1;
}
