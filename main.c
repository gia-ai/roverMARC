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
    printf("Base station position is at (%d, %d)\n", base.x, base.y);
    t_tree* arbre = create_tree(0, 0, SOUTH);
    t_node* node = create_node(0,0,SOUTH);
    printf("Marc position is at (%d.%d)", node->local.pos.x, node->local.pos.y);
    while (node->local.pos.x != base.x || node->local.pos.y != base.y) {
        // Code pour continuer la recherche
        for (int i = 0; i < 8; i++) {
            if (node->enfant != NULL) {
                node->enfant[i] = create_node(node->local.pos.x, node->local.pos.y,node->local.ori);
            }
        }
    }
    return 0;
}
