#include "binary_trees.h"


/**
 * sorted_array_to_avl - function that creates avl from array
 * @array:- pointer to the array
 * @size:- size of the array
 * Return:- Always 0
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t center;
	avl_t *root;

	if (size == 0)
		return (NULL);

	center = size / 2;
	root = binary_tree_node(NULL, array[center]);

	if (!root)
		return (NULL);

	root->left = sorted_array_to_avl(array, center);
	root->right = sorted_array_to_avl(array + center + 1, size - center - 1);

	return (root);
}
