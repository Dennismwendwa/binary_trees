#include "binary_trees.h"


/**
 * bst_search - function that search for value in binary tree
 * @tree:- pointer to the root node
 * @value:- the value to search for
 * Return:- Always 0
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
