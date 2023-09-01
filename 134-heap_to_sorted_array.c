#include "binary_trees.h"
/**
 * heap_to_sorted_array - heap to array
 * @size: sizze of array
 * Return: sorted array in in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	heap_t *ptr;
	int i = 0, k, *array;

	if (heap == NULL || size == NULL)
		return (NULL);

	ptr = heap;
	while (ptr  != NULL)
	{
		i++;
		ptr = ptr->right;
	}

	array = malloc(sizeof(int) * i);
	if (array == NULL)
		return (NULL);

	for (k = i; k > 0; k--)
		array[k - 1] = heap_extract(&heap);

	*size = i;

	return (array);
}
