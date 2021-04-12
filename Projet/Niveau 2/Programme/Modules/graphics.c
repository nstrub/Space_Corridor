/**
 * \file graphics.c
 * \author Demange Dan & Nicolas Strub
 * \brief Gestion des ressources graphiques
 * \version 1.0
 * \date 07/04/2021
 */

#include "graphics.h"
#include "monde.h"
#include "param.h"


//Les fonctions



//mettre dans monde    ------------------------------------------------------
void init_data(world_t * world){
    //initialisation du vaisseau dans le monde
    world->vaisseau.x = SCREEN_WIDTH/2 - SHIP_SIZE/2;
    world->vaisseau.y = SCREEN_HEIGHT - SHIP_SIZE*2;
    world->vaisseau.h = SHIP_SIZE;
    world->vaisseau.w = SHIP_SIZE;

    //Initialisation de la ligne d'arrivée
    world->arrivee.x = 0;
    world->arrivee.y = FINISH_LINE_HEIGHT;
    world->arrivee.h = FINISH_LINE_HEIGHT;
    world->arrivee.w = SCREEN_WIDTH;

    print_sprite(&world->vaisseau);
    //on n'est pas à la fin du jeu
    world->gameover = 0;

    // Vitesse de base
    world->vitesse = INITIAL_SPEED;

    // Mur et meteores
    world->mur.x = SCREEN_WIDTH/2 - 3*METEORITE_SIZE/2;
    world->mur.y = SCREEN_HEIGHT/2 - 7*METEORITE_SIZE/2;
    world->mur.h = METEORITE_SIZE  * 7;
    world->mur.w = METEORITE_SIZE * 3;
    


    
}


//La fonction nettoie les textures
void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->vaisseau);
    clean_texture(textures->arrivee);
    clean_texture(textures->meteorite);
}


//La fonction initialise les textures nécessaires à l'affichage graphique du jeu
void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/space-background.bmp",renderer);
    textures->vaisseau = load_image( "ressources/spaceship.bmp", renderer);
    textures->arrivee = load_image( "ressources/finish_line.bmp", renderer);
    textures->meteorite = load_image( "ressources/meteorite.bmp", renderer);  
}



//La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
void apply_background(SDL_Renderer *renderer, SDL_Texture *texture){
    if(texture != NULL){
      apply_texture(texture, renderer, 0, 0);
    }
}


//Va appliquer la texture "texture" associée au sprite "sprite" sur le renderer "renderer" à la position indiqué dans le sprite
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite){
    apply_texture(texture, renderer, sprite->x, sprite->y);
}


//La fonction rafraichit l'écran en fonction de l'état des données du monde
void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    
    //on vide le renderer
    clear_renderer(renderer);
    
    //application des textures dans le renderer
    apply_background(renderer, textures->background);

    apply_sprite(renderer, textures->vaisseau, &world->vaisseau);
    apply_sprite(renderer, textures->arrivee, &world->arrivee);

    //Mur de météorites
    for(int y = 0; y < 7; y++){
        for(int x = 0; x < 3; x ++){
            apply_texture(textures->meteorite, renderer, world->mur.x + x * METEORITE_SIZE , world->mur.y + y * METEORITE_SIZE);
        }
    }
    // on met à jour l'écran
    update_screen(renderer);

}

 
// Fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_textures(textures);
    clean_sdl(renderer,window);
}


//fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_data(world);
    init_textures(*renderer,textures);
}
