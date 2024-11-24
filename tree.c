//
// Created by LiamC on 08/11/2024.
//

#include "tree.h"


#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "moves.h"
#include "map.h"


t_node* create_node(int x,int y,t_orientation orientation) {
    t_node *node = (t_node*)malloc(sizeof(t_node));
    if (!node) {
        printf("Memory allocation error\n");
        return NULL;
    }
// initialiser les coordonnées du node local = localisation et boucle pour les coordonnées des enfants
    node->local = loc_init(x,y, orientation);
    node->nb_enfant = 0;
    for (int i = 0; i < 8; i++) {
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
//Met l'adresse du premier noeud comme suivant de l'arbre
    tree->root = create_node(x, y, orientation);
    return tree;
}

void add_node_to_tree(t_node* node,int x,int y, t_orientation orientation, int mouvement) {
    t_node *new_node = create_node(x, y, orientation);
    if (!new_node) {
        printf("Memory allocation error\n");
        return;
    }
    //Si le mouvement choisie fait partie des 8 actions, alors on implément un nouveau noeud
    if (mouvement > -1 && mouvement < 9) {
        node->enfant[mouvement] = new_node;
    }
    //Définie les coordnonnées du nouveau noeud implémenté
    new_node->local = loc_init(x, y, orientation);
    new_node->parent = node;
}

void free_node(t_node* node) {
    if (node == NULL) {
        return;
    }
    // Libérer tous les enfants
    for (int i = 0; i < 7; i++) {
        if (node->enfant[i] != NULL) {
            free_node(node->enfant[i]);
        }
    }
    // Libérer le nœud lui-même
    free(node);
}
void dfs(t_node* node, t_position base, t_map map) {
    if (node == NULL) {
        return; // Si l'arbre est vide (le nœud de départ est NULL), on quitte immédiatement.
    }

    // Création d'une file de capacité 100 pour gérer les nœuds à explorer.
    t_node_queue queue = createQueue_node(1000);

    // Ajout du nœud racine (point de départ) dans la file.
    enqueue_node(&queue, node);

    // Boucle principale : continue tant que la file n'est pas vide.
    while (queue.first != queue.last) {
        // Récupération du premier nœud de la file pour traitement.
        t_node* current_node = dequeue_node(&queue);

        // Affichage des coordonnées du nœud en cours de visite.
        printf("Visit: (%d, %d)\n", current_node->local.pos.x, current_node->local.pos.y);

        // Si le nœud courant correspond à la position de la base cible, on arrête la recherche.
        if (current_node->local.pos.x == base.x && current_node->local.pos.y == base.y) {
            printf("La base a ete atteinte en (%d,%d)\n", current_node->local.pos.x, current_node->local.pos.y);

            // Nettoyage des ressources avant de quitter la fonction.
            freeQueue_node(&queue);
            free_node(node);
            return;
        }

        // Définition de la liste des mouvements possibles depuis le nœud courant.
        t_move movement[7] = {F_10, F_20, F_30, B_10, T_LEFT, T_RIGHT, U_TURN};


        // Parcours de chaque mouvement possible.
        for (int i = 0; i < 7; i++) {
            // Calcul de la nouvelle localisation en appliquant le mouvement.
            t_localisation localisation = move(current_node->local, movement[i]);
            // Vérification :
            // 1. Si le nœud enfant correspondant n'existe pas encore.
            // 2. Si la localisation résultante est valide (dans les limites de la carte).
            if (current_node->enfant[i] == NULL && isValidLocalisation(localisation.pos, map.x_max, map.y_max) == 1) {
                // Création d'un nouveau nœud enfant pour cette localisation.
                current_node->enfant[i] = create_node(localisation.pos.x, localisation.pos.y, localisation.ori);

                printf("Visit: (%d, %d)\n", current_node->enfant[i]->local.pos.x, current_node->enfant[i]->local.pos.y);
                // Ajout du nœud enfant dans la file pour exploration future.
                enqueue_node(&queue, current_node->enfant[i]);
            }
            // Message de débogage pour confirmer que l'exécution avance correctement.
            printf(" ca fonctionne ");
        }
    }

    // Nettoyage des ressources : libération de la file et de l'arbre.
    freeQueue_node(&queue);
    free_node(node);
}
