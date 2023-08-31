#include "binary_trees.h"
/**
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
* @first: Pointer to the first node.
* @second: Pointer to the second node.
*
* Return: If no common ancestors return NULL, else return common ancestor.
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *mull, *pull;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mull = first->parent, pull = second->parent;
	if (first == pull || !mull || (!mom->parent && pull))
		return (binary_trees_ancestor(first, pop));
	else if (mull == second || !pull || (!pull->parent && mull))
		return (binary_trees_ancestor(mull, second));
	return (binary_trees_ancestor(mull, pull));
}
