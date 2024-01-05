#include "binary_trees.h"

/**
 * max - Finds the maximum between two numbers.
 * @a: First number.
 * @b: Second number.
 *
 * Return: The maximum between a and b.
 */
size_t max(size_t a, size_t b)
{
    return (a > b ? a : b);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    return (1 + max(left_height, right_height));
}
