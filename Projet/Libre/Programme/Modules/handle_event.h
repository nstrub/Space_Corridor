/**
 * \file handle_event.h
 * \brief Module contenant le monde
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 7 avril 2021
 */


#ifndef HANDLE_EVENT_H
#define HANDLE_EVENT_H

#include <stdio.h>
#include <stdlib.h>
#include "sdl2-light.h"
#include "monde.h"

/**
 * @brief Fonction visant à géré tout les évènements ce déroulant lors de la boucle de jeu
 * 
 * @param event 
 * @param world 
 */

void handle_events(SDL_Event *event,world_t *world);

#endif