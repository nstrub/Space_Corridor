/**
 * \file tests.c
 * \brief Fichier de test pour le 2) du niveau 2
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 8 avril 2021
 */

#include "../Modules/monde.h"
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
    printf("------test_depacement_gauche------\n\n");
    world_t monde;
    init_sprite(&monde.vaisseau, 100, 100, SHIP_SIZE, SHIP_SIZE);
    param_depacement_gauche(&monde);
    init_sprite(&monde.vaisseau, -1, 100, SHIP_SIZE, SHIP_SIZE);
    param_depacement_gauche(&monde);
    init_sprite(&monde.vaisseau, 10, 100, SHIP_SIZE, SHIP_SIZE);
    param_depacement_gauche(&monde);
    printf("\n\n\n\n");
}





//Sprite_collide


void param_sprite_collide(sprite_t *sp1, sprite_t *sp2){
    printf("Pour les sprites sp1 : \n");
    print_sprite(sp1);
    printf("\nEt sp2 :\n");
    print_sprite(sp2);
    printf("\nLa fonction renvoie : %d\n\n", sprites_collide(sp1, sp2));
}

void test_sprite_collide(){
    printf("------test_sprite_collide------\n\n");
    sprite_t spr1, spr2;
    // S'ils ne se touchent pas.
    init_sprite( &spr1 , 0 , 0, 10 , 10);
    init_sprite( &spr2 , 100 , 100, 10 , 10);
    param_sprite_collide(&spr1 , &spr2);
    printf("\n\n\n");

    // S'ils se touchent sur les côtés
    init_sprite( &spr1 , 0 , 0, 10 , 10);
    init_sprite( &spr2 , 8 , 1, 9 , 9);
    param_sprite_collide(&spr1 , &spr2);
    printf("\n\n\n");

    // s'ils se touchent par le haut et bas
    init_sprite( &spr1 , 0 , 0, 10 , 10);
    init_sprite( &spr2 , 1 , 8, 9 , 9);
    param_sprite_collide(&spr1 , &spr2);
    printf("\n\n\n");

    // s'ils se frôlent 
    init_sprite( &spr1 , 0 , 0, 10 , 10);
    init_sprite( &spr2 , 10 , 10, 9 , 9);
    param_sprite_collide(&spr1 , &spr2);
    printf("\n\n\n\n");
}







//handle_sprite_collision

void param_handle_sprite_collision(sprite_t *sp1, sprite_t *sp2, world_t *world){
    handle_sprite_collision( sp1 , sp2 , world );
    printf("Pour les spirtes sp1 : \n");
    print_sprite(sp1);
    printf("\nEt sp2 :\n");
    print_sprite(sp2);
    printf("\nLa vitesse du monde vaut : %d\n\n", world->vitesse);
    printf("\n\n");
}

void test_handle_sprite_collision(){
    printf("------test_handle_collision------\n\n");
    // Initialisation
    sprite_t spr1, spr2;
    world_t world;
    world.vitesse = 100;

    // S'ils ne se touchent pas.
    init_sprite( &spr1 , 0 , 0, 10 , 10);
    init_sprite( &spr2 , 100 , 100, 10 , 10);
    param_handle_sprite_collision(&spr1 , &spr2, &world);
    printf("\n\n\n");

    // S'ils se touchent
    init_sprite( &spr1 , 0 , 0, 10 , 10);
    init_sprite( &spr2 , 8 , 1, 9 , 9);
    param_handle_sprite_collision(&spr1 , &spr2, &world);

    printf("\n\n\n\n");
}

void param_init_walls(world_t monde){
    for(int i = 0; i < MURS_NBR; i++){
        printf("le tableau %d :\n", i );
        print_sprite(&monde.murs[i]);
        printf("\n\n\n");
    }

}


void test_init_walls(){
    printf("------test_init_walls------\n\n");
    // Initialisation
    world_t monde;
    init_walls(&monde);

    //On vérifie qu'ils affiche ce que l'on veut (à comparer avec le tableau attendu).
    param_init_walls(monde);

    printf("\n\n\n\n");
}

void param_update_walls(world_t *monde){
    printf("\n\n\nLa vitesse du monde est de :  %d\n\n\n\nVoici les données de deux sprites :\n\n", monde->vitesse);
    print_sprite(&monde->murs[1]);
    printf("\n\n");
    print_sprite(&monde->murs[2]);
    for(int n = 0; n < 3; n++){
        update_walls(monde);
        printf("\n\n\n\n\nAprès avoir appliqué %d fois update_walls :\n\n", n+1);
        print_sprite(&monde->murs[1]);
        printf("\n\n");
        print_sprite(&monde->murs[2]);
    }
}

void test_update_walls(){

    printf("------test_update_walls------\n\n");

    // Initialisation
    world_t monde;
    monde.vitesse = 5;
    init_sprite(&monde.murs[0], 48,0,96,192);
    init_sprite(&monde.murs[1],252,58,96,192);
    
    param_update_walls(&monde);
    printf("\n\n\n\n");
    
}



//test_fin_de_partie

void param_fin_de_partie(world_t *monde){
    printf("La vitesse du monde est :  %d\n\nLe desappear vaut : %d\n\nGameover vaut : %d\n\n\n", monde->vitesse, monde->desappear, monde->gameover);
    fin_de_partie(monde);
    printf("\n\nAprès la fonction fin de partie :\n\n\nLa vitesse du monde est :  %d\n\nLe desappear vaut : %d\n\nGameover vaut : %d\n\n\n", monde->vitesse, monde->desappear, monde->gameover);
}


void test_fin_de_partie(){

    printf("------test_fin_de_partie------\n\n\n");

    //initialisation
    world_t monde;
    monde.vitesse = 10;             
    monde.desappear = 10;
    monde.gameover = 10;  

    param_fin_de_partie(&monde);



    printf("\n\n\n\n");
}





















int main( int argc, char* args[] ){
    printf("\n\n------------EXECUTION DE TESTS------------\n            __________________\n\n\n");
    test_init_sprite();
    test_depacement_droite();
    test_depacement_gauche();
    test_sprite_collide();
    test_handle_sprite_collision();
    test_init_walls();
    test_update_walls();
    test_fin_de_partie();
    return 0;
}

