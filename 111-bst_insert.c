#include "binary_trees.h"

bst_t *recursive_bst_insert(bst_t **tree, int value, bst_t *curr_node,
		bst_t *w_node);

/**
 * bst_insert - function that insert node in binary search tree
 * @tree:- double pointer to the tree
 * @value:- the value to insert
 * Return:- Always 0
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *nw_node;

	if (!tree)
		return (NULL);

	nw_node = binary_tree_node(NULL, value);
	if (!nw_node)
		return (NULL);

	if (!(*tree))
	{
		*tree = nw_node;
		return (nw_node);
	}

	return (recursive_bst_insert(tree, value, *tree, nw_node));
}



/**
 * recursive_bst_insert - function that inserts nodes
 * @tree:- double pointer to the tree
 * @value:- the value to insert
 * @curr_node:- pointer to the node to insert at
 * @nw_node:- Pointer to the new node
 * Return:- Always 0
 */

bst_t *recursive_bst_insert(bst_t **tree, int value, bst_t *curr_node,
		bst_t *nw_node)
{
	if (value == curr_node->n)
	{
		free(nw_node);
		return (NULL);
	}

	if (value < curr_node->n)
	{
		if (curr_node->left == NULL)
		{
			curr_node->left = nw_node;
			nw_node->parent = curr_node;
			return (nw_node);
		}
		return (recursive_bst_insert(tree, value, curr_node->left, nw_node));
	}
	else
	{
		if (curr_node->right == NULL)
		{
			curr_node->right = nw_node;
			nw_node->parent = curr_node;
			return (nw_node);
		}
		return (recursive_bst_insert(tree, value, curr_node->right, nw_node));
	}
}
