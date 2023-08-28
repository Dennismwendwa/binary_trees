#include "binary_trees.h"


/**
 * binary_tree_inorder - function that transverse binary tree inorder way
 * @tree:- pointer to the root of the tree
 * @func:- pointer to function that prints the nodes
 * Return:- Always 0
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);

	func(tree->n);

	binary_tree_inorder(tree->right, func);
}
