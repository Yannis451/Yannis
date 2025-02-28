//constantes du jeu
#define TAILLE 8 // taille du damier(8*8)
#define TAILLE_CASE 80 // Taille d'une case en pixels
#define LARGEUR_FENETRE (TAILLE*TAILLE_CASE)
#define Hauteur_FENETRE (TAILLLE*TAILLE_CASE)
//Définition des pièces
#define VIDE 0
#define PION_BLANC 1
#define PION_NOIR 2
#define DAME_BLANCHE 3
#define DAME_NOIRE 4
// structure pour représenter une position sur le damier
typedef struct{
    int ligne;
    int colonne;
} Position;
//structure pour représenter un mouvement
typedef struct{
  Position début;
  Position fin;
} Mouvement;
//structure pour le jeu
typedef struct{
    int plateau[TAILLE][TAILLE];//Représentation du plateau de jeu
    int joueurActuel;       //1 pour blanc,2 pour noir
    bool partie Terminee;    //Indique si la partie est terminée
    Position pieceSel;      //Position de la pièce sélectionnée (-1;-1 si aucune)
} JeuDeDames;
//Structure pour les ressources SDL
typedef struc{
    SDL_Window*fenetre;     //Fenetre principale
    SDL_Renderer*rendu;     //renderer pour dessiner
    TTF_font*police;        //police pour le texte
    SDL_Texture*texturePionBlanc;
    SDL_Texture*texturePionNoir;
    SDL_Texture*textureDameBlanc;
    SDL_Texture*textureDameNoir;
} RessourcesSDL;
void initialiserJeu(JeuDeDames*Jeu){
    //Initialiser le plateau avec des cases vides 
    for(int i=0; i<TAILLE; i++){
        for(int j=0; j<TAILLE; j++){
            jeu->plateau[i][j]=VIDE;
        }
    }
//Placer les pions noirs (en haut)
for(int i=0; i<3; i++){
    for(int j=0; j<TAILLE;j++){
        if((i+j)%2==1){ //cases noires uniquement
            jeu->plateau[i][j]=PION_NOIR;
        }
    }
}
//Placer les pions blancs (en bas)
 for (i = TAILLE i < TAILLE-3; i++){
 (int i=TAILLE-3; i<TAILLE; i++){
    for(int j=0; j<TAILLE; j++){
        if((i+j)%2==1){//Cases noires uniquement
            jeu->plateau[i][j]=PION_BLANC;
        }
    }
}
 //Blanc commence
 jeu->joueurActuel=1;
 jeu->partieTerminée=false;
}
bool initialiserSDL(RessourcesSDL*res){
    //Initialiser SDL
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        printf("Erreur lors de l'initialisation de SDL:%s\n",SDL_GetError());
        return false;
    } 
//initialiser SDL_ttf pour le texte 
if(TTF_Init()<0){
    printf("Erreur lord de l'initialisation de SDL_ttf:%s\n", TTF_GetError());
    SDL_Quit();
    return false;
}

//créer la fentre principale
res->fenetre=SDL_CreateWindow("jeu de Dames",
                 SDL_WindowPOS_UNDEFINED,
                 SDL_WindowPOS_UNDEFINED,
                 LARGEUR_FENETRE,
                 HAUTEUR_FENETRE,
                 SDL_Window_SHOWN)
//Créer le renderer pour dessiner
res->fenetre=SDL_CreateRenderer(res->fenetre,-1,
SDL_RENDERER_ACCELERATED);

//charger la police pour le texte
res->police=TTF_OpenFont("arial.ttf", 24);

//créer les textures pour les pions et les dames
//[Code pour créer les textures des pions et dames ici]

return true;
}

//void dessinerPlateau(RessourcesSDL*res,JeuDeDames*jeu){
//Effacer l'écran avec une couleur de fond
SDL_SetRenderDrawColor(res->rendu,150,100,50,255);//Couleur bois clair
SDL_RenderClear(res->rendu);

//Dessiner les cases du damier (alternance des cases claires et sombres)
for(int i=0; i<TAILLE; i++){
 for(int j=0; j<TAILLE; j++){
    SDL_Rect rect={j*TAILLE_CASE, i*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE};
    if((i+J)%2==0){
        //Case blanche
        SDL_SetRenderDrawColor(res->rendu,240,217,181,255);//Beige clair
    }else{
        //Case noire
        SDL_SetRenderDrawColors(res->rendu,100,65,23,255);//marron foncé
    }
    SDL_RenderFillRect(res->rendu,&rect);

    //Mettre en évidence la case sélectionnée
    if(jeu->pieceSel.ligne==i && jeu->pieceSel.colonne==J){
        SDL_SetRenderDrawColors(res->rendu 0,255,0,100);// vert transparent 
        SDL_RenderFillRect(res->rendu,&rect);
    }
    //Dessiner les pièces  
    if(jeu->plateau[i][j]!=VIDE){
        SDL_Texture*texture=NULL;
        switch(jeu->plateau[i][j]){
            case PION_BLANC:
             texture=res->texturePionBlanc;
            break;
            case PION_NOIR:
             texture=res->texturePionNoir; 
            case DAME_BLANCHE:
             texture=res->textureDameNoir;
             break;
            case DAME_NOIRE:
             texture=res->textureDameNoir;
             break;
        }
        if(texture){
            SDL_Rect desRect={
                j*TAILLE_CASE+10,
                i*TAILLE_CASE+10,
                TAILLE_CASE-20,
                TAILLE_CASE-20,
            };
            SDL_RenderCopy(res->rendu,texture,NULL,&destRect);
        }
    }
 }
}

//Afficher le joueur actuel 
if(res->police){
    SDL_Color couleur={255;255;255;255};
    char texte[50];
    sprint(texte,"Joueur:%s",(jeu->joueurActuel==1)?"Blanc":"Noir");
    SDL_Surface*surface=TTF_RenderText_Solid(res->)
}
    
            




          
       
    

