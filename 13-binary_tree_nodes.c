#include "binary_trees.h"
/**
 * binary_tree_nodes - fuction that counts nodes with at least one child
 * tree: pointer to root node
 * Return: 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
size_t least_1_child = 0;

if (tree == NULL)
return (0);

if (tree->left != NULL || tree->right != NULL)
least_1_child = binary_tree_nodes(tree->left) +
	binary_tree_nodes(tree->right) + 1;

return (least_1_child);
}
