#include "binary_trees.h"
/**
 * binary_height - height of tree on both sides
 * @tree:- pointer to the root node
 * Return: gearter + 1 of right or left height
 */
int binary_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = binary_height(tree->left);
	right = binary_height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}
/**
 * binary_tree_balance - measure the balance factors of a binary tree
 * @tree:- pointer to root node
 * Return: 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = binary_height(tree->left);
	right = binary_height(tree->right);

	return (left - right);
}
