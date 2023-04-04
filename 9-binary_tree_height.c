#include "binary_trees.h"
/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The height of the tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left_height = 0, right_height = 0;

		if (tree->right)
			right_height = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left_height = 1 + binary_tree_height(tree->left);
		if (left_height > right_height)
			return (left_height);
		else
			return(right_height);
	}
	else
		return (0);
}
