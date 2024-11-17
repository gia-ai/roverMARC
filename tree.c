//
// Created by LiamC on 08/11/2024.
//

#include "tree.h"

#include "mooves.h"
#include "tree.h"

/**
typedef struct s_node
{
    struct s_node *left ;
    T value ; // T est un type quelconque : int, float ou autre.
    struct s_node *right ;
} t_node;

typedef struct s_tree
{
    t_node *root ;
} t_tree ;

p_node createNode(int val)
{
    p_node nouv;

    nouv = (p_node)malloc(sizeof(t_node));
    nouv->value = val;
    nouv->left = nouv->right = NULL;

    return nouv;
}

typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;
 **/
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
    struct node *tourned
    struct node *demitour;
} node ;


void possibilite_case (x,y,orientation) {
    s_node arbre = creer_arbre();
}
