/**
 * \file vaisseau.c
 * \author Strub Nicolas Demange Dan
 * \brief Gestion des collision et autres pour le vaisseau
 * \version 1.0
 * \date 12/04/2021
 */

#include "vaisseau.h"


void depacement_gauche(world_t *world){
    if (world->vaisseau.x < 0){
        world->vaisseau.x = 0;
    }
}



void depacement_droite(world_t *monde){
    if(monde->vaisseau.x + SHIP_SIZE > SCREEN_WIDTH){//On rentre dès qu'un morceau du vaisseau sort de l'écran
        printf("boucle prise");
        monde->vaisseau.x = SCREEN_WIDTH - SHIP_SIZE;
    }
}

void depacement(world_t *monde){
    depacement_droite(monde);
    depacement_gauche(monde);
}