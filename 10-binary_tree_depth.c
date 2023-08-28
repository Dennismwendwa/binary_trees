#include "binary_trees.h"


/**
 * binary_tree_depth - function that measure the depth of binary tree
 * @tree:- pointer to the root of the tree
 * Return:- Always 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dp = 0;

	if (!tree)
		return (0);

	while (tree->parent != NULL)
	{
		dp++;
		tree = tree->parent;
	}

	return (dp);
}
