/**
 * \file monde.c
 * \brief Module contenant le monde
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 7 avril 2021
 */






#include "sdl2-light.h"
#include "param.h"
#include "graphics.h"
#include "monde.h"



void init_data(world_t * world){
    //initialisation du vaisseau dans le monde
    world->vaisseau.x = SCREEN_WIDTH/2 - SHIP_SIZE/2;
    world->vaisseau.y = SCREEN_HEIGHT - SHIP_SIZE*2;
    world->vaisseau.h = SHIP_SIZE;
    world->vaisseau.w = SHIP_SIZE;

    //Initialisation de la ligne d'arrivée
    world->arrivee.x = 0;
    world->arrivee.y = FINISH_LINE_HEIGHT;
    //world->arrivee.h = FINISH_LINE_HEIGHT; surment pas utile
    //world->arrivee.w = SCREEN_WIDTH;

    print_sprite(&world->vaisseau);
    //on n'est pas à la fin du jeu
    world->gameover = 0;

    // Vitesse de base
    world->vitesse = INITIAL_SPEED;

    // Mur et meteores
    world->mur.x = SCREEN_WIDTH/2 - METEORITE_SIZE/2*3;
    world->mur.y = SCREEN_HEIGHT/2 - METEORITE_SIZE/2*7;


    
}



int is_game_over(world_t *world){
    return world->gameover;
}



void update_data(world_t *world){
    // Déplacement de la ligne d'arrivée
    world->arrivee.y += world->vitesse ;

    // Déplacement du mur de météore
    world->mur.y += world->vitesse ;
}

































void handle_events(SDL_Event *event,world_t *world){
    Uint8 *keystates;
    while( SDL_PollEvent( event ) ) 
    {
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
            world->gameover = 1;
        }

        //si une touche est appuyée
        
        //SI LA TOUCHE ECHAP EST APPUYEE (quitter le jeu)
         
         if(event->type == SDL_KEYDOWN)
         {
             //si la touche appuyée est 'D'
            if(event->key.keysym.sym == SDLK_d)
            {
                 printf("La touche D est appuyée\n");
            }
            //si Flèche droite est appuyée
            if(event->key.keysym.sym == SDLK_RIGHT)
            {
                 world->vaisseau.x += 6;
            }
            //si Flèche gauche est appuyée
            if(event->key.keysym.sym == SDLK_LEFT)
            {
                 world->vaisseau.x += -6;
            }
            //si la touche échap est appuyée
            if(event->key.keysym.sym == SDLK_ESCAPE)
            {
                world->gameover = 1;
            }
            //si la flèche du haut est appuyée
            if(event->key.keysym.sym == SDLK_UP)
            {
                world->vitesse += 2;
            }
            //si la flèche du haut est appuyée
            if(event->key.keysym.sym == SDLK_DOWN)
            {
                world->vitesse -= 2;
            }
        }
    }
}
