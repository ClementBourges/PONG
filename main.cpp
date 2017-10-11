#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif

int main ( int argc, char** argv )
{
    //Déclaration des variables
    int allerretour=1;
    int pause=1;
    int anglegauche=0;
    int droit=0;
    int tempsactuel=0, tempsprecedent=0;
    int vitesse=5, coup=0;
    SDL_Surface *ecran=NULL;
    SDL_Surface *barre1=NULL, *barre2=NULL;
    SDL_Surface *balle=NULL;
    SDL_Event event;
    //Création des surfaces
    barre1=SDL_CreateRGBSurface(SDL_HWSURFACE,20,150,32,0,0,0,0);
    barre2=SDL_CreateRGBSurface(SDL_HWSURFACE,20,150,32,0,0,0,0);
    balle=SDL_CreateRGBSurface(SDL_HWSURFACE, 20,20,32,0,0,0,0);
    //Configuration générale
    SDL_Init(SDL_INIT_VIDEO);
    ecran=SDL_SetVideoMode(0,0,0, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);
    SDL_EnableKeyRepeat (2,2);
    // Déclaration des positions
    SDL_Rect positionbarre1;
    positionbarre1.x=0;
    positionbarre1.y=250;
    SDL_Rect positionbarre2;
    positionbarre2.x=1260;
    positionbarre2.y=250;
    SDL_Rect positionballe;
    positionballe.y=310;
    positionballe.x=1280/2;
    // Configuration des sufraces
    SDL_BlitSurface(balle,NULL,ecran,&positionballe);
    SDL_WM_SetCaption( "||PONG||", NULL);// Nom de la fenêtre

    while(pause)
    {

    if ( coup == 2)
    {
        vitesse=10;
    }
    if (coup == 4)
    {
        vitesse=12;
    }
    if (coup == 8)
    {
        vitesse=14;
    }
    if (coup == 10)
    {
        vitesse=15;
    }
    if (coup == 14)
    {
        vitesse=18;
    }
    if (coup == 18)
    {
        vitesse=20;
    }
    if (coup==28)
    {
        vitesse=28;
    }
    /*if (coup==16)
    {
        vitesse=1260;
    }*/
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,0,0,0));
    SDL_FillRect(barre1,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDL_FillRect(barre2,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDL_FillRect(balle,NULL,SDL_MapRGB(ecran->format,255,255,255));

    SDL_BlitSurface(barre1,NULL,ecran,&positionbarre1);
    SDL_BlitSurface(barre2,NULL,ecran,&positionbarre2);
    SDL_BlitSurface(balle,NULL,ecran,&positionballe);
    SDL_Flip(ecran);
    tempsactuel=SDL_GetTicks();
    if (tempsactuel-tempsprecedent>5)
    {

        if(allerretour==0)
        {
            if(positionballe.x!=positionbarre2.x)
            {
                        if (anglegauche==0)
                        {
                        positionballe.x=positionballe.x+vitesse;
                        }
                        else if (anglegauche==1)
                        {
                        positionballe.x=positionballe.x+vitesse;
                        positionballe.y=positionballe.y+10;
                        }
                        else if (anglegauche==2)
                        {
                        positionballe.x=positionballe.x+vitesse;
                        positionballe.y=positionballe.y-10;
                        }
                        if ( positionballe.y==800)
                        {
                        anglegauche=2;
                        }
                        if (positionballe.y==0)
                        {
                        anglegauche=1;
                        }
                        }
                        else if(positionballe.x==positionbarre2.x && positionbarre2.y<=positionballe.y && positionballe.y<=positionbarre2.y+150)
                            {
                            allerretour=1;
                            }
                                if (positionballe.x==positionbarre2.x && positionbarre2.y>positionballe.y)
                                {
                                pause=0;
                                }
                                if (positionballe.x==positionbarre2.x && positionbarre2.y+150<positionballe.y)
                                {
                                pause=0;
                                }
                                    if (positionballe.x==positionbarre2.x && positionbarre2.y+50<=positionballe.y && positionbarre2.y+100>=positionballe.y)
                                    {
                                    droit=0;
                                    coup++;

                                    }

                                    else if (positionballe.x==positionbarre2.x && positionbarre2.y<=positionballe.y && positionbarre2.y+50>positionballe.y)
                                    {
                                    droit=1;
                                    coup++;
                                    }
                                    else if (positionballe.x==positionbarre2.x && positionbarre2.y+100<positionballe.y && positionbarre2.y+150>=positionballe.y)
                                    {
                                    droit=2;
                                    coup++;
                                    }
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,0,0,0));
    SDL_FillRect(barre1,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDL_FillRect(barre2,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDL_FillRect(balle,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDL_BlitSurface(barre1,NULL,ecran,&positionbarre1);
    SDL_BlitSurface(barre2,NULL,ecran,&positionbarre2);
    SDL_BlitSurface(balle,NULL,ecran,&positionballe);
    SDL_Flip(ecran);
            }
         else if (allerretour==1)
            {
                if(positionballe.x!=positionbarre1.x)
                {
                        if (droit==0)
                        {
                        positionballe.x=positionballe.x-vitesse;
                        }
                        if (droit==1)
                        {
                        positionballe.x=positionballe.x-vitesse;
                        positionballe.y=positionballe.y+10;
                        }
                        if (droit==2)
                        {
                        positionballe.x=positionballe.x-vitesse;
                        positionballe.y=positionballe.y-10;
                        }
                        if(positionballe.y==800)
                        {
                        droit=2;
                        }
                        if (positionballe.y==0)
                        {
                        droit=1;
                        }
                       // emplacement
                    }
                            if (positionballe.x==positionbarre1.x && positionbarre1.y<=positionballe.y && positionballe.y<=positionbarre1.y+150)
                            {
                            allerretour=0;
                            }
                            else if (positionballe.x==positionbarre1.x && positionbarre2.y+150>positionballe.y)
                            {
                            pause=0;
                            }
                            else if (positionballe.x==positionbarre1.x && positionbarre2.y<positionballe.y)
                            {
                            pause=0;
                            }

                                    if (positionballe.x==positionbarre1.x && positionbarre1.y+50<=positionballe.y && positionbarre1.y+100>=positionballe.y)
                                    {
                                    anglegauche=0;
                                    coup++;
                                    }
                                    else if (positionballe.x==positionbarre1.x && positionbarre1.y<=positionballe.y && positionbarre1.y+50>positionballe.y)
                                    {
                                    anglegauche=1;
                                    coup++;
                                    }

                                    else if (positionballe.x==positionbarre1.x && positionbarre1.y+100<positionballe.y && positionbarre1.y+150>=positionballe.y)
                                    {
                                    anglegauche=2;
                                    coup++;
                                    }
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,0,0,0));
    SDL_FillRect(barre1,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDL_FillRect(barre2,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDL_FillRect(balle,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDL_BlitSurface(barre1,NULL,ecran,&positionbarre1);
    SDL_BlitSurface(barre2,NULL,ecran,&positionbarre2);
    SDL_BlitSurface(balle,NULL,ecran,&positionballe);
    SDL_Flip(ecran);

                }
        }

    SDL_PollEvent(&event);// Attente d'un événement
    switch (event.type)
    {
        case SDL_QUIT:
            pause=0;
            break;
        case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                pause=0;
                break;
            }
    }
    SDL_PollEvent(&event);
    switch (event.type)
        {
            case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
                {
                case SDLK_a:
                if (positionbarre1.y<650)
                {
                SDL_EventState(SDLK_UP , SDL_IGNORE);
                SDL_EventState(SDLK_DOWN, SDL_IGNORE);
                positionbarre1.y=positionbarre1.y+10;
                }
                break;
                case SDLK_q:
                if(positionbarre1.y>0)
                {
                SDL_EventState(SDLK_UP , SDL_IGNORE);
                SDL_EventState(SDLK_DOWN, SDL_IGNORE);
                positionbarre1.y=positionbarre1.y-10;
                }
                break;
                case SDLK_UP:
                if(positionbarre2.y >0 )
                {
                positionbarre2.y=positionbarre2.y-10;
                break;
                }
                case SDLK_DOWN:
                if(positionbarre2.y<650)
                {
                positionbarre2.y=positionbarre2.y+10;
                }
                break;
                }
            }
        }
    SDL_FreeSurface(barre1);
    SDL_Quit();
    return 0;
}
