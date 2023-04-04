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
		int left_height = 1, right_height = 1;

		if (tree->right)
			right_height += binary_tree_height(tree->right);
		if (tree->left)
			left_height += binary_tree_height(tree->left);
		if (left_height > right_height)
			return (left_height);
		else
			return (right_height);
	}
	else
		return (0);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is full - 1.
 *         Otherwise - 0.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));

	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is perfect - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t  left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height != right_height)
		return (0);

	return (binary_tree_is_full(tree));
}
