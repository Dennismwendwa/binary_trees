#include "binary_trees.h"


/**
 * binary_tree_rotate_left - function that rotates binary tree left
 * @tree:- the root node of the tree
 * Return:- Always 0
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *nw_root;

	if (!tree || tree->right == NULL)
		return (NULL);

	nw_root = tree->right;
	tree->right = nw_root->left;
	nw_root->left = tree;

	if (tree->left != NULL)
		tree->right->parent = tree;

	nw_root->parent = tree->parent;
	tree->parent = nw_root;

	return (nw_root);
}
