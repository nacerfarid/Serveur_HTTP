#include "etape3.h"
// a garder !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


int cas_slash_etoile(char* chaine)
{
    char* chaine = i_req.c-> accept->c;
    char root= server_root;
    char site= i_req.c-> host->value
    char* chemin;
    char* nom;
    int taille_chemin;
    
    for (k=0; k< i_req->c-> accept->l; k++)     /* on sépare l'extension */
    {                                            /*            ^               */
        if (chaine[k]=='/')                   /*               |               */
        {                                            
            pos = k;                            
        }                                           
    }                                              
    for (k=0; k<=pos; k++){                      /*            |            */
        chemin[k]=chaine[k];                     /*            v            */
    }                                                /* on sépare l'extension */
    chemin[k]=0;                    
    chemin[pos]='.'
    concat_chaine(site, chemin);
    taille_chemin= i_req.c-> host->v_l + k      /* on lui donne une taille */
    
    
    Configs* config = config;           
    while (config-> next != NULL)            /* la ca commence vraiment */       
    {        
        k=0;
        while (k< taille_chemin && site[k]== config->path[k])     /* on cherche l'URL */
        { 
            k++;
        }
        if (k!= taille_chemin)        /* pas le bon URL -> */
        {
            config=config->next;        /* on change de fichier */
        }
        else            /* bon URL */
        {
            i_req.req->URL= config->path;
            i_req.req->
            return(0);
        
        }
    }
    
    
    config=config->next;            /* on test le dernier fichier */
    k=0;
    while (k< taille_chemin && site[k]== config->path[k])     /* on cherche l'URL */
    { 
        k++;
    }
    if (k!= taille_chemin)        /* pas le bon URL -> */
    {
        return(-1);        /* ca n'existe pas */
    }
    else            /* bon URL */
    {
        i_req.req->URL= config->path;
        return(0);
    }
