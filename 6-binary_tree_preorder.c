#include "binary_trees.h"


/**
 * binary_tree_preorder - function that goes theough binary tree using
 * pre-order traversal
 * @tree:- point to the root node of tree
 * @func:- pointer for function for printing each node
 * Return:- Always 0
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);

	binary_tree_preorder(tree->left, func);

	binary_tree_preorder(tree->right, func);
}
