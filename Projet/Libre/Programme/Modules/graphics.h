/**
 * \file graphics.h
 * \brief Module contenant les 
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 7 avril 2021
 */



#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdio.h>
#include <stdlib.h>
#include "monde.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"



//Definitions

/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/

struct textures_s{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* vaisseau; /*!< Texture liée à l'image du vaisseau. */
    SDL_Texture* arrivee; /*!< Texture liée à l'image de la ligne d'arrivée */
    SDL_Texture* meteorite; /*!< Texture liée à l'image de meteorite */
    SDL_Texture* coin; /*!< Texture liée à l'image de la pièce */
    TTF_Font* font; /*!< Police d'écriture pour l'affichage dans le jeu */
};


/**
 * \brief Type qui correspond aux textures du jeu
*/

typedef struct textures_s textures_t;





// PROTOTYPES DES FONCTIONS EN RAPPORT AVEC LES GRAPHIQUES DU JEUX //




/**
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/

void clean_textures(textures_t *textures);


/**
 * \brief La fonction initialise les textures nécessaires à l'affichage graphique du jeu
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/

void  init_textures(SDL_Renderer *renderer, textures_t *textures);


/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param texture la texture liée au fond
*/

void apply_background(SDL_Renderer *renderer, SDL_Texture *texture);


/**
 * \brief Va appliquer la texture "texture" associée au sprite "sprite" sur le renderer "renderer" à la position indiqué dans le sprite
 * \param renderer le renderer
 * \param texture la texture liée au fond
 * \param sprite l'enregistrement du sprite
*/

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);


/**
 * @brief Fonction qui crée un mur de metoerite (de 7X3 pour l'instant)
 * @param renderer le renderer
 * @param world les données du monde
 * @param textures la texture liée au fond
 */
void crea_wall(textures_t *textures,SDL_Renderer *renderer,world_t *world,int x,int y,int h,int w);

/**
 * @brief Fonction qui prend la position des murs et les affiches dans le renderer
 * 
 * @param renderer le renderer
 * @param world les données du monde
 * @param textures les textures
 */
void apply_walls(SDL_Renderer *renderer, textures_t *textures, world_t *world);

/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer le renderer lié à l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures, int temps);


/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les textures
* \param world le monde
*/

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world);


/**
 * \brief fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param world le monde
 */

void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world);

/**
 * @brief Fonction qui réalise l'affichage de fin de partie
 * 
 * @param renderer le renderer
 * @param world le monde
 * @param textures les textures
 * @param temps le chronomètre du monde
 */
void end_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures, int temps);



/**
 * @brief ecran_titre
 * 
 * @param renderer le renderer
 * @param textures les textures
 */
void ecran_titre(SDL_Renderer *renderer,textures_t *textures);


/**
 * @brief ecran du menu
 * 
 * @param renderer le renderer
 * @param world le monde
 * @param textures les textures
 */
void menu(SDL_Renderer *renderer, world_t *world,textures_t *textures);









#endif