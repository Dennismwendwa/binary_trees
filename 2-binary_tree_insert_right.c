#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that creates new node at the right
 * @parent:- Pointer to the node to insert on the right
 * @value:- the values to store in the created node
 * Return:- Always 0
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_nod;

	if (!parent)
		return (NULL);

	new_nod = binary_tree_node(parent, value);
	if (!new_nod)
		return (NULL);

	if (parent->right != NULL)
	{
		new_nod->right = parent->right;
		parent->right->parent = new_nod;
	}

	parent->right = new_nod;

	return (new_nod);
}
