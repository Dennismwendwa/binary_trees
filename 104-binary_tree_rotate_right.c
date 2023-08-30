#include "binary_trees.h"


/**
 * binary_tree_rotate_right - function that rotates binary tree right
 * @tree:- pointer to the root of the tree
 * Return:- Always 0
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *nw_root;

	if (!tree || tree->left == NULL)
		return (NULL);

	nw_root = tree->left;
	tree->left = nw_root->right;
	nw_root->right = tree;

	if (tree->left != NULL)
		tree->left->parent = tree;

	nw_root->parent = tree->parent;
	tree->parent = nw_root;

	return (nw_root);
}
