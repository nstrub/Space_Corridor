/**
 * \file param.h
 * \brief Fichier de test pour le 2) du niveau 2
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 8 avril 2021
 */

#include "../Modules/monde.h"
#include "../Modules/param.h"
#include "../Modules/vaisseau.h"


void test_init_sprite_param(sprite_t *sprite, int x, int y, int w, int h){
    init_sprite(sprite,x,y,w,h);
    print_sprite(sprite);
}

void test_init_sprite(){
    printf("------test_init_sprite------\n\n");
    sprite_t sprite;
    test_init_sprite_param(&sprite,0,0,0,0);
    printf("\n\n");
    test_init_sprite_param(&sprite,50,50,10,10);
    printf("\n\n");
    test_init_sprite_param(&sprite,0,100,25,75);
    printf("\n\n");
    test_init_sprite_param(&sprite,100,0,75,25);
    printf("\n\n");
    test_init_sprite_param(&sprite,100,100,SHIP_SIZE,SHIP_SIZE);
    printf("\n\n\n\n");
}

void param_depacement_droite(world_t *monde){
    printf("le sprite ce trouve en x = %d\nSa largeur est w = %d\nla largeur de l'écran est sw = %d\n", monde->vaisseau.x, monde->vaisseau.x, SCREEN_WIDTH);
    depacement_droite(monde);
    printf("La nouvelle coordonnée du vaisseau est x = %d\n\n", monde->vaisseau.x);
        
}


void param_depacement_gauche(world_t *monde){
    printf("le sprite ce trouve en x = %d\nSa largeur est w = %d\nla largeur de l'écran est sw = %d\n", monde->vaisseau.x, monde->vaisseau.x, SCREEN_WIDTH);
    depacement_gauche(monde);
    printf("La nouvelle coordonnée du vaisseau est x = %d\n\n", monde->vaisseau.x);
        
}


void test_depacement_droite(){
    printf("------test_depacement_droite------\n\n");
    world_t monde;
    
    // On teste pour une utilisation normale
    init_sprite(&monde.vaisseau, 100, 100, SHIP_SIZE, SHIP_SIZE);
    param_depacement_droite(&monde);

    // On teste pour le vaisseau en dehors de la zone de jeu
    init_sprite(&monde.vaisseau, 301, 100, SHIP_SIZE, SHIP_SIZE);
    param_depacement_droite(&monde);

    // On teste pour le vaisseau entre la zone de jeu et la non zone de jeu
    init_sprite(&monde.vaisseau, 295, 100, SHIP_SIZE, SHIP_SIZE);
    param_depacement_droite(&monde);
    printf("\n\n\n\n");
}


void test_depacement_gauche(){
    world_t monde;
    init_sprite(&monde.vaisseau, 100, 100, SHIP_SIZE, SHIP_SIZE);
    param_depacement_gauche(&monde);
    init_sprite(&monde.vaisseau, -1, 100, SHIP_SIZE, SHIP_SIZE);
    param_depacement_gauche(&monde);
    init_sprite(&monde.vaisseau, 10, 100, SHIP_SIZE, SHIP_SIZE);
    param_depacement_gauche(&monde);
}


void param_sprite_collide(sprite_t *sp1, sprite_t *sp2){

}

void test_sprite_collide(){

}






int main( int argc, char* args[] ){
    printf("\n\n------------EXECUTION DE TESTS------------\n            __________________\n\n\n");
    test_init_sprite();
    test_depacement_droite();
    test_depacement_gauche();
    return 0;
}
