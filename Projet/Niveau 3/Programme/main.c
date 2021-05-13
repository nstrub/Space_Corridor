/**
 * \file main.c
 * \brief Programme principal initial du niveau 1
 * \author Mathieu Constant
 * \version 1.0
 * \date 18 mars 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include "Modules/sdl2-light.h"
#include "Modules/graphics.h"
#include "Modules/monde.h"
#include "Modules/handle_event.h"
#include "Modules/vaisseau.h"

















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
    int temps_ecoule = 0;
    world.game = 0;
    
    
        //Affiche l'écran titre
    while(world.game == 0){
        ecran_titre(renderer,&world,&textures);

        handle_events(&event,&world);

        pause(10);
    
    }
    // Début de partie
    
    while(!is_game_over(&world)){ //tant que le jeu n'est pas fini
        //Le temps s'écoule
        temps_ecoule = SDL_GetTicks();
        
        //gestion des évènements
        handle_events(&event,&world);
        
        //mise à jour des données liée à la physique du monde
        update_data(&world,temps_ecoule);
        
        //rafraichissement de l'écran
        refresh_graphics(renderer,&world,&textures, temps_ecoule);
        
        // pause de 10 ms pour controler la vitesse de rafraichissement
        pause(10);
    }
    



    //Fin de partie
    end_graphics(renderer,&world,&textures, temps_ecoule);
    
    //On fait une pause de 4 secondes avant de fermer le jeu
    pause(4000);
    
    //nettoyage final
    clean(window,renderer,&textures,&world);
    
    
    return 0;
}
