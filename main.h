#include <stdio.h>

#define RIVEARRIVEE 1
#define RIVEDEPART 0

#define CANNIBALE 1
#define MISSIONNAIRE 0

typedef struct{
    int cannibale;
    int missionnaire;
}rive;

void traverser(rive *riveDepart, rive *riveArrivee, int coteRive, int cOuM, int nombre){

    if(cOuM == MISSIONNAIRE){
        if(coteRive == RIVEDEPART){ 
            riveArrivee->missionnaire += nombre;
            riveDepart->missionnaire -= nombre;
        }
        else if(coteRive = RIVEARRIVEE){ 
            riveDepart->missionnaire += nombre;
            riveArrivee->missionnaire -= nombre;
        }
    } 
    else if(cOuM == CANNIBALE){
        if(coteRive == RIVEDEPART){ 
            riveArrivee->cannibale += nombre;
            riveDepart->cannibale -= nombre;
        }
        else if(coteRive = RIVEARRIVEE){
            riveDepart->cannibale += nombre;
            riveArrivee->cannibale -= nombre;
        }
    }
}

int gagneOuPerduOuRien(rive riveDepart, rive riveArrivee){
    // Victoire
    if(riveDepart.missionnaire == 0 && riveDepart.cannibale == 0 && riveArrivee.missionnaire == 3 && riveArrivee.cannibale == 3){
        gagner();
        return 1;
    }
    // Défaite (rive arrivée)
    else if(riveArrivee.missionnaire < riveArrivee.cannibale){
        perdu(RIVEARRIVEE);
        return 0;
    }
    // Défaite (rive départ)
    else if(riveDepart.missionnaire < riveDepart.cannibale){
        perdu(RIVEDEPART);
        return 0;
    }
    // Ni perdu ni gagner
    else {
        return -1;
    }
}

int missionnaireTraverser() {
    int valeur;
    printf("Combien de missionnaires voulez-vous faire traverser ?");
    scanf("%d", &valeur);
    // Condition
    while(valeur > 2){
        valeur = 0;
        printf("Combien de missionnaires voulez-vous faire traverser ?");
        scanf("%d", &valeur);
    }
    return valeur;
}

int cannibaleTraverser(int valeurMiss) {
    int valeur;
    printf("Combien de cannibale voulez-vous faire traverser ?");
    scanf("%d", &valeur);
    // Condition
    while(valeur > 2 && (valeurMiss + valeur) > 2){
        valeur = 0;
        printf("Combien de missionnaires voulez-vous faire traverser ?");
        scanf("%d", &valeur);
    }
    return valeur;
}

void afficherRive(rive riveDepart, rive riveArriver) {
    printf("rive de départ : %d missionnaire(s) et %d cannibale(s)", riveDepart.missionnaire, riveDepart.cannibale);
    printf("rive de d'arrivée : %d missionnaire(s) et %d cannibale(s)", riveArriver.missionnaire, riveArriver.cannibale);
}

void afficherTraverser(int missionnaireTraverser, int cannibaleTraverser) {
    printf("On fait traverser %d missionnaire(s) et %d cannibale(s)", missionnaireTraverser, cannibaleTraverser);
}

int gagner() {
    printf("Vous avez gagné la partie !");
    return 1;
}

int perdu(int rivePerdu) {
    if (rivePerdu == RIVEDEPART) printf("Les cannibale mangent les missionnaires sur la rive de départ !");
    else printf("Les cannibale mangent les missionnaires sur la rive d'arrivé !");

    printf("Vous avez perdu la partie.");
    return 0;
}

void afficherRiveRadeau(int coteRadeau){
    if(coteRadeau == RIVEDEPART) printf("La barque est sur la rive de départ \n");
    else printf("La barque est sur la rive d'arrivée");
}

int rienFaire(){
    return -1;
}