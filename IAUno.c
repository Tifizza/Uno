#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "UnoFunc.h"

int chercher_occurence(Carte T,Carte P[],int *Color_Joker){
    int i;
    for(i=0;i<NumberOfCard(P);i++)
    if(is_valid(T,P[i],Color_Joker)){
            return i;
    }
    return -1;
}
void Apply_special_IA(Player *P,Carte C,Carte *Deck,int *sens,int *Cmpt_Deck,int *Color_Joker){
    if(C.valeur==9) distribuer(Deck,&(P->main),Cmpt_Deck,2);
    else if(C.valeur==10) (*sens)*=-1;
    else if(C.valeur==12){ srand(time(NULL));*Color_Joker=rand()%4;}
    else if(C.valeur==13) {
        distribuer(Deck,&(P->main),Cmpt_Deck,4);
        srand(time(NULL));*Color_Joker=rand()%4;
    }

}

