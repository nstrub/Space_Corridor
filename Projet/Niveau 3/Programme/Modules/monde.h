/**
 * \file monde.h
 * \brief Module contenant le monde
 * \author STRUB Nicolas DEMANGE Dan
 * \version 1.0
 * \date 7 avril 2021
 */



#ifndef MONDE_H
#define MONDE_H

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
    int end; /*!< Type de fin de partie*/

};

/**
 * \brief Type qui correspond aux données du monde
 */

typedef struct world_s world_t;
















//Prototypes de Fonctions




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

void update_data(world_t *world, int temps);




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



/**
 * @brief Fonction qui met fin à la partie en cas de victoire
 * 
 * @param sp1 premier sprite de type sprite_t
 * @param sp2 deuxième sprite de type sprite_t
 * @param world les données du monde
 */
void finish_line(sprite_t *sp1, sprite_t *sp2, world_t *world, int temps);


/**
 * @brief Fonction qui met fin à la partie si le vaisseau se crash
 * 
 * @param world les données du monde
 */
void crash(world_t *world);

/**
 * @brief Fonction qui met fin à la partie en cas de défaite
 * 
 * @param sp1 premier sprite de type sprite_t
 * @param sp2 deuxième sprite de type sprite_t
 * @param world les données du monde
 */
void collision_meteore(sprite_t *sp1, sprite_t *sp2, world_t *world);


/**
 * @brief Fin de partie
 * 
 * @param world les données du monde
 */
void fin_de_partie(world_t *world);

#endif