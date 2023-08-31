#include "binary_trees.h"
/**
 * binary_tree_is_heap - function that checks if a binary tree is valid
 * @tree: is a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL, or 1
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right != NULL)
		 return (0);

	if (tree->left != NULL && tree->n < tree->left->n)
		 return (0);

	if (tree->right != NULL && tree->n < tree->right->n)
		 return (0);

	return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
}
