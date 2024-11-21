//
// Created by LiamC on 08/11/2024.
//

#ifndef TREE_H
#define TREE_H
#include "loc.h"
typedef struct node
{
    t_localisation local;
    struct node *parent;
    int nb_enfant;
    struct node *enfant[];
} t_node, s_node, p_node;


typedef struct s_tree
{
    t_node *root ;
} t_tree, *p_tree;


t_node* create_node(int, int, t_orientation);
t_tree* create_tree(int, int, t_orientation);
void add_node_to_tree(t_node*,int,int, t_orientation, int);


#endif //TREE_H
