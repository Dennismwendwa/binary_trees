#include "binary_trees.h"

/**
 * array_to_heap - function that builds a Max Binary Heap tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created Heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i = 0;

	if (array == NULL || size == 0)
		return (NULL);

	for (; i < size; i++)
	{
		heap_t *created = malloc(sizeof(heap_t));

		if (created == NULL)
			return (NULL);
		created->n = array[i];
		created->parent = NULL;
		created->left = NULL;
		created->right = NULL;

		if (root == NULL)
			root = created;
		else
		{
			traverse_and_insert(root, created);
			trav_and_heap(created);
		}
	}
	return (root);
}

/**
 * trav_and_heap - heapify node
 * @created: node to create
 */
void trav_and_heap(heap_t *created)
{
		while (created->parent != NULL && created->n > created->parent->n)
		{
			swap_max_heap(&(created->n), &(created->parent->n));
			created =  created->parent;
		}
}
