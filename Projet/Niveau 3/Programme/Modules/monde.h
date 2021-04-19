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
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */

void init_data(world_t * world);

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
 * @brief Fonction qui initialise les murs dans le monde afin de faire un parcours
 * 
 * @param world les données du monde
 */
void init_walls(world_t *world);

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


/**
 * @brief gère la collision de sprite entre sprites
 * 
 * @param sp1 premier sprite de type sprite_t
 * @param sp2 deuxième sprite de type sprite_t
 */
int sprites_collide(sprite_t *sp1, sprite_t *sp2);


/**
 * @brief Fonction qui met la vitesse du vaisseau à 0 en cas de contact entre deux sprites
 * 
 * @param sp1 premier sprite de type sprite_t
 * @param sp2 deuxième sprite de type sprite_t
 * @param world les données du monde
 */
void handle_sprite_collision(sprite_t *sp1, sprite_t *sp2, world_t *world);



/**
 * @brief Fonction qui met à jour les murs en fonctions de la vistesse du monde..
 * 
 * @param world Les données du monde
 */
void update_walls(world_t *world);








#endif