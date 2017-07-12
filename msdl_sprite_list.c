/*
** msdl_surface.c
** by bogard_t
*/

#include "msdl.h"

static void msdl_init_list(t_msdl *sdl, const char *filePath)
{
    t_node *new;

    new = malloc(sizeof(*new));
    new->surface = IMG_Load(filePath);
    new->next = NULL;
    new->prev = NULL;
    sdl->first = new;
    new->filePath = strdup(filePath);
    sdl->nb_node++;
}

void msdl_add_list(t_msdl *sdl, const char *filePath)
{
    t_node *new;
    t_node *current;

    if (sdl->nb_node == 0)
        msdl_init_list(sdl, filePath);
    else
    {
        new = malloc(sizeof(*new));
        new->surface = IMG_Load(filePath);
        for (current = sdl->first; current->next; current = current->next);
        new->next = NULL;
        new->prev = current;
        current->next = new;
        new->filePath = strdup(filePath);
        sdl->nb_node++;
    }
}
