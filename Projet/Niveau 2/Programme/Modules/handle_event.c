/**
 * @file handle_event.c
 * @author Strub Nicolas Demange Dan
 * @brief Fichier contenant la fonction handle event (parce que c'est plus simple)
 * @version 1.0
 * @date 2021-04-12
 * 
 */

#include "handle_event.h"
#include "sdl2-light.h"
#include "monde.h"


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