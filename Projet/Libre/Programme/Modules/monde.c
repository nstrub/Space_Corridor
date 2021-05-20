/**
 * \file monde.c
 * \brief Module contenant le monde
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 7 avril 2021
 */


#include "monde.h"
#include "vaisseau.h"



void init_data(world_t * world){

    

    
 
    // Mur et meteores
    //init_sprite(&world->mur,SCREEN_WIDTH/2 - 3*METEORITE_SIZE/2, SCREEN_HEIGHT/2 - 7*METEORITE_SIZE/2, METEORITE_SIZE * 3, METEORITE_SIZE  * 7 );


    //on n'est pas à la fin du jeu
    world->gameover = 0;

    //Le sprite du vaisseau et de la pièce sont affichés de base
    world->desappear = 0;
    world->desappear_coin = 0;


    world->secret = 0;


    //On met la valeur end à une valeur différente de 0 et 1
    world->end = 2;

    // On met les autres valeurs à zéro.
    world->game = 0;
    world->menu = 0;

    // Vitesse de base
    world->vitesse = INITIAL_SPEED;

      
}

void init_game(world_t * world){


    //Initialisation du vaisseau dans le monde
    init_sprite(&world->vaisseau, SCREEN_WIDTH/2 - SHIP_SIZE/2, SCREEN_HEIGHT - SHIP_SIZE*2, SHIP_SIZE, SHIP_SIZE);

    //Initialisation de la ligne d'arrivée
    init_line(world);

    //print_sprite(&world->vaisseau);


    // On initailise les murs de météores propre au niveau
    init_walls(world);

    // On initailise les pièces de météores propre au niveau
    init_coin(world);  
}



//La fonction nettoie les données du monde
void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
}


void init_line(world_t *world){

    // Si le joueur choisi le niveau 1
    if(world->menu == 0){

        init_sprite(&world->arrivee, 0, -METEORITE_SIZE*40, SCREEN_WIDTH, FINISH_LINE_HEIGHT);

    }

    // Si le joueur choisi le niveau 2
    else if(world->menu == 1){
        init_sprite(&world->arrivee, 0, -METEORITE_SIZE*40, SCREEN_WIDTH, FINISH_LINE_HEIGHT);
    }

    // Si le joueur choisi le niveau 3
    else if(world->menu == 2){
        
    }
}

//La fonction qui initialise le parcours de murs
void init_walls(world_t *world){

    // Si le joueur choisi le niveau 1
    if(world->menu == 0){

        init_sprite(&world->murs[0],0,METEORITE_SIZE*2,METEORITE_SIZE*2,METEORITE_SIZE*2);                      
        init_sprite(&world->murs[1],METEORITE_SIZE*7.5,METEORITE_SIZE*2,METEORITE_SIZE*2,METEORITE_SIZE*2);
        init_sprite(&world->murs[2],METEORITE_SIZE*2,-METEORITE_SIZE*10,METEORITE_SIZE*5,METEORITE_SIZE*2);
        init_sprite(&world->murs[3],0,-METEORITE_SIZE*25,METEORITE_SIZE*3,METEORITE_SIZE*7);
        init_sprite(&world->murs[4],METEORITE_SIZE*6.5,-METEORITE_SIZE*25,METEORITE_SIZE*3,METEORITE_SIZE*7);
        

    }

    // Si le joueur choisi le niveau 2
    else if(world->menu == 1){

        init_sprite(&world->murs[0],0,METEORITE_SIZE*2,METEORITE_SIZE*5,METEORITE_SIZE);                      
        init_sprite(&world->murs[1],METEORITE_SIZE*4.5,-METEORITE_SIZE*10,METEORITE_SIZE*5,METEORITE_SIZE);
        init_sprite(&world->murs[2],METEORITE_SIZE*2,-METEORITE_SIZE*39,METEORITE_SIZE*5,METEORITE_SIZE*2);
        init_sprite(&world->murs[3],0,-METEORITE_SIZE*25,METEORITE_SIZE*4,METEORITE_SIZE*7);
        init_sprite(&world->murs[4],METEORITE_SIZE*5.5,-METEORITE_SIZE*25,METEORITE_SIZE*4,METEORITE_SIZE*7);

    }

    // Si le joueur choisi le niveau 3
    else if(world->menu == 2){
        
    }
    
}

