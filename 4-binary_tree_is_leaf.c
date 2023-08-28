#include "binary_trees.h"


/**
 * binary_tree_is_leaf - function that checks if a given node is leaf
 * @node:- A pointer to the node to check if its leaf
 * Return:- Always 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}
