/**
 * \file monde.h
 * \brief Module contenant le monde
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 7 avril 2021
 */



#ifndef MONDE_H
#define MONDE_H

#include "param.h"





/**
 * \brief La fonction nettoie les données du monde
 * \param *sprite l'adresse de l'enregistrement de type sprite_t
 * \param int x, int y les coordonnées du sprite
 * \param  int w, int h la largeur et hauteur du sprite
 */

void init_sprite(sprite_t *sprite, int x, int y, int w, int h);


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