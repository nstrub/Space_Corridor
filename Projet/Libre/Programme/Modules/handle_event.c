/**
 * @file handle_event.c
 * @author Strub Nicolas Demange Dan
 * @brief Fichier contenant la fonction handle event (parce que c'est plus simple)
 * @version 1.0
 * @date 2021-04-12
 * 
 */

#include "handle_event.h"




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
             //si la touche échap est appuyée
            if(event->key.keysym.sym == SDLK_ESCAPE)
            {
                world->gameover = 1;
            }

            if(world->game != 0 && world->game != 1) 
            {

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

            // Dans l'écran titre
            if(world->game == 0)
            {
                //si la touche appuyée est 'espace'
                if(event->key.keysym.sym == SDLK_SPACE)
                {

                 world->game = 1;
                 
                }
            }

            // Dans le menu
            if(world->game == 1) 
            {

                //si la flèche du haut est appuyée
                if(event->key.keysym.sym == SDLK_UP)
                {
                    if(world->menu == 0)
                    {
                        world->menu = menu_max;
                    }
                    else
                    {
                        world->menu += -1;
                    }
                }
                //si la flèche du haut est appuyée
                if(event->key.keysym.sym == SDLK_DOWN)
                {
                    if(world->menu == menu_max)
                    {
                        world->menu = 0;
                    }
                    else
                    {
                        world->menu += 1;
                    }
                }


                //si la touche appuyée est espace
                if(event->key.keysym.sym == SDLK_RETURN)
                {
                 world->game = 2;
                }
            }
        }
    }
}