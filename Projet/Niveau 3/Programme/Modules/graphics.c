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
    textures->font = load_font ("ressources/arial.ttf",14);
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


//Creation du mur de meteorites
void crea_wall(textures_t *textures,SDL_Renderer *renderer,world_t *world,int x,int y,int h,int w){
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            // Création du mur de meteorites en appliquand i * j fois la texture
            apply_texture(textures->meteorite, renderer,x+j*METEORITE_SIZE,y+i*METEORITE_SIZE);
        }
    }
}

//Fonction qui va répéter crea_wall autant de fois qu'il y a de murs pour créé le niveau
void apply_walls(SDL_Renderer *renderer, textures_t *textures, world_t *world){
    for(int i=0;i<MURS_NBR;i++){
        // Appel de crea_wall dans la boucle
        crea_wall(textures,renderer,world, world->murs[i].x,world->murs[i].y,world->murs[i].h/METEORITE_SIZE,world->murs[i].w/METEORITE_SIZE);
    }
}


//La fonction rafraichit l'écran en fonction de l'état des données du monde
void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures, int temps){
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

    char tempstr[20];
    sprintf(tempstr, "%d", temps/1000);
    //On applique le texte
    apply_text(renderer, 230, 0,60,60,tempstr,textures->font);
    apply_text(renderer, 140, 0,80,60,"Temps :",textures->font);

    // on met à jour l'écran
    update_screen(renderer);

}

 
// Fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_textures(textures);
    clean_sdl(renderer,window);
    clean_font(textures->font);
}


//fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_ttf();
    init_data(world);
    init_textures(*renderer,textures);
    
}

void end_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures, int temps){//a finir
    //on vide le renderer
    clear_renderer(renderer);

    //application des textures dans le renderer
    apply_background(renderer, textures->background);



    if(world->end == 0){

        char tempstr[20];
        sprintf(tempstr, "%d", temps/1000);

        //On applique le texte
        apply_text(renderer, 10, 335,70,70,tempstr,textures->font);
        apply_text(renderer, 30, 200,240,100,"Victoire en :",textures->font);
        apply_text(renderer, 80, 330,190,80,"Sec",textures->font);

    }

    if(world->end == 1){

        apply_text(renderer, 30, 200,240,100,"Vous avez perdu",textures->font);
    }




    update_screen(renderer); 
}