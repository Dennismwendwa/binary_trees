#include "binary_trees.h"
/**
 * binary_tree_is_root - function to check if a given node is a root node
 * node: pointer to node to check
 * Return: 1 if node is root and 0 if otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (1);
	else
		return(0);
}
