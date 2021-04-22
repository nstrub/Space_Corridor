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


/// CA COPI SAL 
void crea_wall(textures_t *textures,SDL_Renderer *renderer,world_t *world,int x,int y,int h,int w){
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            // Applique i*j fois la texture pour créer le mur de météorites
            apply_texture(textures->meteorite, renderer,x+j*METEORITE_SIZE,y+i*METEORITE_SIZE);
        }
    }
}

void apply_walls(SDL_Renderer *renderer, textures_t *textures, world_t *world){
    for(int i=0;i<MURS_NBR;i++){
        // Applique la texture autant de fois qu'il a de murs de météorites
        crea_wall(textures,renderer,world, world->murs[i].x,world->murs[i].y,world->murs[i].h/METEORITE_SIZE,world->murs[i].w/METEORITE_SIZE);
    }
}


//La fonction rafraichit l'écran en fonction de l'état des données du monde
void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    
    //on vide le renderer
    clear_renderer(renderer);

    //application des textures dans le renderer
    apply_background(renderer, textures->background);

    // Le vaisseau est afficher si rentré ici
    if(world->desappear != 1){
        apply_sprite(renderer, textures->vaisseau, &world->vaisseau);   
    }
    
    //affichage de la ligne d'arrivé
    apply_sprite(renderer, textures->arrivee, &world->arrivee);         

    //Affichage et applique les collisions des murs
    apply_walls(renderer, textures, world);

    //Crée le mur de météorites


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
