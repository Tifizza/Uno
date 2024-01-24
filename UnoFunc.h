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
void remplissage(Carte*);
int NumberOfCard(Carte*);
void remplissage(Carte*);
void melanger(Carte *jeu,int nb);
void initialiser(Carte *T,int n);
void distribuer(Carte*,Carte*,int*,int);
void ShowCard(Carte);
void Show_Hand(Player *P);
void Show_Table(Carte);
bool is_valid(Carte T,Carte M,int *Joker_color);
bool is_special(Carte);
void Apply_special(Player *P,Carte C,Carte *Deck,int *sens,int *Cmpt_Deck,int *Color_Joker);
void Empiler(Carte T[],Carte *C);
void reload_Deck(Carte Deck[],Carte Table[],int *Cmpt_Deck);
