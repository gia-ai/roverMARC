//
// Created by LiamC on 08/11/2024.
//

#include "tree.h"

#include "moves.h"


#include <stdio.h>
#include <stdlib.h>


t_node* create_node(int x,int y,t_orientation orientation) {
    t_node *node = (t_node*)malloc(sizeof(t_node));
    int i;
    if (!node) {
        printf("Memory allocation error\n");
        return NULL;
    }
    node->local = loc_init(x,y, orientation);
    node->nb_enfant = 0;
    for (i = 0; i < 8; i++) {
        node->enfant[i] = NULL;
    }
    node->parent = NULL;
    return node;
}

t_tree* create_tree( int x , int y, t_orientation orientation) {
    t_tree *tree = (t_tree*)malloc(sizeof(t_tree));
    if (!tree) {
        printf("Memory allocation error\n");
        return NULL;
    }
    tree->root = create_node(x, y, orientation);
    return tree;
}

void add_node_to_tree(t_node* node,int x,int y, t_orientation orientation, int mouvement) {
    t_node *new_node = create_node(x, y, orientation);
    if (!new_node) {
        printf("Memory allocation error\n");
        return;
    }
    if (mouvement > -1 && mouvement < 9) {
        node->enfant[mouvement] = new_node;
    }
    new_node->local = loc_init(x, y, orientation);
    new_node->parent = node;
}

/*
void possibilite_case (s_node* arbre ) {
    int temp=0;
    if (abre.orientation==NORTH){//orientation nord
        if (is_valid_loc(arbre.x,arbre.y-1){
            arbre->avance10=create_node(arbre.x,arbre.y-1,arbre.orientation);//avance de 10
        }
        if (is_valid_loc(arbre.x,arbre.y-2){
            arbre->avance10=create_node(arbre.x,arbre.y-2,arbre.orientation);//avance de 20
        }
        if (is_valid_loc(arbre.x,arbre.y-3){
            arbre->avance10=create_node(arbre.x,arbre.y-3,arbre.orientation);//avance de 30
        }
        if (is_valid_loc(arbre.x,arbre.y+1){
            arbre->avance10=create_node(arbre.x,arbre.y+1,arbre.orientation);//recule de 10
        }
    }
    if (abre.orientation==SOUTH){//orientation sud 
        if (is_valid_loc(arbre.x,arbre.y+1){
            arbre->avance10=create_node(arbre.x,arbre.y+1,arbre.orientation);//avance de 10
        }
        if (is_valid_loc(arbre.x,arbre.y+2){
            arbre->avance10=create_node(arbre.x,arbre.y+2,arbre.orientation);//avance de 20
        }
        if (is_valid_loc(arbre.x,arbre.y+3){
            arbre->avance10=create_node(arbre.x,arbre.y+3,arbre.orientation);//avance de 30
        }
        if (is_valid_loc(arbre.x,arbre.y-1){
            arbre->avance10=create_node(arbre.x,arbre.y-1,arbre.orientation);//recule de 10
        }
        
    }
    if (abre.orientation==EAST){//orientation est
        if (is_valid_loc(arbre.x+1,arbre.y){
            arbre->avance10=create_node(arbre.x+1,arbre.y,arbre.orientation);//avance de 10
        }
        if (is_valid_loc(arbre.x+2,arbre.y){
            arbre->avance10=create_node(arbre.x+2,arbre.y,arbre.orientation);//avance de 20
        }
        if (is_valid_loc(arbre.x+3,arbre.y){
            arbre->avance10=create_node(arbre.x+3,arbre.y,arbre.orientation);//avance de 30
        }
        if (is_valid_loc(arbre.x-1,arbre.y){
            arbre->avance10=create_node(arbre.x-1,arbre.y,arbre.orientation);//recule de 10
        }
        
    }

    if (abre.orientation==WEST){//orientation ouest
        if (is_valid_loc(arbre.x-1,arbre.y){
            arbre->avance10=create_node(arbre.x-1,arbre.y,arbre.orientation);//avance de 10
        }
        if (is_valid_loc(arbre.x-2,arbre.y){
            arbre->avance10=create_node(arbre.x-2,arbre.y,arbre.orientation);//avance de 20
        }
        if (is_valid_loc(arbre.x-3,arbre.y){
            arbre->avance10=create_node(arbre.x-3,arbre.y,arbre.orientation);//avance de 30
        }
        if (is_valid_loc(arbre.x+1,arbre.y){
            arbre->avance10=create_node(arbre.x+1,arbre.y,arbre.orientation);//recule de 10
        }
        
    }
    arbre->avance10=create_node(arbre.x,arbre.y,arbre.orientation-1%4);//tourne à gauche
    arbre->avance10=create_node(arbre.x,arbre.y,arbre.orientation+1%4);//tourne à droite
    arbre->avance10=create_node(arbre.x,arbre.y,arbre.orientation+2%4);//demi-tour

    //probleme avec les orientations 

}
*/