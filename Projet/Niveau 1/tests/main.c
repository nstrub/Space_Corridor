/**
 * \file main.c
 * \brief Programme principal initial du niveau 1
 * \author Mathieu Constant
 * \version 1.0
 * \date 18 mars 2021
 */

#include "sdl2-light.h"


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
 * \brief La fonction nettoie les données du monde
 * \param *sprite l'adresse de l'enregistrement de type sprite_t
 * \param int x, int y les coordonnées du sprite
 * \param  int w, int h la largeur et hauteur du sprite
 */
void init_sprite(sprite_t *sprite, int x, int y, int w, int h)
{
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
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
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/

void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->vaisseau);
    clean_texture(textures->arrivee);
    clean_texture(textures->meteorite);
    /* A COMPLETER */
}



/**
 * \brief La fonction initialise les textures nécessaires à l'affichage graphique du jeu
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/

void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/space-background.bmp",renderer);
    textures->vaisseau = load_image( "ressources/spaceship.bmp", renderer);
    textures->arrivee = load_image( "ressources/finish_line.bmp", renderer);
    textures->meteorite = load_image( "ressources/meteorite.bmp", renderer);
    /* A COMPLETER */

    
}


/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param texture la texture liée au fond
*/

void apply_background(SDL_Renderer *renderer, SDL_Texture *texture){
    if(texture != NULL){
      apply_texture(texture, renderer, 0, 0);
    }
}

//Niveau 1 question 2.10
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite){
    // Va appliquer la texture "texture" associée au sprite "sprite" sur le renderer "renderer" à la position indiqué dans le sprite
    apply_texture(texture, renderer, sprite->x, sprite->y);
}



/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer le renderer lié à l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    
    //on vide le renderer
    clear_renderer(renderer);
    
    //application des textures dans le renderer
    apply_background(renderer, textures->background);

    apply_sprite(renderer, textures->vaisseau, &world->vaisseau);
    apply_sprite(renderer, textures->arrivee, &world->arrivee);

    //Mur de météorites
    for(int y = 0; y < 7; y++){
        for(int x = 0; x < 3; x ++){
            apply_texture(textures->meteorite, renderer, world->mur.x + x * METEORITE_SIZE , world->mur.y + y * METEORITE_SIZE);
        }
    }
    // on met à jour l'écran
    update_screen(renderer);

}



/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les textures
* \param world le monde
*/

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}



/**
 * \brief fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param world le monde
 */

void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_data(world);
    init_textures(*renderer,textures);
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
