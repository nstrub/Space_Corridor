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

    //Sortie de jeu du vaisseau
    depacement(world);

    //Collisions
    handle_sprite_collision(&world->arrivee, &world->vaisseau, world);
    handle_sprite_collision(&world->mur, &world->vaisseau, world);
}

int sprites_collide(sprite_t *sp1, sprite_t *sp2){
    int x1,x2,y1,y2,w1,w2,h1,h2,col_x = 0,col_y = 0;
    x1=sp1->x;
    y1=sp1->y;
    w1=sp1->w;
    h1=sp1->h;
    x2=sp2->x;
    y2=sp2->y;
    w2=sp2->w;
    h2=sp2->h;
    
    if ((x2 > x1 && x2 < x1 + w1) || (x2 + w2 > x1 && x2 + w2 < x1 + w1))   //Gestion de la collision dans la largeur
    {
        col_x = 1;
    }

    if ((y2 > y1 && y2 < y1 + h1) || (y2 + h2 > y1 && y2 + h2 < y1 + h1))   //Gestion de la collision dans la hauteur
    {
        col_y = 1;
    }
    
    if (col_x && col_y)                                                     //S'il y a une collision en hauteur ET en largeur
    {
        return 1;
    }
    return 0;
}

void handle_sprite_collision(sprite_t *sp1, sprite_t *sp2, world_t *world){

    if(sprites_collide(sp1,sp2)){
        world->vitesse = 0;             //Le vaisseau (sp1) entre en conllision avec sp2, la vitesse devient nulle
        world->desappear = 1;             //Le vaisseau (sp1) entre en conllision avec sp2, le vaisseau disparait
    }
}