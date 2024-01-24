#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int valeur;
	int couleur;
	}Carte;
typedef struct{
    Carte main[40];
    int points;
    char Nom[20];
}Player;
int NumberOfCard(Carte T[]){
    int cmpt=0;
    while(T[cmpt].valeur!=15){
        cmpt++;
    }
    return cmpt;
}
void remplissage(Carte T[]){
	int i,j=0,k,c=0;
	for(i=12;i<15;i++){
		for(k=0;k<4;k++,j++){
			T[j].valeur=i;
			T[j].couleur=k;
		}
	}
	for(c=0;c<2;c++){
	for(i=0;i<12;i++){
		for(k=0;k<4;k++,j++){
			T[j].valeur=i;
			T[j].couleur=k;
	}
	}
}
}
void melanger(Carte *jeu,int nb){

  int i,n;
  Carte tmp;
  srand(time(NULL)); /* Initialise le generateur pseudo aleatoire */
  for (i=0;i<nb; i++)
  {
    n=rand()%nb;     /* n est un nombre pseudo aleatoire entre 0 et nb */
    tmp=jeu[i];
    jeu[i]=jeu[n];
    jeu[n]=tmp;
  }
}

void initialiser(Carte *T,int n){
   int i;
   for(i=0;i<n;i++){
    T[i].couleur=5;
    T[i].valeur=15;
   }
}
void distribuer(Carte *T,Carte *P,int *C,int n){ // n est le nombre des cates à distribuer
    int i=0,j;
   while(P[i].valeur!=15){i++;};
    for(j=0;j<n;j++,(*C)--){
        P[i++]=T[*C];
        initialiser(&T[*C],1);

    }
}
void ShowCard(Carte T){
    int i;
    if(T.valeur==12) {printf("%s","     Joker      ");return ;}
    if(T.valeur==13) {printf("%s","       +4       ");return ;}
    if(T.couleur==0){
        printf("%6s","Bleu");
        for(i=0;i<=8;i++){
            if(T.valeur==i) {printf("%10d",i+1); break;}}
        if(T.valeur==9) printf("%10s","'+2'");
        else if(T.valeur==10) printf("%10s","Invers");
        else if(T.valeur==11) printf("%10s","Passe tour");
        //else if(T.valeur==12) printf("%10s","Joker");
        //else if(T.valeur==13) printf("%10s","'+4'");
        else if(T.valeur==14) printf("%10s","0");
            }

     else if(T.couleur==1){
        printf("%6s","Rouge");
        for(i=0;i<=8;i++){
            if(T.valeur==i) {printf("%10d",i+1); break;}}
                if(T.valeur==9) printf("%10s","'+2'");
                else if(T.valeur==10) printf("%10s","Invers");
                else if(T.valeur==11) printf("%10s","Passe tour");
                //else if(T.valeur==12) printf("%10s","Joker");
                //else if(T.valeur==13) printf("%10s","'+4'");
                else if(T.valeur==14) printf("%10s","0");
            }
      else if(T.couleur==2){
        printf("%6s","Jaune");
        for(i=0;i<=8;i++){
            if(T.valeur==i) {printf("%10d",i+1); break;}}
                if(T.valeur==9) printf("%10s","'+2'");
                else if(T.valeur==10) printf("%10s","Invers");
                else if(T.valeur==11) printf("%10s","Passe tour");
                //else if(T.valeur==12) printf("%10s","Joker");
                //else if(T.valeur==13) printf("%10s","'+4'");
                else if(T.valeur==14) printf("%10s","0");
            }

      else if(T.couleur==3){
        printf("%6s","Vert");
         for(i=0;i<=8;i++){
            if(T.valeur==i) {printf("%10d",i+1); break;}}
                if(T.valeur==9) printf("%10s","'+2'");
                else if(T.valeur==10) printf("%10s","Invers");
                else if(T.valeur==11) printf("%10s","Passe tour");
                //else if(T.valeur==12) printf("%10s","Joker");
                //else if(T.valeur==13) printf("%10s","'+4'");
                else if(T.valeur==14) printf("%10s","0");
            }
        }
void Show_Hand(Player *P){
    int i;
    printf("+---+----------------+\n");
    printf("|%3s|%16s|\n","Num","La carte");
    printf("+---+----------------+\n");
    for(i=0;i<NumberOfCard(P->main);i++){
         printf("|%3d|",i+1);
         ShowCard(P->main[i]);
         printf("|\n");
         printf("+---+----------------+\n");
    }
}
void Show_Table(Carte T){
    printf("+****************+\n");
    printf("|%16s|\n","");
    printf("|%16s|\n","");
    printf("|%16s|\n","");
    printf("|%16s|\n","");
    printf("|%16s|\n","");
    printf("|");
    ShowCard(T);
    printf("|\n");
    printf("|%16s|\n","");
    printf("|%16s|\n","");
    printf("|%16s|\n","");
    printf("|%16s|\n","");
    printf("|%16s|\n","");
    printf("+****************+\n");
}
bool is_valid(Carte T,Carte M,int *Joker_color){
    if(M.valeur==13 || M.valeur==12) return true;
    if(*Joker_color==4 && (T.couleur==M.couleur || T.valeur==M.valeur)) return true;
    else if(M.couleur==*Joker_color) return true;
    else return false;
}
bool is_special(Carte T){
    int i;
    for(i=9;i<14;i++){
        if(T.valeur==i) return true;
    }
    return false;
}
void Apply_special(Player *P,Carte C,Carte *Deck,int *sens,int *Cmpt_Deck,int *Color_Joker){
    if(C.valeur==9) distribuer(Deck,(P->main),Cmpt_Deck,2);
    else if(C.valeur==10) (*sens)*=-1;
    else if(C.valeur==12){
        printf("Quel couleur voulez-vous ? (Entrez le numéro):\n");
        printf("1-Bleu\n2-Rouge\n3-Jaune\n4-Vert\n");
        scanf("%d",Color_Joker);
        (*Color_Joker)-=1;
    }
    else if(C.valeur==13){
        distribuer(Deck,(P->main),Cmpt_Deck,4);
        printf("Quel couleur voulez-vous ? (Entrez le numéro):\n");
        printf("1-Bleu\n2-Rouge\n3-Jaune\n4-Vert\n");
        scanf("%d",Color_Joker);
        (*Color_Joker)-=1;
    }
}
void Empiler(Carte T[],Carte *C){
   *C=T[NumberOfCard(T)-1];
   initialiser(&T[NumberOfCard(T)-1],1);
}
void reload_Deck(Carte Deck[],Carte Table[],int *Cmpt_Deck){
Carte Temp;
int i;
initialiser(Deck,108);
Temp=Table[NumberOfCard(Table)-1];
for(i=0;i<NumberOfCard(Table)-1;i++){
    Deck[i]=Table[i];
}
melanger(Deck,NumberOfCard(Table)-1);
initialiser(Table,108);
Table[0]=Temp;
*Cmpt_Deck=NumberOfCard(Deck);
}
