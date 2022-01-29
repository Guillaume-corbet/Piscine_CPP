/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_btree
*/

#include "double_btree.h"
#include <unistd.h>
#include <stdlib.h>
#include <float.h>
#include <stdio.h>

bool double_btree_create_node(double_btree_t *node_ptr , double value)
{
    double_btree_t new = malloc(sizeof(doublebtree_node_t));

    if (new == NULL)
        return (false);
    new->left = NULL;
    new->right = NULL;
    new->value = value;
    *node_ptr = new;
    return (true);
}

bool double_btree_delete(double_btree_t *root_ptr)
{
    double_btree_t del = *root_ptr;

    if (*root_ptr == NULL)
        return (false);
    if (del->right != NULL) {
        double_btree_delete(&del->right);
    }
    if (del->left != NULL) {
        double_btree_delete(&del->left);
    }
    free(del);
    *root_ptr = NULL;
    return (true);
}

double double_btree_get_max_value(double_btree_t tree)
{
    double max = -2147483648;
    double result = 0;

    if (tree == NULL)
        return (0);
    if (tree->value > max)
        max = tree->value;
    result = double_btree_get_max_value(tree->right);
    if (result > max && tree->right != NULL)
        max = result;
    result = double_btree_get_max_value(tree->left);
    if (result > max && tree->left != NULL)
        max = result;
    return (max);
}

double double_btree_get_min_value(double_btree_t tree)
{
    double min = 2147483647;
    double result = 0;

    if (tree == NULL)
        return (0);
    if (tree->value < min)
        min = tree->value;
    result = double_btree_get_min_value(tree->right);
    if (result < min && tree->right != NULL)
        min = result;
    result = double_btree_get_min_value(tree->left);
    if (result < min && tree->left != NULL)
        min = result;
    return (min);
}