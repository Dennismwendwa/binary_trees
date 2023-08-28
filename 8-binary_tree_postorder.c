#include "binary_trees.h"


/**
 * binary_tree_postorder - function that transverse binary tree using postorder
 * @tree:- Pointer to the root of the binary tree
 * @func:- pointer to function for printing the nodes
 * Return:- Always 0
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;


	binary_tree_postorder(tree->left, func);

	binary_tree_postorder(tree->right, func);

	func(tree->n);
}
