#include <iostream>
#include <string.h>
using namespace std;

const int TG=4;

void init(char G[TG][TG][100])
{
    for (int i=0;i<TG;i++)
    {
        for (int j=0;j<TG;j++)
        {
            strcpy(G[i][j],"*");
        }
    }
}

void remplir_grille(char G[TG][TG][100])
{
    int nb,i,l,c;
    char animal[100];
    for(nb=1;nb<=(TG*TG)/2;nb++)
    {
        cout<< "Animal " << nb << " ?";
        cin>>animal;
        for(i=0;i<2;i++)
        {
            do{
                l=rand()%TG;
                c=rand()%TG;
            }while(strcmp("*",G[l][c])!=0);
            strcpy(G[l][c],animal);
        }
    }
}

void affiche_grille(char G[TG][TG][100],char S[TG][TG][100],int l1,int c1,int l2,int c2)
{
    for(int i=0;i<TG;i++)
    {
        for(int j=0;j<TG;j++)
        {
            if((i==(l1-1))&&(j==(c1-1))||(i==(l2-1))&&(j==(c2-1)))
                cout<<S[i][j]<<"|";
            else
                cout<<G[i][j]<<"|";
        }
        cout<<endl;
    }
}

void choix_case(char G[TG][TG][100], char S[TG][TG][100], int&l1,int&l2,int&c1,int&c2)
{
    affiche_grille(G,S,l1,c1,l2,c2);
    do{
        cout<<"Case 1 : ligne ?";
        cin>>l1;
        cout<<"Case 1 : colonne ?";
        cin>>c1;
        affiche_grille(G,S,l1,c1,l2,c2);
        cout<<"Case 2 : ligne ?";
        cin>>l2;
        cout<<"Case 2 : colonne ?";
        cin>>c2;
    }while((l1>4)||(l1<1)||(c1>4)||(c1<1)||  (l2>4)||(l2<1)||(c2>4)||(c2<1)   ||((l1==l2)&&(c1==c2))    ||(strcmp(G[l1-1][c1-1],"*")!=0)   ||(strcmp(G[l2-1][c2-1],"*")!=0));
    affiche_grille(G,S,l1,c1,l2,c2);
}


int verif(char G[TG][TG][100],char S[TG][TG][100],int l1,int l2,int c1,int c2)
{
    if(strcmp(S[l1-1][c1-1],S[l2-1][c2-1])==0)
    {
        strcpy(G[l1-1][c1-1],S[l1-1][c1-1]);
        strcpy(G[l2-1][c2-1],S[l2-1][c2-1]);
        return 0;
    }
    else
        return 1;
}

int main()
{
    char Grille[TG][TG][100];
    char Solution[TG][TG][100];
    char Joueur[10];
    int ScoreJ1,ScoreJ2,nb_paires,x;
    int lig1,lig2,col1,col2;
    strcpy(Joueur,"Joueur1");
    ScoreJ1=0,ScoreJ2=0;
    nb_paires=(TG*TG)/2;
    cout << "***Bienvenue dans le jeu Memory***" << endl;
    cout << "Rentrez 8 animaux differents pour commencer :" << endl;
    init(Grille);
    init(Solution);
    remplir_grille(Solution);
    while(ScoreJ1+ScoreJ2!=nb_paires)
    {
        cout<<"Joueur="<<Joueur<<endl;
        choix_case(Grille,Solution,lig1,lig2,col1,col2);
        x = verif(Grille,Solution,lig1,lig2,col1,col2);
        if(strcmp(Joueur,"Joueur1")==0)
        {
            if(x==0)
            {
                ScoreJ1++;
            }
            strcpy(Joueur,"Joueur2");
        }
        else
        {
            if(x==0)
            {
                ScoreJ2++;
            }
            strcpy(Joueur,"Joueur1");
        }
    }
    if(ScoreJ1>ScoreJ2)
    {
        cout<<"Gagnant Joueur 1 avec "<<ScoreJ1<<" paires";
    }
    else if(ScoreJ2>ScoreJ1)
    {
        cout<<"gagnant Joueur 2 avec "<<ScoreJ2<<" paires";
    }
        else
            cout<<"Egalite";
    return 0;
}
