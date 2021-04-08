/**
 * \file param.h
 * \brief Fichier de test pour le 2) du niveau 2
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 8 avril 2021
 */

#include "../Modules/monde.h"
#include "../Modules/param.h"


void test_init_sprite_param(sprite_t *sprite, int x, int y, int w, int h){
    init_sprite(sprite,x,y,w,h);
    print_sprite(sprite);
}

void test_init_sprite(){
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
    printf("\n\n");
}

int main( int argc, char* args[] ){
    test_init_sprite();
    return 0;
}
