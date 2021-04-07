/**
 * \file main.c
 * \brief Programme principal initial du niveau 1
 * \author Mathieu Constant
 * \version 1.0
 * \date 18 mars 2021
 */

#include "Modules/sdl2-light.h"


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
 * \brief fonction qui affiche dans le terminal les coordonées d'un sprite
 * \param sprite le sprite
 */


void print_sprite(sprite_t *sprite)
{
    printf("Les coordonnées du sprite x/y sont : %d et %d\n",sprite->x,sprite->y);
    printf("La hauteur et largeur font : %d et %d\n",sprite->h,sprite->w);
}


/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */

void init_data(world_t * world){
    //initialisation du vaisseau dans le monde
    world->vaisseau.x = SCREEN_WIDTH/2 - SHIP_SIZE/2;
    world->vaisseau.y = SCREEN_HEIGHT - SHIP_SIZE*2;
    world->vaisseau.h = SHIP_SIZE;
    world->vaisseau.w = SHIP_SIZE;

    //Initialisation de la ligne d'arrivée
    world->arrivee.x = 0;
    world->arrivee.y = FINISH_LINE_HEIGHT;
    //world->arrivee.h = FINISH_LINE_HEIGHT; surment pas utile
    //world->arrivee.w = SCREEN_WIDTH;

    print_sprite(&world->vaisseau);
    //on n'est pas à la fin du jeu
    world->gameover = 0;

    // Vitesse de base
    world->vitesse = INITIAL_SPEED;

    // Mur et meteores
    world->mur.x = SCREEN_WIDTH/2 - METEORITE_SIZE/2*3;
    world->mur.y = SCREEN_HEIGHT/2 - METEORITE_SIZE/2*7;


    
}


/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */

void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    
}




/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */

int is_game_over(world_t *world){
    return world->gameover;
}



/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param les données du monde
 */

void update_data(world_t *world){
    // Déplacement de la ligne d'arrivée
    world->arrivee.y += world->vitesse ;

    // Déplacement du mur de météore
    world->mur.y += world->vitesse ;
}



/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */

void handle_events(SDL_Event *event,world_t *world){
    Uint8 *keystates;
    while( SDL_PollEvent( event ) ) 
    {
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
            world->gameover = 1;
        }

        //si une touche est appuyée
        
        //SI LA TOUCHE ECHAP EST APPUYEE (quitter le jeu)
         
         if(event->type == SDL_KEYDOWN)
         {
             //si la touche appuyée est 'D'
            if(event->key.keysym.sym == SDLK_d)
            {
                 printf("La touche D est appuyée\n");
            }
            //si Flèche droite est appuyée
            if(event->key.keysym.sym == SDLK_RIGHT)
            {
                 world->vaisseau.x += 6;
            }
            //si Flèche gauche est appuyée
            if(event->key.keysym.sym == SDLK_LEFT)
            {
                 world->vaisseau.x += -6;
            }
            //si la touche échap est appuyée
            if(event->key.keysym.sym == SDLK_ESCAPE)
            {
                world->gameover = 1;
            }
            //si la flèche du haut est appuyée
            if(event->key.keysym.sym == SDLK_UP)
            {
                world->vitesse += 2;
            }
            //si la flèche du haut est appuyée
            if(event->key.keysym.sym == SDLK_DOWN)
            {
                world->vitesse -= 2;
            }
        }
    }
}


/**
 *  \brief programme principal qui implémente la boucle du jeu
 */


int main( int argc, char* args[] )
{
    SDL_Event event;
    world_t world;
    textures_t textures;
    SDL_Renderer *renderer;
    SDL_Window *window;

    //initialisation du jeu
    init(&window,&renderer,&textures,&world);
    
    while(!is_game_over(&world)){ //tant que le jeu n'est pas fini
        
        //gestion des évènements
        handle_events(&event,&world);
        
        //mise à jour des données liée à la physique du monde
        update_data(&world);
        
        //rafraichissement de l'écran
        refresh_graphics(renderer,&world,&textures);
        
        // pause de 10 ms pour controler la vitesse de rafraichissement
        pause(10);
    }
    
    //nettoyage final
    clean(window,renderer,&textures,&world);
    
    
    return 0;
}
