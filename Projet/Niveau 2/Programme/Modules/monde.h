/**
 * \file monde.h
 * \brief Module contenant le monde
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 7 avril 2021
 */



#ifndef MONDE_H
#define MONDE_H

#include "sdl2-light.h"
#include "param.h"
#include "graphics.h"


/**
 * \brief Représentation du monde du jeu
*/

struct world_s{
    sprite_t vaisseau; /*! < Ajout d'un vaisseau de type sprite_t au monde */
    sprite_t arrivee; /*! < Ajout de la ligne d'arrivée de type sprite_t au monde */
    sprite_t mur; /*! <Ajout du mur de meteorite de type sprite_t au monde */
    
    int gameover; /*!< Champ indiquant si l'on est à la fin du jeu */
    int vitesse; /*!< Vitesse de déplacement de base des strucures*/

};

/**
 * \brief Type qui correspond aux données du monde
 */

typedef struct world_s world_t;

/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */

void init_data(world_t * world);


/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */

/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */

int is_game_over(world_t *world);


/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param les données du monde
 */

void update_data(world_t *world);


/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */

void handle_events(SDL_Event *event,world_t *world);


















#endif