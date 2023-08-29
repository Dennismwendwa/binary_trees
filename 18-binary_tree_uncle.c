#include "binary_trees.h"


/**
 * my_sisters_and_brothers - function that returns sibling nodes
 * @node:- pointer to parent node
 * Return:- Always 0
 */

binary_tree_t *my_sisters_and_brothers(binary_tree_t *node)
{
	if (!node || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}

/**
 * binary_tree_uncle - function that checks for uncle node
 * @node:- pointer to starting node
 * Return:- Always 0
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
			node->parent->parent == NULL)

		return (NULL);

	return (my_sisters_and_brothers(node->parent));
}
