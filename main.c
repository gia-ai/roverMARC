#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "tree.h"
#include "moves.h"
#include "loc.h"
#include "stack.h"


int main() {
    t_map map = createMapFromFile("..\\maps\\example1.map");
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    displayMap(map);

    t_position base = getBaseStationPosition(map);
    if (isValidLocalisation(base, map.x_max, map.y_max) == 1) {
        printf("Base station position is at (%d, %d)\n", base.x, base.y);
    }
    int val = 0;
    t_orientation ori = SOUTH;


    //Initalisation de l'arbre et du premier noeud
    t_node* node = create_node(0,0,SOUTH);

    printf("Marc position is at (%d,%d)\n", node->local.pos.x, node->local.pos.y);
    val = isValidLocalisation(node->local.pos, map.x_max, map.y_max);
    printf("%d\n", val);

    dfs(node, base, map);
/*
    while (node->local.pos.x != base.x || node->local.pos.y != base.y) {
        // Code pour continuer la recherche
        t_move movement [7] = {F_10,F_20,F_30,B_10,T_LEFT,T_RIGHT,U_TURN};
        for (int i = 0; i < 7; i++) {
        t_node* new_node = create_node(node->local.pos.x, node->local.pos.y, node->local.ori);
            node->enfant[i] = new_node;

        node->enfant[i]->local = move(node->enfant[i]->local,movement[i]);
            printf("Marc position is at (%d,%d)\n", node->enfant[i]->local.pos.x, node->enfant[i]->local.pos.y);
        }

    }
    printf("Marc position is at (%d,%d)\n", node->local.pos.x,node->local.pos.y);*/
    return 0;
}
