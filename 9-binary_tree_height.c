#include "binary_trees.h"


/**
 * binary_tree_height - function that return the height of binary tree
 * @tree:- pointer to root node of the tree
 * Return:- Always 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);

	return (1 + (height_l > height_r ? height_l : height_r));
}
