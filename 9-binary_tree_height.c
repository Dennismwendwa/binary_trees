#include "binary_trees.h"


/**
 * binary_tree_height - function that return the height of binary tree
 * @tree:- pointer to root node of the tree
 * Return:- Always 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->right || tree->left)
	{
		height_r = binary_tree_height(tree->right);
		height_l = binary_tree_height(tree->left);


		if (height_l > height_r)
			return (height_l + 1);
		return (height_r + 1);
	}

	return (0);
}
