#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
int complte_tree(const binary_tree_t *tree, int idx, int siz);



/**
 * binary_tree_is_complete - main function for checking if binary is complete
 * @tree:- pointer to root node
 * Return:- Always 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (complte_tree(tree, 0, binary_tree_size(tree)));
}



/**
 * complte_tree - function that check if tree is complete
 * @tree:- pointer to root of the tree
 * @idx:- index of the node we at
 * @siz:- size of the binary tree
 */

int complte_tree(const binary_tree_t *tree, int idx, int siz)
{
	if (!tree)
		return (1);

	if (idx >= siz)
		return (0);

	return (complte_tree(tree->left, 2 * idx + 1, siz) &&
			complte_tree(tree->right, 2 * idx + 2, siz));
}



/**
 * binary_tree_size - function that retur size of binary tree
 * @tree:- pointer to root of tree
 * Return:- Always 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1;

	return (size);
}
