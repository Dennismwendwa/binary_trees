#include "binary_trees.h"

int check_bst(const binary_tree_t *tree, int minimum, int maximum);


/**
 * binary_tree_is_bst - function that checks if binary tree is valid
 * binary search tree
 * @tree:- pointer to the root node
 * Return:- Always 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (
			check_bst(tree, INT_MIN, INT_MAX)
			);
}



/**
 * check_bst - function that checks if binary tree is bst recursively
 * @minimum:- the minimum allowed value for node
 * @maximum:- the maximum allowed value for node
 * @tree:- pointer to the root node
 * Return:- Always 0
 */

int check_bst(const binary_tree_t *tree, int minimum, int maximum)
{
	if (!tree)
		return (1);

	if (tree->n <= minimum || tree->n >= maximum)
		return (0);

	return (check_bst(tree->left, minimum, tree->n) &&
			check_bst(tree->right, tree->n, maximum)
			);
}
