//
// Created by LiamC on 08/11/2024.
//

#ifndef TREE_H
#define TREE_H

typedef struct node
{
    int x;
    int y;
    int orientation;
    struct node *avance10;
    struct node *avance20;
    struct node *avance30;
    struct node *recule10;
    struct node *tourneg;
    struct node *tourned;
    struct node *demitour;
} t_node, s_node, p_node* ;


typedef struct s_tree
{
    t_node *root ;
} t_tree, *p_tree;


t_node* Creat_node(int x,int y,int orientation);


#endif //TREE_H
