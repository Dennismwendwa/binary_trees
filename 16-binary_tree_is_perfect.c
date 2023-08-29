#include "binary_trees.h"

int trees_depth(const binary_tree_t *tree);
int perfect_check(const binary_tree_t *tree, int dep, int lev);

/**
 * binary_tree_is_perfect - this function check if binary tree is perfect
 * @tree:- pointer to the rood node of the binary tree
 * Return:- Always 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t dep;
	size_t lev = 0;

	if (!tree)
		return (0);

	dep = trees_depth(tree);

	return (perfect_check(tree, dep, lev));

}

/**
 * perfect_check - function that check if its perfect tree
 * @tree:- pointer to root of tree
 * @dep:- depth of the tree
 * @lev:- level of the tree
 * Return:- Always 0
 */

int perfect_check(const binary_tree_t *tree, int dep, int lev)
{
	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (dep == lev + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (perfect_check(tree->left, dep, lev + 1) &&
			perfect_check(tree->right, dep, lev + 1));
}


/**
 * trees_depth - function that measure the depth of binary tree
 * @tree:- pointer to the root of the tree
 * Return:- Always 0
 */

int trees_depth(const binary_tree_t *tree)
{
	size_t dp = 0;

	if (!tree)
		return (0);

	while (tree)
	{
		dp++;
		tree = tree->left;
	}
	return (dp);
}
