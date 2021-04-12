/**
 * \file monde.c
 * \brief Module contenant le monde
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 7 avril 2021
 */


#include "graphics.h"
#include "monde.h"
#include "vaisseau.h"
#include "param.h"


//La fonction nettoie les données du monde
void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
}


//fonction qui affiche dans le terminal les coordonées d'un sprite.
void print_sprite(sprite_t *sprite){
    printf("Les coordonnées du sprite x/y sont : %d et %d\n",sprite->x,sprite->y);
    printf("La hauteur et largeur font : %d et %d\n",sprite->h,sprite->w);
}


int is_game_over(world_t *world){
    return world->gameover;
}



void update_data(world_t *world){
    // Déplacement de la ligne d'arrivée
    world->arrivee.y += world->vitesse ;

    // Déplacement du mur de météore
    world->mur.y += world->vitesse ;

    //Sorite de jeu du vaisseau
    depacement(world);
}





int sprites_collide(sprite_t *sp1, sprite_t *sp2){ 
    if(abs(sp1->x-sp2->x) <= (sp1->w+sp2->w) /2 && abs(sp1->y-sp2->y) <= (sp1->h+sp2->h)/2){
        return 1;
    }
    else{
        return 0;
    }
}