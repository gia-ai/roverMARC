//
// Created by LiamC on 08/11/2024.
//

#include "tree.h"

#include "moves.h"
#include "tree.h"


#include <stdio.h>
#include <stdlib.h>

#include "loc.h"

t_node* create_node(int x,int y,int orientation) {
    t_node* node = (t_node*)malloc(sizeof(t_node));
    if (!node) {
        printf("Memory allocation error\n");
        return NULL;
    }
    node->x = 0;
    node->y = 0;
    node->orientation = SOUTH;
    node->avance10 = NULL;
    node->avance20 = NULL;
    node->avance30 = NULL;
    node->demitour = NULL;
    node->recule10 = NULL;
    node->tourned = NULL;
    node->tourneg = NULL;
    return node;
}



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
