/**
 * \file graphics.h
 * \brief Module contenant les 
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 7 avril 2021
 */

#include "sdl2-light.h"

#ifndef GRAPHICS_H
#define GRAPHICS_H


// DEFINITION DES STRUCTURES //

/**
*\struct sprite_s
*\typedef sprite_t
*\brief Représente un sprite du jeu
*/
struct sprite_s{
    int x; /*!< Abscisse du centre de l'image. */
    int y; /*!< Ordonnée du centre de l'image. */
    int h; /*!< Hauteur de l'image.*/
    int w; /*!< Largeur de l'image.*/
};
typedef struct sprite_s sprite_t;



/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/

struct textures_s{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* vaisseau; /*!< Texture liée à l'image du vaisseau. */
    SDL_Texture* arrivee; /*!< Texture liée à l'image de la ligne d'arrivée */
    SDL_Texture* meteorite; /*!< Texture liée à l'image de meteorite */
};


/**
 * \brief Type qui correspond aux textures du jeu
*/

typedef struct textures_s textures_t;




// PROTOTYPES DES FONCTIONS EN RAPPORT AVEC LES GRAPHIQUES DU JEUX //

/**
 * \brief fonction qui affiche dans le terminal les coordonées d'un sprite
 * \param sprite le sprite
 */

void print_sprite(sprite_t *sprite);


/**
 * \brief La fonction nettoie les données du monde
 * \param *sprite l'adresse de l'enregistrement de type sprite_t
 * \param int x, int y les coordonnées du sprite
 * \param  int w, int h la largeur et hauteur du sprite
 */

void init_sprite(sprite_t *sprite, int x, int y, int w, int h);


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
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer le renderer lié à l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures);


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

#endif