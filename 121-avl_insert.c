#include "binary_trees.h"


/**
 * avl_insert - functuion that inserts int avl
 * @tree:- double pointer to root
 * @value:- value
 * Return:- Always 0
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *nw_node = NULL;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		nw_node = binary_tree_node(NULL, value);

		if (nw_node)
			*tree = nw_node;

		return (nw_node);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&(*tree)->left, value);

		if (!(*tree)->left)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&(*tree)->right, value);
		if (!(*tree)->right)
			return (NULL);
	}
	else
	{
		return (NULL);
	}


	return (*tree);
}
