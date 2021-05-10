/**
 * \file param.h
 * \brief Module contenant toutes les constantes
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 7 avril 2021
 */




#ifndef PARAM_H
#define PARAM_H

#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include <stdio.h>
#include <stdlib.h>


// Définitions
/**
 * \brief Largeur de l'écran de jeu
 */
#define SCREEN_WIDTH 300

/**
 * \brief Hauteur de l'écran de jeu
 */
#define SCREEN_HEIGHT 480


/**
 * \brief Taille d'un vaisseau
 */

#define SHIP_SIZE 32


/**
 * \brief Taille d'un météorite
*/

#define METEORITE_SIZE 32


/**
 * \brief Hauteur de la ligne d'arrivée
 */


#define FINISH_LINE_HEIGHT 10


/**
 * \brief Pas de déplacement horizontal du vaisseau
*/

#define MOVING_STEP 10


/**
  * \brief Vitesse initiale de déplacement vertical des éléments du jeu 
*/

#define INITIAL_SPEED 2

/**
 * @brief Nombre de murs de méréorites dans le jeu
 * 
 */
#define MURS_NBR 6


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
 * \brief Représentation du monde du jeu
*/

struct world_s{
    sprite_t vaisseau; /*! < Ajout d'un vaisseau de type sprite_t au monde */
    sprite_t arrivee; /*! < Ajout de la ligne d'arrivée de type sprite_t au monde */
    sprite_t mur; /*! <Ajout du mur de meteorite de type sprite_t au monde */
    sprite_t murs[MURS_NBR]; /*! <Ajout des murs de meteorites de type sprite_t au monde.*/

    int gameover; /*!< Champ indiquant si l'on est à la fin du jeu */
    int vitesse; /*!< Vitesse de déplacement de base des strucures*/
    int desappear; /*!< Variable qui sert à afficher le sprite du vaisseau*/

};

/**
 * \brief Type qui correspond aux données du monde
 */

typedef struct world_s world_t;




/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/

struct textures_s{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* vaisseau; /*!< Texture liée à l'image du vaisseau. */
    SDL_Texture* arrivee; /*!< Texture liée à l'image de la ligne d'arrivée */
    SDL_Texture* meteorite; /*!< Texture liée à l'image de meteorite */
    TTF_Font* font; /*!< Police d'écriture pour l'affichage dans le jeu */
};


/**
 * \brief Type qui correspond aux textures du jeu
*/

typedef struct textures_s textures_t;


#endif