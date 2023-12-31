#include "binary_trees.h"
/**
 * binary_tree_leaves - count leaves
 * @tree:- pointer to root nodes
 * Return: 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count_leav;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	count_leav = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);

	return (count_leav);
}