void init_coin(world_t *world){

    
    // Si le joueur choisi le niveau 1
    if(world->menu == 0){
        init_sprite(&world->coin,METEORITE_SIZE*4.25,-METEORITE_SIZE*35,METEORITE_SIZE,METEORITE_SIZE);

    }

    // Si le joueur choisi le niveau 2
    else if(world->menu == 1){
        init_sprite(&world->coin,METEORITE_SIZE*4.25,-METEORITE_SIZE*25,METEORITE_SIZE,METEORITE_SIZE);
    }

    // Si le joueur choisi le niveau 3
    else if(world->menu == 2){
        
    }
    
}

//fonction qui affiche dans le terminal les coordonées d'un sprite.
void print_sprite(sprite_t *sprite){
    printf("Les coordonnées du sprite x/y sont : %d et %d\n",sprite->x,sprite->y);
    printf("La hauteur et largeur font : %d et %d\n",sprite->h,sprite->w);
}

//Fonction qui regarde dans quel état est le jeu (en cours ou fini)
int is_game_over(world_t *world){
    return world->gameover;
}


//La fonction met à jour les données en tenant compte de la physique du monde
void update_data(world_t *world, int temps){
    // Déplacement de la ligne d'arrivée
    world->arrivee.y += world->vitesse ;

    // Déplacement du mur de météore
    //world->mur.y += world->vitesse ;

    update_walls(world);

    update_piece(world);

    //Sortie de jeu du vaisseau
    depacement(world);


    //Collisions
    //Si la ligne d'arrivée est franchie
    finish_line(&world->arrivee, &world->vaisseau, world, temps);

    //Si le vaisseau ce crash : fin du jeu
    crash(world);

    //Si le joueur touche une pièce
    collision_piece(&world->vaisseau,&world->coin,world);

}

//Fonction qui gère la collision entre les sprites
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

//Fonction qui met la vitesse du vaisseau à 0 en cas de contact entre deux sprites
void handle_sprite_collision(sprite_t *sp1, sprite_t *sp2, world_t *world){

    if(sprites_collide(sp1,sp2)){
        world->vitesse = 0;            
        world->desappear = 1;             
    }
}

//Fonction qui met à jour les murs en fonctions de la vistesse du monde
void update_walls(world_t *world){
    for(int i = 0; i < MURS_NBR; i++){
        world->murs[i].y += world->vitesse;
    }
}

//Fonction qui met à jour la pièce en fonction de la vitesse du monde
void update_piece(world_t *world){
    world->coin.y += world->vitesse;
}

//Fonction qui met fin à la partie en cas de victoire
void finish_line(sprite_t *sp1, sprite_t *sp2, world_t *world, int temps){
    if(sprites_collide(sp1,sp2)){// Le vaisseau atteint la ligne d'arrivée
        printf("VOUS AVEZ GAGNé(e) EN %d secondes !!! ggwp\n",temps/1000);
        printf("%d\n",world->secret);
        if(world->secret ==! 0){
            printf("W O W\nVous avez trouvé le secret :o !!! Vous êtes vraiment trop fortiche !!!\n");
        }
        else{
            printf("Vous n'avez pas trouvé le secret... Dommage :c\n");
        }
        fin_de_partie(world);
        world->end = 0;
    }
}

//Fonction qui met fin à la partie si le vaisseau se crash
void crash(world_t *world){
    for(int i = 0; i < MURS_NBR; i++){
        collision_meteore(&world->murs[i], &world->vaisseau, world);
    }
}

void collision_meteore(sprite_t *sp1, sprite_t *sp2, world_t *world){

    if(sprites_collide(sp1,sp2)){
        fin_de_partie(world);
        world->end = 1;
        printf("\n\n\n                   You loose\n\n\n");

    }
}

void collision_piece(sprite_t *sp1, sprite_t *sp2, world_t *world){
    if(sprites_collide(sp1,sp2)){
        world->secret = 1;                      //Le joueur trouve le secret !
        printf("\n\nbruit_de_pièce.mp3\n\n");   //On affiche dans la console également
        world->desappear_coin = 1;              //On fait disparaître la pièce
        init_sprite(&world->coin,0,0,0,0);   //On donne des collisions nulles au sprite
    }
}

void fin_de_partie(world_t *world){
        world->vitesse = 0;             //la vitesse devient nulle
        world->desappear = 1;             //le vaisseau disparait
        world->gameover = 1;            //La partie est finie
}