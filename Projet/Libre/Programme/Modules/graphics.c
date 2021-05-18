/**
 * \file graphics.c
 * \author Demange Dan & Nicolas Strub
 * \brief Gestion des ressources graphiques
 * \version 1.0
 * \date 07/04/2021
 */

#include "graphics.h"


//Les fonctions//



//La fonction nettoie les textures
void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->vaisseau);
    clean_texture(textures->arrivee);
    clean_texture(textures->meteorite);
    clean_texture(textures->coin);
}


//La fonction initialise les textures nécessaires à l'affichage graphique du jeu
void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/space-background.bmp",renderer);
    textures->vaisseau = load_image( "ressources/spaceship.bmp", renderer);
    textures->arrivee = load_image( "ressources/finish_line.bmp", renderer);
    textures->meteorite = load_image( "ressources/meteorite.bmp", renderer);  
    textures->coin = load_image("ressources/coin.bmp", renderer);
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

    // //Affichage + applique la piece
    apply_sprite(renderer, textures->coin,&world->coin);

    char tempstr[20];
    sprintf(tempstr, "%d", temps/1000);
    //On applique le texte
        //Pour le temps :
    apply_text(renderer, 230, 0,60,60,tempstr,textures->font);
    apply_text(renderer, 140, 0,80,60,"Temps :",textures->font);
        //On affiche les pièces :
    char mabite[20];
    sprintf(mabite, "%d", world->coins);
    apply_text(renderer, 90, 0,55,60,mabite,textures->font);
    apply_text(renderer, 5, 0,80,60,"Coins :",textures->font);

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

void end_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures, int temps){
    //on vide le renderer
    clear_renderer(renderer);


    // Si le joueur gagne
    if(world->end == 0){
        //application des textures dans le renderer
        apply_background(renderer, textures->background);

        //On créé un tableau de charactère
        char tempstr[20];
        //On converti le temps de nombre à un charactère afin de le mettre dans le tableau
        sprintf(tempstr, "%d", temps/1000);

        //On applique le texte (de victoire)
        apply_text(renderer, 10, 335,70,70,tempstr,textures->font);
        apply_text(renderer, 30, 200,240,100,"Victoire en :",textures->font);
        apply_text(renderer, 80, 330,190,80,"Sec",textures->font);

    }

    //Si le joueur perd
    else if(world->end == 1){
        //application des textures dans le renderer
        apply_background(renderer, textures->background);

        //On applique le texte (de défaite pas besoin d'afficher le temps)
        apply_text(renderer, 30, 200,240,100,"Vous avez perdu",textures->font);
    }

    //Si le joueur utilise échape
    else{
        
        apply_title(renderer, 30, 200,240,100,"A plus",textures->font);
    }



    //On met à jour l'affichage sur le renderer une fois sorti d'une boucle
    update_screen(renderer); 
}


void ecran_titre(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    clear_renderer(renderer);
    apply_title(renderer, 28, 50,240,100,"Space corridor",textures->font);
    update_screen(renderer);
    pause(200);
    apply_title(renderer, 60, 250,170,70,"Press space",textures->font);
    pause(200);
    update_screen(renderer);
    pause(1000); 
    
}

void menu(SDL_Renderer *renderer, world_t *world,textures_t *textures){

    //Netoyage de l'écran
    clear_renderer(renderer);
    apply_title(renderer, 28, 50,240,100,"Space corridor",textures->font);
    if(world->menu == 0)
    {
        apply_text(renderer, 90, 190,120,50,"Niveau 1",textures->font);
        apply_title(renderer, 90, 280,120,50,"Niveau 2",textures->font);
        apply_title(renderer, 90, 370,120,50,"Niveau 3",textures->font);
    }

    else if(world->menu == 1)
    {
        apply_title(renderer, 90, 190,120,50,"Niveau 1",textures->font);
        apply_text(renderer, 90, 280,120,50,"Niveau 2",textures->font);
        apply_title(renderer, 90, 370,120,50,"Niveau 3",textures->font);
    }
    else if(world->menu == 2)
    {
        apply_title(renderer, 90, 190,120,50,"Niveau 1",textures->font);
        apply_title(renderer, 90, 280,120,50,"Niveau 2",textures->font);
        apply_text(renderer, 90, 370,120,50,"Niveau 3",textures->font);
    }

    // On met à jour l'écran
    update_screen(renderer);
}