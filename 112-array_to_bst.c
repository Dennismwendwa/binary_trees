#include "binary_trees.h"


/**
 * array_to_bst - function that builds binary tree form array
 * @array:- pointer to the array
 * @size:- size of the array
 * Return:- Always 0
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree_array = NULL;
	size_t p;

	if (!array || size == 0)
		return (NULL);

	for (p = 0; p < size; p++)
	{
		bst_insert(&tree_array, array[p]);
	}

	return (tree_array);
}
