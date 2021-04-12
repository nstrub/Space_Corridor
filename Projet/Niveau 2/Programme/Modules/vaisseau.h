/**
 * \file vaisseau.h
 * \brief Module d'interaction entre le vaisseau et l'écran
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 12/04/2021
 */

#ifndef VAISSEAU_H
#define VAISSEAU_H

#include "graphics.h"
#include "monde.h"
#include "param.h"
#include "vaisseau.h"

/**
 * @brief Fonction qui replace le vaisseau lorsqu'il sort de l'écran à gauche
 * 
 * @param monde 
 */
void depacement_gauche(world_t *monde);

/**
 * @brief Fonction qui replace le vaisseau lorsqu'il sort de l'écran à gauche
 * 
 * @param monde 
 */
void depacement_droite(world_t *monde);

/**
 * @brief Fonction qui replace le vaisseau lorsqu'il sort de l'écran (gère les deux côtés)
 * 
 * @param monde 
 */
void depacement(world_t *monde);









#endif