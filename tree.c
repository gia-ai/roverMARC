//
// Created by LiamC on 08/11/2024.
//

#include "tree.h"

#include "moves.h"
#include "tree.h"


#include <stdio.h>
#include <stdlib.h>

#include "loc.h"

t_node* Creat_node(int x,int y,int orientation) {
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
    if (abre.orientation==NORTH){
        if
            arbre->avance10=creer_noeud(arbre.x
        }
    if (abre.orientation==SOUTH){}

#include "moves.h"
    if (abre.orientation==EAST){}

    if (abre.orientation==WEST){}

}
