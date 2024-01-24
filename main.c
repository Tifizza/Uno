#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include "UnoFunc.h"
#include "IAUno.h"

int main(){
    Carte Deck[108];
    Carte Table[108];
    Player P1,P2,P3;
    int Color_Joker=4;
    int Cmpt_deck=107,tours=0,sens=1,choosen_card,winner=0,cmpt_tours=0;
    char c;
    //Saissie de donnée du joueur:
printf("           _____                    _____                   _______         \n");
printf("           /\\    \\                  /\\    \\                 /::\\    \\        \n");
printf("          /::\\____\\                /::\\____\\               /::::\\    \\       \n");
printf("         /:::/    /               /::::|   |              /::::::\\    \\      \n");
printf("        /:::/    /               /:::::|   |             /::::::::\\    \\     \n");
printf("       /:::/    /               /::::::|   |            /:::/~~\\:::\\    \\    \n");
printf("      /:::/    /               /:::/|::|   |           /:::/    \\:::\\    \\   \n");
printf("     /:::/    /               /:::/ |::|   |          /:::/    / \\:::\\    \\  \n");
printf("    /:::/    /      _____    /:::/  |::|   | _____   /:::/____/   \\:::\\____\\ \n");
printf("   /:::/____/      /\\    \\  /:::/   |::|   |/\\    \\ |:::|    |     |:::|    |\n");
printf("  |:::|    /      /::\\____\\/:: /    |::|   /::\\____\\|:::|____|     |:::|    |\n");
printf("  |:::|____\\     /:::/    /\\::/    /|::|  /:::/    / \\:::\\    \\   /:::/    / \n");
printf("   \\:::\\    \\   /:::/    /  \\/____/ |::| /:::/    /   \\:::\\    \\ /:::/    /  \n");
printf("    \\:::\\    \\ /:::/    /           |::|/:::/    /     \\:::\\    /:::/    /  \n");
printf("     \\:::\\    /:::/    /            |::::::/    /       \\:::\\__/:::/    /    \n");
printf("      \\:::\\__/:::/    /             |:::::/    /         \\::::::::/    /     \n");
printf("       \\::::::::/    /              |::::/    /           \\::::::/    /      \n");
printf("        \\::::::/    /               /:::/    /             \\::::/    /       \n");
printf("         \\::::/    /               /:::/    /               \\::/____/        \n");
printf("          \\::/____/                \\::/    /                 ~~              \n");
printf("           ~~                       \\/____/                                  \n\n\n");

printf("                         Entrez votre nom:\t");
    gets(P1.Nom);
    fflush(stdin);
    Start:;
    system("cls");
    //Remplissage du deck
    remplissage(Deck);
    //mélanger le deck
    melanger(Deck,108);
    //initialiser les mains
    initialiser((P1.main),40);
    initialiser((P2.main),40);
    initialiser((P3.main),40);
    initialiser(Table,108);
    //distribuer les cartes
    distribuer(Deck,(P1.main),&Cmpt_deck,7);
    distribuer(Deck,(P2.main),&Cmpt_deck,7);
    distribuer(Deck,(P3.main),&Cmpt_deck,7);
    distribuer(Deck,Table,&Cmpt_deck,1);

   Player1: ;
        if(Cmpt_deck<0) reload_Deck(Deck,Table,&Cmpt_deck);
        tours=1;
        system("cls");
        printf("**************** Le tour du %s ****************\n",P1.Nom);
        printf("La Carte sur la table:\n");
        Show_Table(Table[NumberOfCard(Table)-1]);
        if(Color_Joker!=4){
            switch(Color_Joker){
                case 0: {printf("$$$$$$$$ Vous devez jouer la couleur BLEUE! $$$$$$$$\n");break;}
                case 1: {printf("$$$$$$$$ Vous devez jouer la couleur ROUGE! $$$$$$$$\n");break;}
                case 2: {printf("$$$$$$$$ Vous devez jouer la couleur JAUNE! $$$$$$$$\n");break;}
                case 3: {printf("$$$$$$$$ Vous devez jouer la couleur VERTE! $$$$$$$$\n");break;}
            }
        }
        if(cmpt_tours==0){
            if(is_special(Table[NumberOfCard(Table)-1])){
                if(Table[NumberOfCard(Table)-1].valeur==11) goto Player3;
                else if(Table[NumberOfCard(Table)-1].valeur==13) goto There;
                else Apply_special(&P1,Table[NumberOfCard(Table)-1],Deck,&sens,&Cmpt_deck,&Color_Joker);
            }
        }

        There:;
        printf("La main de %s:\n",P1.Nom);
        Show_Hand(&P1);
        printf("Entrez le numero de la carte que vous voulez jouer ou entrez 0 pour piocher:\t");
        scanf("%d",&choosen_card);
        if(choosen_card!=0){
            while(!is_valid(Table[NumberOfCard(Table)-1],P1.main[choosen_card-1],&Color_Joker) && choosen_card!=0){
                printf("Vous ne pouvez pas jouer cette carte ! ");
                system("pause");
                system("cls");
                printf("**************** Le tour du %s ****************\n",P1.Nom);
                printf("La Carte sur la table:\n");
                Show_Table(Table[NumberOfCard(Table)-1]);
                printf("La main de %s:\n",P1.Nom);
                Show_Hand(&P1);
                printf("Entrez le numero de la carte que vous voulez jouer ou entrez 0 pour piocher:\t");
                scanf("%d",&choosen_card);
            }
        }
        system("cls");
        if(choosen_card==0) distribuer(Deck,(P1.main),&Cmpt_deck,1);
        else{
            Color_Joker=4;
            if(is_special(P1.main[choosen_card-1])){
                if(P1.main[choosen_card-1].valeur==11) {
                    if(sens>0){
                        Table[NumberOfCard(Table)]=P1.main[choosen_card-1];
                        if(NumberOfCard(P1.main)==1 && choosen_card==1) initialiser(P1.main,1);
                        else Empiler(P1.main,&(P1.main[choosen_card-1]));
                        if(NumberOfCard(P1.main)==0){winner=1;goto Exit;}
                        if(tours==1) goto Player3;
                        else if(tours==2) goto Player1;
                        else goto Player2;
                        }
                    else{
                        Table[NumberOfCard(Table)]=P1.main[choosen_card-1];
                        if(NumberOfCard(P1.main)==1 && choosen_card==1) initialiser(P1.main,1);
                        else Empiler(P1.main,&(P1.main[choosen_card-1]));
                        if(NumberOfCard(P1.main)==0){winner=1;goto Exit;}
                        if(tours==1) goto Player2;
                        else if(tours==2) goto Player3;
                        else goto Player1;
                        }
                    }
                    else if(P1.main[choosen_card-1].valeur==13) {
                        Table[NumberOfCard(Table)]=P1.main[choosen_card-1];
                        if(NumberOfCard(P1.main)==1 && choosen_card==1) initialiser(P1.main,1);
                        else Empiler(P1.main,&(P1.main[choosen_card-1]));
                        printf("Quel couleur voulez-vous ? (Entrez le numéro):\n");
                        printf("1-Bleu\n2-Rouge\n3-Jaune\n4-Vert\n");
                        scanf("%d",&Color_Joker);
                        Color_Joker-=1;
                        if(sens>0){
                            distribuer(Deck,(P2.main),&Cmpt_deck,4);
                            goto Player3;
                        }
                        else{
                            distribuer(Deck,(P3.main),&Cmpt_deck,4);
                            goto Player2;
                        }
                    }
                    else{
                        if(sens>0)
                            Apply_special(&P2,P1.main[choosen_card-1],Deck,&sens,&Cmpt_deck,&Color_Joker);

                        else
                            Apply_special(&P3,P1.main[choosen_card-1],Deck,&sens,&Cmpt_deck,&Color_Joker);

                    }
                }
            Table[NumberOfCard(Table)]=P1.main[choosen_card-1];
            if(NumberOfCard(P1.main)==1 && choosen_card==1) initialiser(P1.main,1);
            else Empiler(P1.main,&(P1.main[choosen_card-1]));
        }
        if(NumberOfCard(P1.main)==0){winner=1;goto Exit;}
        if(sens>0)
            goto Player2;
        else goto Player3;


Player2: ;
    cmpt_tours++;
    if(Cmpt_deck<0) reload_Deck(Deck,Table,&Cmpt_deck);
    system("cls");
    printf("**************** Le tour du %s (%d Cartes dans la main)****************\n","L'ordinateur 1",NumberOfCard(P2.main));
    Show_Table(Table[NumberOfCard(Table)-1]);
    Sleep(2000);
    tours=2;
    choosen_card=chercher_occurence(Table[NumberOfCard(Table)-1],P2.main,&Color_Joker);
    if(choosen_card!=-1){
            Color_Joker=4;
            choosen_card+=1;
            if(is_special(P2.main[choosen_card-1])){
                if(P2.main[choosen_card-1].valeur==11) {
                    if(sens>0){
                        Table[NumberOfCard(Table)]=P2.main[choosen_card-1];
                        if(NumberOfCard(P2.main)==1 && choosen_card==0) initialiser(P2.main,1);
                        else Empiler(P2.main,&(P2.main[choosen_card-1]));
                        system("cls");
                        printf("**************** Le tour du %s (%d Cartes dans la main)****************\n","L'ordinateur 1",NumberOfCard(P2.main));
                        Show_Table(Table[NumberOfCard(Table)-1]);
                        Sleep(2000);
                        if(NumberOfCard(P2.main)==0){winner=2;goto Exit;}
                        if(tours==1) goto Player3;
                        else if(tours==2) goto Player1;
                        else goto Player2;
                        }
                    else{
                        Table[NumberOfCard(Table)]=P2.main[choosen_card-1];
                        if(NumberOfCard(P2.main)==1 && choosen_card==0) initialiser(P1.main,1);
                        else Empiler(P2.main,&(P2.main[choosen_card-1]));
                        system("cls");
                        printf("**************** Le tour du %s (%d Cartes dans la main)****************\n","L'ordinateur 1",NumberOfCard(P2.main));
                        Show_Table(Table[NumberOfCard(Table)-1]);
                        Sleep(2000);
                        if(NumberOfCard(P2.main)==0){winner=2;goto Exit;}
                        if(tours==1) goto Player2;
                        else if(tours==2) goto Player3;
                        else goto Player1;
                        }
                    }
                    else if(P2.main[choosen_card-1].valeur==13){
                        Table[NumberOfCard(Table)]=P2.main[choosen_card-1];
                        if(NumberOfCard(P2.main)==1 && choosen_card==0) initialiser(P2.main,1);
                        else Empiler(P2.main,&(P2.main[choosen_card-1]));
                        srand(time(NULL));Color_Joker=rand()%4;
                        if(sens>0){
                            distribuer(Deck,(P3.main),&Cmpt_deck,4);
                            goto Player1;
                        }
                        else{
                            distribuer(Deck,(P1.main),&Cmpt_deck,4);
                            goto Player3;
                        }
                    }
                    else{
                        if(sens>0){
                        Apply_special_IA(&P3,P2.main[choosen_card-1],Deck,&sens,&Cmpt_deck,&Color_Joker);
                    }
                    else{
                        Apply_special_IA(&P1,P2.main[choosen_card-1],Deck,&sens,&Cmpt_deck,&Color_Joker);
                    }
            }
            }
        Table[NumberOfCard(Table)]=P2.main[choosen_card-1];
        system("cls");
        printf("**************** Le tour du %s (%d Cartes dans la main)****************\n","L'ordinateur 1",NumberOfCard(P2.main));
        Show_Table(Table[NumberOfCard(Table)-1]);
        Sleep(2000);
        if(NumberOfCard(P2.main)==1 && choosen_card==0) initialiser(P2.main,1);
        else Empiler(P2.main,&(P2.main[choosen_card-1]));
    }
    else distribuer(Deck,(P2.main),&Cmpt_deck,1);

    if(NumberOfCard(P2.main)==0){winner=2;goto Exit;}
    if(sens>0)goto Player3;
    else goto Player1;


Player3: ;
    cmpt_tours++;
    if(Cmpt_deck<0) reload_Deck(Deck,Table,&Cmpt_deck);
    tours=3;
    system("cls");
    printf("**************** Le tour du %s (%d Cartes dans la main)****************\n","L'ordinateur 2",NumberOfCard(P3.main));
    Show_Table(Table[NumberOfCard(Table)-1]);
    Sleep(2000);
    tours=3;
    choosen_card=chercher_occurence(Table[NumberOfCard(Table)-1],P3.main,&Color_Joker);
    if(choosen_card!=-1){
            Color_Joker=4;
            choosen_card+=1;
            if(is_special(P3.main[choosen_card-1])){
                if(P2.main[choosen_card-1].valeur==11) {
                    if(sens>0){
                        Table[NumberOfCard(Table)]=P3.main[choosen_card-1];
                        if(NumberOfCard(P3.main)==1 && choosen_card==0) initialiser(P3.main,1);
                        else Empiler(P3.main,&(P3.main[choosen_card-1]));
                        system("cls");
                        printf("**************** Le tour du %s (%d Cartes dans la main)****************\n","L'ordinateur 2",NumberOfCard(P3.main));
                        Show_Table(Table[NumberOfCard(Table)-1]);
                        Sleep(2000);
                        if(NumberOfCard(P3.main)==0){winner=3;goto Exit;}
                        if(tours==1) goto Player3;
                        else if(tours==2) goto Player1;
                        else goto Player2;
                        }
                    else{
                        Table[NumberOfCard(Table)]=P3.main[choosen_card-1];
                        if(NumberOfCard(P3.main)==1 && choosen_card==0) initialiser(P3.main,1);
                        else Empiler(P3.main,&(P3.main[choosen_card-1]));
                        system("cls");
                        printf("**************** Le tour du %s (%d Cartes dans la main)****************\n","L'ordinateur 2",NumberOfCard(P3.main));
                        Show_Table(Table[NumberOfCard(Table)-1]);
                        Sleep(2000);
                        if(NumberOfCard(P3.main)==0){winner=3;goto Exit;}
                        if(tours==1) goto Player2;
                        else if(tours==2) goto Player3;
                        else goto Player1;
                        }
                    }
                    else if(P3.main[choosen_card-1].valeur==13){
                        Table[NumberOfCard(Table)]=P3.main[choosen_card-1];
                        if(NumberOfCard(P3.main)==1 && choosen_card==0) initialiser(P3.main,1);
                        else Empiler(P3.main,&(P3.main[choosen_card-1]));
                        srand(time(NULL));Color_Joker=rand()%4;
                        if(sens>0){
                            distribuer(Deck,(P1.main),&Cmpt_deck,4);
                            goto Player2;
                        }
                        else{
                            distribuer(Deck,(P2.main),&Cmpt_deck,4);
                            goto Player1;
                        }
                    }
                    else{
                        if(sens>0)
                            Apply_special_IA(&P1,P3.main[choosen_card-1],Deck,&sens,&Cmpt_deck,&Color_Joker);
                        else
                            Apply_special_IA(&P2,P3.main[choosen_card-1],Deck,&sens,&Cmpt_deck,&Color_Joker);

            }
            }
        Table[NumberOfCard(Table)]=P3.main[choosen_card-1];
        system("cls");
        printf("**************** Le tour du %s (%d Cartes dans la main)****************\n","L'ordinateur 2",NumberOfCard(P3.main));
        Show_Table(Table[NumberOfCard(Table)-1]);
        Sleep(2000);
        if(NumberOfCard(P3.main)==1 && choosen_card==0) initialiser(P3.main,1);
        else Empiler(P3.main,&(P3.main[choosen_card-1]));
    }
    else distribuer(Deck,(P3.main),&Cmpt_deck,1);

    if(NumberOfCard(P3.main)==0){winner=3;goto Exit;}
    if(sens>0)goto Player1;
    else goto Player2;


Exit: ;
system("cls");
printf("Le gangnant est :\t");
switch(winner){
    case 1:{puts(P1.Nom);break;}
    case 2:{printf("Ordinateur 1");break;}
    case 3:{printf("Ordinteur 2");break;}
}
fflush(stdin);
printf("\nVoulez vous rejouer O/N ?    ");
scanf("%c",&c);
c=toupper(c);
while(c!='O' || c!='N'){
    system("cls");
    printf("Tapez O pour oui et N pour non:\t");
    scanf("%c",&c);
    c=toupper(c);
}
if(c=='O') goto Start;
system("cls");
printf("Merci %s ! Aurevoir   :)",P1.Nom);
return 0;
}
