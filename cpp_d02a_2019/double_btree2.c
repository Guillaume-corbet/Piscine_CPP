/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_btree2
*/

#include "double_btree.h"
#include <unistd.h>
#include <stdlib.h>
#include <float.h>
#include <stdio.h>

bool double_btree_is_empty(double_btree_t tree)
{
    if (tree == NULL)
        return (true);
    return (false);
}

unsigned int double_btree_get_size_rec(double_btree_t tree)
{
    unsigned int count = 0;

    if (tree->right != NULL) {
        count = count + 1;
        count = count + double_btree_get_size_rec(tree->right);
    }
    if (tree->left != NULL) {
        count = count + 1;
        count = count + double_btree_get_size_rec(tree->left);
    }
    return (count);
}

unsigned int double_btree_get_size(double_btree_t tree)
{
    if (tree == NULL)
        return (0);
    return (double_btree_get_size_rec(tree) + 1);
}

unsigned int double_btree_get_depth_rec(double_btree_t tree)
{
    unsigned int left = 0;
    unsigned int right = 0;

    if (tree->right != NULL) {
        right = right + 1;
        right = right + double_btree_get_depth_rec(tree->right);
    }
    if (tree->left != NULL) {
        left = left + 1;
        left = left + double_btree_get_depth_rec(tree->left);
    }
    if (right > left)
        return (right);
    else
        return (left);
}

unsigned int double_btree_get_depth(double_btree_t tree)
{
    if (tree == NULL)
        return (0);
    return (double_btree_get_depth_rec(tree) + 1);
}