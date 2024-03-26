#include <stdio.h>

#define CANNIBALE 1
#define MISSIONNAIRE 0

#define RIVEDEPART 0
#define RIVEARRIVE 1

typedef struct {
    int missionnaire;
    int cannibale;

} rive;

void afficherDebut() {
    printf("La barque est sur la rive de départ \n");
    printf("rive de départ : 3 missionnaire(s) et 3 cannibale(s) \n");
    printf("rive d’arrivée : 0 missionnaire(s) et 0 cannibale(s) \n");
}

int missionnaireTraverser() {
    int valeur;
    printf("Combien de missionnaires voulez-vous faire traverser ?");
    scanf("%d", &valeur);
    return valeur;
}

int missionnaireTraverser() {
    int valeur;
    printf("Combien de cannibales voulez-vous faire traverser ?");
    scanf("%d", &valeur);
    return valeur;
}

void afficherRive(rive riveDepart, rive riveArriver) {
    printf("rive de départ : %d missionnaire(s) et %d cannibale(s)", riveDepart.missionnaire, riveDepart.cannibale);
    printf("rive de d'arrivée : %d missionnaire(s) et %d cannibale(s)", riveArriver.missionnaire, riveArriver.cannibale);
}

void afficherTraverser(int missionnaireTraverser, int CannibaleTraverser) {
    printf("On fait traverser %d missionnaire(s) et %d cannibale(s)", missionnaireTraverser, CannibaleTraverser);
}

void gagner() {
    printf("Vous avez gagné la partie !");
}

void perdu(int rivePerdu) {
    if (rivePerdu == RIVEDEPART) printf("Les cannibales mangent les missionnaires sur la rive de départ !");
    else printf("Les cannibales mangent les missionnaires sur la rive d'arrivé !");
        
    printf("Vous avez perdu la partie.");
}
