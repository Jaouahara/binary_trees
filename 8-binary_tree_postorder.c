#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of another in a binary tree
 * @parent: A pointer to the node to insert the left-child in
 * @value: The value to store in the new node
 *
 * Return: If parent is NULL or an error occurs - NULL
 *         Otherwise - a pointer to the new node
 *
 * Description: If parent already has a left-child, the new node
 *              takes its place and the old left-child is set as
 *              the left-child of the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_left;

    if (parent == NULL)
        return (NULL);

    new_left = malloc(sizeof(binary_tree_t));
    if (new_left == NULL)
        return (NULL);

    new_left->n = value;
    new_left->parent = parent;
    new_left->left = NULL;
    new_left->right = NULL;

    if (parent->left != NULL)
    {
        new_left->left = parent->left;
        parent->left->parent = new_left;
    }
    parent->left = new_left;

    return (new_left);
}

/**
 * custom_function - Custom function to pass into binary_tree_postorder.
 * @n: Value of the node.
 */
void custom_function(int n)
{
    // Perform custom operations with the node value
    printf("%d ", n); // For example, printing the value
}

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    binary_tree_postorder(tree->left, func);
    binary_tree_postorder(tree->right, func);
    func(tree->n);
}
