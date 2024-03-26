#define RIVEARRIVEE 1
#define RIVEDEPART 0

#define CANNIBALE 1
#define MISSIONNAIRE 0

typedef struct{
    int cannibales;
    int missionnaire;
}rive;

void traverser(rive riveDepart, rive riveArrivee, int coteRive, int cOuM, int nombre){

    if(cOuM == MISSIONNAIRE){
        if(coteRive == RIVEDEPART){ 
            riveArrivee.missionnaire += nombre;
            riveDepart.missionnaire -= nombre;
        }
        else if(coteRive = RIVEARRIVEE){ 
            riveDepart.missionnaire += nombre;
            riveArrivee.missionnaire -= nombre;
        }
    } 
    else if(cOuM == CANNIBALE){
        if(coteRive == RIVEDEPART){ 
            riveArrivee.cannibales += nombre;
            riveDepart.cannibales -= nombre;
        }
        else if(coteRive = RIVEARRIVEE){
            riveDepart.cannibales += nombre;
            riveArrivee.cannibales -= nombre;
        }
    }
}

void gagneOuPerdu(rive riveDepart, rive riveArrivee){
    // Victoire
    if(riveDepart.missionnaire == 0 && riveDepart.cannibales == 0 && riveArrivee.missionnaire == 3 && riveArrivee.cannibales == 3){
        gagner();
    }
    // Défaite (rive arrivée)
    else if(riveArrivee.missionnaire < riveArrivee.cannibales){
        perdu(RIVEARRIVEE);
    }
    // Défaite (rive départ)
    else if(riveDepart.missionnaire < riveDepart.cannibales){
        perdu(RIVEDEPART);
    }
}