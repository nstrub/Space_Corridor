/**
 * \file main.c
 * \brief Programme principal initial du niveau 1
 * \author Mathieu Constant
 * \version 1.0
 * \date 18 mars 2021
 */

#include "Modules/param.h"
#include "Modules/sdl2-light.h"
#include "Modules/graphics.h"





/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */

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


/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */

void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    
}




/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */

int is_game_over(world_t *world){
    return world->gameover;
}



/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param les données du monde
 */

void update_data(world_t *world){
    // Déplacement de la ligne d'arrivée
    world->arrivee.y += world->vitesse ;

    // Déplacement du mur de météore
    world->mur.y += world->vitesse ;
}



/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */

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


/**
 *  \brief programme principal qui implémente la boucle du jeu
 */


int main( int argc, char* args[] )
{
    SDL_Event event;
    world_t world;
    textures_t textures;
    SDL_Renderer *renderer;
    SDL_Window *window;

    //initialisation du jeu
    init(&window,&renderer,&textures,&world);
    
    while(!is_game_over(&world)){ //tant que le jeu n'est pas fini
        
        //gestion des évènements
        handle_events(&event,&world);
        
        //mise à jour des données liée à la physique du monde
        update_data(&world);
        
        //rafraichissement de l'écran
        refresh_graphics(renderer,&world,&textures);
        
        // pause de 10 ms pour controler la vitesse de rafraichissement
        pause(10);
    }
    
    //nettoyage final
    clean(window,renderer,&textures,&world);
    
    
    return 0;
}
