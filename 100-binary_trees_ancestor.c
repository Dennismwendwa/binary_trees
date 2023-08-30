#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, this function will return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *second_ancestor[1024];
	binary_tree_t *first_ancestor[1024], *common = NULL;
	int i = 0, j = 0;
	const binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	ancestor = first;
	while (ancestor != NULL)
	{
		first_ancestor[i++] = (binary_tree_t *)ancestor;
		ancestor = ancestor->parent;
	}

	ancestor = second;
	while (ancestor != NULL)
	{
		second_ancestor[j++] = (binary_tree_t *)ancestor;
		ancestor = ancestor->parent;
	}

	if (first == NULL || second == NULL)
		return (NULL);

	i--;
	j--;

	while (i >= 0 && j >= 0 && first_ancestor[i] == second_ancestor[j])
	{
		common = first_ancestor[i];
		i--;
		j--;
	}

	return (common);
}
