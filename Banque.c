#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
#-------------------------------------------------------------------------------
# Code beginner
# Name:        Petite_banque
# Purpose:     Transaction Bancaire
#
# Author:      Petit-Homme Ben-Jacques
# E-Mail:      pbenjacques@gmail.com
#
# Created:     17-06-2017
# Copyright:   (c) Benito 2017
# Licence:     <your licence>
#-------------------------------------------------------------------------------

*/

//Declaration des Differentes Variables
typedef struct date {
  int jour;
  int mois;
  int annee;
} DATE;

struct Client
{
    int Numero;
    char Nom[100];
    char Prenom[100];
    char Adresse[100];
    char Telephone[100];
    char Mail[100];
    char CarteCredit[100];
    double DP,LC,DT,MN,Penalite,I,PM,Achat;
};
struct Client cli;

struct User
{
    int Numero;
    char Nomc[100];
    char Nom[100];
    char Telephone[100];
    char Mail[100];
    char Password[100];
    char Eta;
    DATE date;
};
struct User use,clu;
void getDate(DATE *d){
  time_t nsec;
  struct tm *temps;
  nsec = time(NULL);
  temps = localtime(&nsec);
  d->jour = temps->tm_mday;
  d->mois = temps->tm_mon + 1;
  d->annee = temps->tm_year + 1900;
}
//Exister
int Exist(int code)
{
    FILE *f;
    f=fopen("client.txt","r");
    do
    {
        fscanf(f,"\n%d  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf\n",&cli.Numero,&cli.Nom,&cli.Prenom,&cli.Adresse,&cli.Telephone,&cli.Mail,&cli.CarteCredit,&cli.LC,&cli.DP,&cli.DT,&cli.MN,&cli.Penalite,&cli.I,&cli.PM,&cli.Achat);
        fflush(stdin);
        if(cli.Numero==code)
        {
            fclose(f);
            return 1;
        }
    }while(!feof(f));
    fclose(f);
    return -1;
}

//Existuser
int ExistUser(int code)
{
    FILE *f=NULL;
    f=fopen("user.txt","r+");
    do
    {
       fscanf(f,"\n%d  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%c  ;%d-%d-%d\n",&use.Numero,&use.Nomc,&use.Nom,&use.Telephone,&use.Mail,&use.Password,&use.Eta,&use.date.jour,&use.date.mois,&use.date.annee);
        fflush(stdin);
        if(use.Numero==code)
        {
            fclose(f);
            return 1;
        }
    }while(!feof(f));
    fclose(f);
    return -1;
}

//Creation User
void AjouterUser()
{
    FILE *f;
    int numero;
   f=fopen("user.txt","a");
   printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =           Creation Compte Utilisateur      =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
    printf("\t\tL'Id Du Compte:");
    scanf("%d",&numero);
    fflush(stdin);
    while(ExistUser(numero)==1)
    {
        printf("\n\t\tCe numero Existe deja\n");
    printf("\n\t\tEntrer l'Id Du Nouveau Compte:");
        scanf("%d",&numero);
    }
    use.Numero=numero;
        printf("\n\t\tLe Nom Du Compte:");
        gets(use.Nomc);
         use.Eta= 'A';
        printf("\n\t\tLe Nom appartenant Le Compte:");
        gets(use.Nom);
        fflush(stdin);
        printf("\n\t\tTelephone Associe A Ce Compte:");
   gets(use.Telephone);
       fflush(stdin);
        printf("\n\t\tEmail Associe A Ce Compte:");
   gets(use.Mail);
       fflush(stdin);
       printf("\n\t\tMot-De-Passe:");
   gets(use.Password);
       fflush(stdin);
    getDate(&use.date);
    fprintf(f,"\n%d  ;%s  ;%s  ;%s  ;%s  ;%s  ;%c  ;%d-%d-%d\n",use.Numero,use.Nomc,use.Nom,use.Telephone,use.Mail,use.Password,use.Eta,use.date.jour,
	   use.date.mois, use.date.annee);
    fclose(f);
}



//Listage User
void AfficherUser()
{
    FILE *f,*ft; int i=1;

    f=fopen("user.txt","r");
    printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =               Listage Des Utilisateurs     =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
    do
    {
       fscanf(f,"\n%d  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%c  ;%d-%d-%d\n",&clu.Numero,&clu.Nomc,&clu.Nom,&clu.Telephone,&clu.Mail,&clu.Password,&clu.Eta,&clu.date.jour,&clu.date.mois,&clu.date.annee);
            fflush(stdin);
           printf("\t\tUser *%d*\n\n",i); i+=1;
          printf("\t\tId: %d\n",clu.Numero);
        printf("\t\tNom Du Compte: %s\n",clu.Nomc);
        printf("\t\t*************************************************\n");
    }while(!feof(f));
    fclose(f);

}


//Ajouter client
void Ajouter()
{
    FILE *f;
    int numero;
    f=fopen("client.txt","a+");
    printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =            Inscription d'Un Client         =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
    printf("\t\t\t\t**********\n\n");
    printf("\t\t\t\t\tLe Numero du client:");
    scanf("%d",&numero);
    fflush(stdin);
    while(Exist(numero)==1)
    {
        printf("\n\t\tCe numero Existe deja\n");
    printf("\n\t\tEntrer le Numero du Nouveau client:");
        scanf("%d",&numero);
    }
    cli.Numero=numero;
    printf("\n\t\tLe Nom:");
    gets(cli.Nom);
        fflush(stdin);
    printf("\n\t\tLe Prenom:");
    gets(cli.Prenom);
        fflush(stdin);
    printf("\n\t\tL'Adresse:");
   gets(cli.Adresse);
       fflush(stdin);
        printf("\n\t\tSon Telephone:");
   gets(cli.Telephone);
       fflush(stdin);
        printf("\n\t\tSon Email:");
   gets(cli.Mail);
       fflush(stdin);
   printf("\n\t\tLe numero de Carte de Credit:");
   gets(cli.CarteCredit);
    fflush(stdin);

      cli.Achat = 0.0;
      cli.DT =(cli.Achat/0.9367);
      printf("\n\t\tLimite De Credit : ");
      scanf("%lf", &cli.LC);
      cli.DP=(cli.LC-cli.DT);
      cli.I=(0.0333*cli.DT);
      cli.MN=(0.06*cli.DT);
      cli.Penalite=(0.03*cli.DT);
      fflush(stdin);
    fprintf(f,"\n%d  ;%s  ;%s  ;%s  ;%s  ;%s  ;%s  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf\n",cli.Numero,cli.Nom,cli.Prenom,cli.Adresse,cli.Telephone,cli.Mail,cli.CarteCredit,cli.LC,cli.DP,cli.DT,cli.MN,cli.Penalite,cli.I,cli.PM,cli.Achat);
    fclose(f);
}

//Exister Nom compte
int ExistNuser(char mot[100])
{   FILE *f; int u;
    f=fopen("user.txt","r+");
    do
    {
       fscanf(f,"\n%d  ;%[^' ']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%c  ;%d-%d-%d\n",&use.Numero,&use.Nomc,&use.Nom,&use.Telephone,&use.Mail,&use.Password,&use.Eta,&use.date.jour,&use.date.mois,&use.date.annee);
        fflush(stdin);
        u=strcmp(mot,use.Nomc);
       // printf("\n%d",u); getchar();
        if(u==0)
        {
         return 1;

        }


    }while(!feof(f));
    fclose(f);
    fflush(stdin);
    return -1;
}

//Desactiver Compte
void Desactiver()
{
    FILE *f,*ftemp; int code; char rep='n';
     printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =           Desactiver Vos Comptes Ici       =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
    printf("\n\t\tEntrer l'Id Du Compte a Activer:");
    scanf("%d",&code);
    fflush(stdin);
    if(ExistUser(code)==1)
    {
        printf("\n\t\tVoulez-vous Vraiment Modifier o/n?:");
        scanf("%c",&rep); printf("\n");
        fflush(stdin);
        if(rep=='o' || rep=='O')
        {
                f=fopen("user.txt","r+");
                ftemp=fopen("Tempclient.txt","a+");
                do
                {
                   fscanf(f,"\n%d  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%c  ;%d-%d-%d\n",&use.Numero,&use.Nomc,&use.Nom,&use.Telephone,&use.Mail,&use.Password,&use.Eta,&use.date.jour,&use.date.mois,&use.date.annee);
                    fflush(stdin);
                    if(code==use.Numero)
                    {
                        system("cls");
        printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =           Desactiver Vos Comptes Ici       =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
                    printf("\n\t\tAffichage Des Informations Actuelles\n\n");
                    printf("\t\tId: %d\n",use.Numero);
                    printf("\t\tNom Du Compte: %s\n",use.Nomc);
                    printf("\t\tCe Compte Appartient a: %s\n",use.Nom);
                    printf("\t\tTelephone: %s\n",use.Telephone);
                    printf("\t\tEmail: %s\n",use.Mail);
                    printf("\t\tMot-De-Passe: %s\n",use.Password);
                    printf("\t\tCree le: %d-%d-%d\n",use.date.jour,use.date.mois,use.date.annee);
                    if(use.Eta=='A'){
                    printf("\t\tEta Du Compte:Activer\n");}
                    else{printf("\t\tEta Du Compte: Desactiver\n");}
                        printf("\t\t\t\t*************************************************\n");

                     use.Numero=code;
                            if(use.Eta=='A')
                            {
                                use.Eta='D';
                                printf("\n\t\t\t\tDesactivation Reussie.....");
                            }
                            else{printf("\n\t\t\t\tCe Compte Est Deja Desactive....");}



                        }
                        //fflush(stdin);
                      fprintf(ftemp,"\n%d  ;%s  ;%s  ;%s  ;%s  ;%s  ;%c  ;%d-%d-%d\n",use.Numero,use.Nomc,use.Nom,use.Telephone,use.Mail,use.Password,use.Eta,use.date.jour,
                              use.date.mois,use.date.annee);


                }while(!feof(f));
                fclose(ftemp);
                fclose(f);
                remove("user.txt");
                rename("Tempclient.txt","user.txt");
                //printf("\n\t\t\t\t\tModification Avec Succes.....\n");
        }
    }
    else{
            printf("\n\t\tCe Compte n'existe pas.....");
        }
}

//Activer Compte
void Activer()
{
    FILE *f,*ftemp; int code; char rep='n';

    printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =           Activer Vos Comptes Ici          =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
    printf("\n\t\tEntrer l'Id Du Compte a Activer:");
    scanf("%d",&code);
    fflush(stdin);
    if(ExistUser(code)==1)
    {
        printf("\n\t\tVoulez-vous Vraiment Modifier o/n?:");
        scanf("%c",&rep); printf("\n");
        fflush(stdin);
        if(rep=='o' || rep=='O')
        {
                f=fopen("user.txt","r+");
                ftemp=fopen("Tempclient.txt","a+");
                do
                {
                   fscanf(f,"\n%d  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%c  ;%d-%d-%d\n",&use.Numero,&use.Nomc,&use.Nom,&use.Telephone,&use.Mail,&use.Password,&use.Eta,&use.date.jour,&use.date.mois,&use.date.annee);
                    fflush(stdin);
                    if(code==use.Numero)
                    {
                                        system("cls");
                        printf("\n");
                        printf("              ----------------- Digital Carte---------------   \n");
                        printf("              =           Activer Vos Comptes Ici          =   \n");
                        printf("              ----------------------------------------------   \n");
                        printf("################################################################################\n");
                        printf("\n\t\tAffichage Des Informations Actuels\n\n");
                        printf("\t\tId: %d\n",use.Numero);
                        printf("\t\tNom Du Compte: %s\n",use.Nomc);
                        printf("\t\tCe Compte Appartient a: %s\n",use.Nom);
                        printf("\t\tTelephone: %s\n",use.Telephone);
                        printf("\t\tEmail: %s\n",use.Mail);
                        printf("\t\tMot-De-Passe: %s\n",use.Password);
                        printf("\t\tCree le: %d-%d-%d\n",use.date.jour,use.date.mois,use.date.annee);
                        if(use.Eta=='A'){
                        printf("\t\tEta Du Compte:Activer\n");}
                        else{printf("\t\tEta Du Compte: Desactiver\n");}
                        printf("\t\t*************************************************\n");
                        //printf("\t\t\t\t\tAjouter Vos Nouvelles Informations\n");
                     use.Numero=code;
                            if(use.Eta=='D')
                            {
                                use.Eta='A';
                                printf("\n\t\tActivation Reussie.....");
                            }
                            else{printf("\n\t\tCe Compte Est Deja Active....");}

                    }
                      fprintf(ftemp,"\n%d  ;%s  ;%s  ;%s  ;%s  ;%s  ;%c  ;%d-%d-%d\n",use.Numero,use.Nomc,use.Nom,use.Telephone,use.Mail,use.Password,use.Eta,use.date.jour,
                              use.date.mois,use.date.annee);


                }while(!feof(f));
                fclose(ftemp);
                fclose(f);
                remove("user.txt");
                rename("Tempclient.txt","user.txt");
        }
    }
    else{
            printf("\n\t\tCe Compte n'existe pas.....");
        }
}

//Rechercher Un utilisateur
void RechercherCompte()
{
    FILE *f;
    char mot[100]; int u,test=0;
    printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =           Faites Vos Recherches Ici         =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");

     printf("\n\t\tLe Nom du Compte a rechercher:");
    scanf("%s",&mot);
    f=fopen("user.txt","r+");
    if(ExistNuser(mot)!=1)
    {
        printf("\n\t\tCe Compte N'existe pas");
    }
    else{
    do
    {
       fscanf(f,"\n%d  ;%[^' ']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%c  ;%d-%d-%d\n",&use.Numero,&use.Nomc,&use.Nom,&use.Telephone,&use.Mail,&use.Password,&use.Eta,&use.date.jour,&use.date.mois,&use.date.annee);
        fflush(stdin);
        u=strcmp(mot,use.Nomc);

        if(u==0)
        {
        system("cls");
        printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =           Resultat De Vos Recherches       =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
         printf("\t\tInformation De l'Utilisateur Searching....\n\n");
        printf("\t\tId: %d\n",use.Numero);
        printf("\t\tNom Du Compte: %s\n",use.Nomc);
        printf("\t\tCe Compte Appartient a: %s\n",use.Nom);
        printf("\t\tTelephone: %s\n",use.Telephone);
        printf("\t\tEmail: %s\n",use.Mail);
        printf("\t\tCree le: %d-%d-%d\n",use.date.jour,use.date.mois,use.date.annee);
        if(use.Eta=='A'){
        printf("\t\tEta Du Compte:Activer\n");}
        else{printf("\t\t\Eta Du Compte: Desactiver\n");}
        }


    }while(!feof(f));
    }
    fclose(f);
            fflush(stdin);
}

//BiLan
void Bilan()
{
    FILE *f; int i=0;double lc=0.00,dispo=0.00,dt=0.00,pe=0.00,mi=0.00,achat=0.00,interet=0.00;
    f=fopen("client.txt","r+");

    do
    {
       fscanf(f,"\n%d  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf\n",&cli.Numero,&cli.Nom,&cli.Prenom,&cli.Adresse,&cli.Telephone,&cli.Mail,&cli.CarteCredit,&cli.LC,&cli.DP,&cli.DT,&cli.MN,&cli.Penalite,&cli.I,&cli.PM,&cli.Achat);
            fflush(stdin);i+=1;
            dt+=cli.DT;
            lc+=cli.LC;
            dispo+=cli.DP;
            pe+=cli.Penalite;
            mi+=cli.MN;
            achat+=cli.Achat;
            interet+=cli.I;
    }while(!feof(f));
    fclose(f);fflush(stdin); system("cls");
        printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =               Le Bilan                     =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n\n");
    printf("\n\t\t1-Nombre de Client:%d\n",i);
    printf("\n\t\t2-Leur Limite de Credit s'eleve a:%.2f gourde(s)\n",lc);
    printf("\n\t\t3-Leur Disponibilite s'eleve a:%.2f gourde(s)\n",dispo);
    printf("\n\t\t4-Leur dette s'eleve a:%.2f gourde(s)\n",dt);
    printf("\n\t\t5-Leur Penalite s'eleve a:%.2f gourde(s)\n",pe);
    printf("\n\t\t6-Leur Minimum a payer s'eleve a:%.2f gourde(s)\n",mi);
    printf("\n\t\t7-Leur Achat s'eleve a:%.2f gourde(s)\n",achat);
    printf("\n\t\t8-Leur Interet a Payer a:%.2f gourde(s)\n",interet);
}


//Recherche Sur Un Client
void Rechercher()
{
    int code;
    printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =             Faites Vos Recherches Ici      =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
     printf("\n\t\tL'Id du client a rechercher:");
        scanf("%d",&code);
        FILE *f;
       f=fopen("client.txt","r+");
       system("cls");
       printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =             Resultat Du Recherche          =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
       if(Exist(code)!=1)
       {
           printf("\t\t\t\tCet Id n'existe pas...");
       }
        else{
                do
                {
                    fscanf(f,"\n%d  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf\n",&cli.Numero,&cli.Nom,&cli.Prenom,&cli.Adresse,&cli.Telephone,&cli.Mail,&cli.CarteCredit,&cli.LC,&cli.DP,&cli.DT,&cli.MN,&cli.Penalite,&cli.I,&cli.PM,&cli.Achat);
                    fflush(stdin);
                    if(cli.Numero==code)
                    {
                       printf("\t\tInformation Du Client Searching....\n\n");
                       printf("\t\tNumero: %d\n",cli.Numero);
                       printf("\t\tNom: %s\n",cli.Nom);
                       printf("\t\tPrenom: %s\n",cli.Prenom);
                       printf("\t\tAdresse: %s\n",cli.Adresse);
                       printf("\t\tTelephone: %s\n",cli.Telephone);
                       printf("\t\tEmail: %s\n",cli.Mail);
                       printf("\t\tCarte De Credit: %s\n",cli.CarteCredit);
                       printf("\t\tLimite De Credit:%.2f gourde(s)\n",cli.LC);
                       printf("\t\tDisponibilite:%.2f gourde(s)\n",cli.DP);
                       printf("\t\tDette:%.2f gourde(s)\n",cli.DT);
                       printf("\t\tInteret:%.2f gourde(s)\n",cli.I);
                       printf("\t\tPenalite:%.2f gourde(s)\n",cli.Penalite);
                       printf("\t\tMinimum A Payer:%.2f gourde(s)\n",cli.MN);
                       printf("\t\tPaiement:%.2f gourde(s)\n",cli.PM);
                       printf("\t\tAchat:%.2f gourde(s)\n",cli.Achat);
                    }

                }while(!feof(f));
            }
            fclose(f);
            fflush(stdin);
}

//Modifier Informations Client
void Modifier()
{
    FILE *f,*ftemp; int code; char rep='n';
    printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =           Modifier Vos Informations Ici    =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
    printf("\n\t\tEntrer l'Id Du Client a Modifier:");
    scanf("%d",&code);
    fflush(stdin);
    if(Exist(code)==1)
    {
        printf("\n\t\tVoulez-vous Vraiment Modifier o/n?:");
        scanf("%c",&rep); printf("\n");
        fflush(stdin);
        if(rep=='o' || rep=='O')
        {
                f=fopen("client.txt","r+");
                ftemp=fopen("Tempclient.txt","a+");
                do
                {
                   fscanf(f,"\n%d  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf\n",&cli.Numero,&cli.Nom,&cli.Prenom,&cli.Adresse,&cli.Telephone,&cli.Mail,&cli.CarteCredit,&cli.LC,&cli.DP,&cli.DT,&cli.MN,&cli.Penalite,&cli.I,&cli.PM,&cli.Achat);
                    fflush(stdin);
                    if(code==cli.Numero)
                    {
                        system("cls");
        printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =        Modifier Vos Informations Ici       =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
                    printf("\n\t\t\t\t\tAffichage Des Informations Actuelles\n\n");
                            printf("\t\tNumero: %d\n",cli.Numero);
                       printf("\t\tNom: %s\n",cli.Nom);
                       printf("\t\tPrenom: %s\n",cli.Prenom);
                       printf("\t\tAdresse: %s\n",cli.Adresse);
                       printf("\t\tTelephone: %s\n",cli.Telephone);
                       printf("\t\tEmail: %s\n",cli.Mail);
                       printf("\t\tCarte De Credit: %s\n",cli.CarteCredit);
                       printf("\t\tLimite De Credit:%.2f gourde(s)\n",cli.LC);
                       printf("\t\tDisponibilite:%.2f gourde(s)\n",cli.DP);
                       printf("\t\tLimite De Credit:%.2f gourde(s)\n",cli.LC);
                       printf("\t\tDette:%.2f gourde(s)\n",cli.DT);
                       printf("\t\tInteret:%.2f gourde(s)\n",cli.I);
                       printf("\t\tPenalite:%.2f gourde(s)\n",cli.Penalite);
                       printf("\t\tMinimum A Payer:%.2f gourde(s)\n",cli.MN);
                       printf("\t\tPaiement:%.2f gourde(s)\n",cli.PM);
                        printf("\t\t*************************************************\n");
                        printf("\t\tAjouter Vos Nouvelles Informations\n");
                     cli.Numero=code;
                        printf("\n\t\tEntrer Le Nom:");
                            gets(cli.Nom);
                                fflush(stdin);
                            printf("\n\t\tEntrer Le Prenom:");
                            gets(cli.Prenom);
                                fflush(stdin);
                            printf("\n\t\tEntrer l'Adresse:");
                           gets(cli.Adresse);
                               fflush(stdin);
                                printf("\n\t\tEntrer Telephone:");
                           gets(cli.Telephone);
                               fflush(stdin);
                                printf("\n\t\tEntrer l'Email:");
                           gets(cli.Mail);

                        }
                        //fflush(stdin);
                      fprintf(ftemp,"\n%d  ;%s  ;%s  ;%s  ;%s  ;%s  ;%s  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf\n",cli.Numero,cli.Nom,cli.Prenom,cli.Adresse,cli.Telephone,cli.Mail,cli.CarteCredit,cli.LC,cli.DP,cli.DT,cli.MN,cli.Penalite,cli.I,cli.PM,cli.Achat);


                }while(!feof(f));
                fclose(ftemp);
                fclose(f);
                remove("client.txt");
                rename("Tempclient.txt","client.txt");
                printf("\n\t\t\t\t\tModification Avec Succes.....\n");
        }
    }
    else{
            printf("\n Cet Id numero n'existe pas.....");
        }
}

//affichage
void Afficher()
{
    FILE *f; int i=1;
    f=fopen("client.txt","r+");
        printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =               Listage Des Clients          =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
    do
    {
       fscanf(f,"\n%d  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf\n",&cli.Numero,&cli.Nom,&cli.Prenom,&cli.Adresse,&cli.Telephone,&cli.Mail,&cli.CarteCredit,&cli.LC,&cli.DP,&cli.DT,&cli.MN,&cli.Penalite,&cli.I,&cli.PM,&cli.Achat);
            fflush(stdin);
           printf("\n\t\tClient *%d*\n\n",i); i+=1;
          printf("\t\tId: %d\n",cli.Numero);
        printf("\t\tNom: %s\n",cli.Nom);
        printf("\t\tPrenom: %s\n",cli.Prenom);
        printf("\t\t*******************************************\n");
    }while(!feof(f));
    fclose(f);
}


//Paiement
void Paiement()
{
    FILE *f,*ftemp; int code; char rep='n',choix; double pai=0.00,somme=0.00;
        printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =            Faites Vos Paiements Ici      =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
    printf("\n\t\tEntrer L'Id Du Client:");
    scanf("%d",&code);
    fflush(stdin);
    if(Exist(code)==1)
    {
        printf("\n\tVoulez-vous Vraiment Faire Un Transaction Sur Ce Client o/n?:");
        scanf("%c",&rep); system("cls");
         printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =            Faites Vos Paiements Ici      =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");

        fflush(stdin);
        if(rep=='o' || rep=='O')
        {
                f=fopen("client.txt","r+");
                ftemp=fopen("Tempclient.txt","a+");
                do
                {
                   fscanf(f,"\n%d  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf\n",&cli.Numero,&cli.Nom,&cli.Prenom,&cli.Adresse,&cli.Telephone,&cli.Mail,&cli.CarteCredit,&cli.LC,&cli.DP,&cli.DT,&cli.MN,&cli.Penalite,&cli.I,&cli.PM,&cli.Achat);
                    fflush(stdin);
                    if(code==cli.Numero)
                    {
                         cli.Numero=code; pai=cli.DT;
                           printf("\t\tNumero:%d\n",cli.Numero);
                           printf("\t\tNom:%s \n",cli.Nom);
                           printf("\t\tPrenom:%s\n",cli.Prenom);
                           printf("\t\tCarte De Credit: %s\n",cli.CarteCredit);
                       printf("\t\tLimite De Credit:%.2f gourde(s)\n",cli.LC);
                       printf("\t\tDisponibilite:%.2f gourde(s)\n",cli.DP);
                       printf("\t\tLimite De Credit:%.2f gourde(s)\n",cli.LC);
                       printf("\t\tDette:%.2f gourde(s)\n",cli.DT);
                       printf("\t\tInteret:%.2f gourde(s)\n",cli.I);
                       printf("\t\tPenalite:%.2f gourde(s)\n",cli.Penalite);
                       printf("\t\tMinimum A Payer:%.2f gourde(s)\n",cli.MN);
                       printf("\t\tPaiement:%.2f gourde(s)\n",cli.PM);
                       printf("\t\tAchat:%.2f gourde(s)\n",cli.Achat);
                        printf("\n\t\tFaites Vos Paiements Ici\n");

                          do {
                            printf("\n\t\tMontant : ");
                          scanf("%lf", &somme);
                          } while (somme<=0);
                            system("cls");
                             printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =            Faites Vos Paiements Ici        =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");

                            pai -= somme;
                            cli.DT=pai;
                            cli.PM+=somme;



                             cli.DP=(cli.LC-cli.DT);
                              cli.I=(0.0333*cli.DT);
                              cli.MN=(0.06*cli.DT);
                              cli.Penalite=(0.03*cli.DT);
                        }
                       fprintf(ftemp,"\n%d  ;%s  ;%s  ;%s  ;%s  ;%s  ;%s  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf\n",cli.Numero,cli.Nom,cli.Prenom,cli.Adresse,cli.Telephone,cli.Mail,cli.CarteCredit,cli.LC,cli.DP,cli.DT,cli.MN,cli.Penalite,cli.I,cli.PM,cli.Achat);
                }while(!feof(f));
                fclose(ftemp);
                fclose(f);
                fflush(stdin);
                remove("client.txt");
                rename("Tempclient.txt","client.txt");

                printf("\n\t\tT'as Paye %.2f Sur Ta Dette.\n\t\tMaintenant, Tu as %.2f Comme Dette Sur Ce Compte......\n ",somme,pai);
                printf("\n\t\tOperation Avec Succes.....");
        }
    }
    else{
            printf("\n\t\t\t\t\tCet Id n'existe pas.....");
        }
}

//Faire Un Renversement
void Renverser()
{
    FILE *f,*ftemp; int code; char rep='n',choix; double dt=0.00,p=0.00,somme=0.00;
        printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =            Faites Vos Renversements Ici      =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
    printf("\n\t\tEntrer L'Id Du Client:");
    scanf("%d",&code);
    fflush(stdin);
    if(Exist(code)==1)
    {
        printf("\n\tVoulez-vous Vraiment Faire Un Transaction Sur Ce Client o/n?:");
        scanf("%c",&rep); system("cls");
         printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =            Faites Vos Renversements Ici      =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");

        fflush(stdin);
        if(rep=='o' || rep=='O')
        {
                f=fopen("client.txt","r+");
                ftemp=fopen("Tempclient.txt","a+");
                do
                {
                   fscanf(f,"\n%d  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf\n",&cli.Numero,&cli.Nom,&cli.Prenom,&cli.Adresse,&cli.Telephone,&cli.Mail,&cli.CarteCredit,&cli.LC,&cli.DP,&cli.DT,&cli.MN,&cli.Penalite,&cli.I,&cli.PM,&cli.Achat);
                    fflush(stdin);
                    if(code==cli.Numero)
                    {
                         cli.Numero=code; dt=cli.DT; p=cli.PM;
                           printf("\t\tNumero:%d\n",cli.Numero);
                           printf("\t\tNom:%s \n",cli.Nom);
                           printf("\t\tPrenom:%s\n",cli.Prenom);
                           printf("\t\tCarte De Credit: %s\n",cli.CarteCredit);
                       printf("\t\tLimite De Credit:%.2f gourde(s)\n",cli.LC);
                       printf("\t\tDisponibilite:%.2f gourde(s)\n",cli.DP);
                       printf("\t\tLimite De Credit:%.2f gourde(s)\n",cli.LC);
                       printf("\t\tDette:%.2f gourde(s)\n",cli.DT);
                       printf("\t\tInteret:%.2f gourde(s)\n",cli.I);
                       printf("\t\tPenalite:%.2f gourde(s)\n",cli.Penalite);
                       printf("\t\tMinimum A Payer:%.2f gourde(s)\n",cli.MN);
                       printf("\t\tPaiement:%.2f gourde(s)\n",cli.PM);
                       printf("\t\tAchat:%.2f gourde(s)\n",cli.Achat);
                        printf("\n\t\tFaites Vos Transactions Ici\n");
                          do {
                            printf("\n\t\tMontant A Renverser : ");
                          scanf("%lf", &somme);
                          } while (somme<=0);
                            system("cls");
                             printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =            Faites Vos Renversements Ici        =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");


                            dt+=somme;
                             p-=somme;
                            cli.DT=dt;
                            cli.PM=p;

                             cli.DP=(cli.LC-cli.DT);
                              cli.I=(0.0333*cli.DT);
                              cli.MN=(0.06*cli.DT);
                              cli.Penalite=(0.03*cli.DT);
                        }
                       fprintf(ftemp,"\n%d  ;%s  ;%s  ;%s  ;%s  ;%s  ;%s  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf  ;%lf\n",cli.Numero,cli.Nom,cli.Prenom,cli.Adresse,cli.Telephone,cli.Mail,cli.CarteCredit,cli.LC,cli.DP,cli.DT,cli.MN,cli.Penalite,cli.I,cli.PM,cli.Achat);
                }while(!feof(f));
                fclose(ftemp);
                fclose(f);
                fflush(stdin);
                remove("client.txt");
                rename("Tempclient.txt","client.txt");

                printf("\n\t\tOn t'a renverse %.2f gourde(s).\n\t\tMaintenant, Tu as %.2f(s) Comme Dette Sur Ce Compte......\n ",somme,dt);
                printf("\n\t\tOperation Avec Succes.....");
        }
    }
    else{
            printf("\n\t\t\t\t\tCet Id n'existe pas.....");
        }
}

//Modifier Password
void ModifierPass()
{
    FILE *f,*ftemp; int code; char rep='n';
    system("cls");
        printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =    Modifier Vos Informations Ici            =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
    printf("\n\t\tEntrer l'Id Du Compte a Modifier:");
    scanf("%d",&code);
    fflush(stdin);
    if(ExistUser(code)==1)
    {
        printf("\n\t\tVoulez-vous Vraiment Modifier o/n?:");
        scanf("%c",&rep); printf("\n");
        fflush(stdin);
        if(rep=='o' || rep=='O')
        {
                f=fopen("user.txt","r+");
                ftemp=fopen("Tempclient.txt","a+");
                do
                {
                   fscanf(f,"\n%d  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%[^';']  ;%c  ;%d-%d-%d\n",&use.Numero,&use.Nomc,&use.Nom,&use.Telephone,&use.Mail,&use.Password,&use.Eta,&use.date.jour,&use.date.mois,&use.date.annee);
                    fflush(stdin);
                    if(code==use.Numero)
                    {
                        system("cls");
                        printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =    Modifier Vos Informations Ici            =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
                    printf("\n\t\tAffichage Des Informations Actuels\n\n");

        printf("\t\tId: %d\n",use.Numero);
        printf("\t\tNom Du Compte: %s\n",use.Nomc);
        printf("\t\tCe Compte Appartient a: %s\n",use.Nom);
        printf("\t\tTelephone: %s\n",use.Telephone);
        printf("\t\tEmail: %s\n",use.Mail);
        printf("\t\tCree le: %d-%d-%d\n",use.date.jour,use.date.mois,use.date.annee);
        if(use.Eta=='A'){
        printf("\t\t\t\t\tEta Du Compte:Activer\n");}
        else{printf("\t\tEta Du Compte: Desactiver\n");}
                        printf("\t\t*************************************************\n");
                        printf("\t\tAjouter Vos Nouvelles Informations\n");
                     use.Numero=code;
                            printf("\n\t\tEntrer Le nouveau Mot De Passe:");
                           gets(use.Password);



                        }
                        //fflush(stdin);
                      fprintf(ftemp,"\n%d  ;%s  ;%s  ;%s  ;%s  ;%s  ;%c  ;%d-%d-%d\n",use.Numero,use.Nomc,use.Nom,use.Telephone,use.Mail,use.Password,use.Eta,use.date.jour,
                              use.date.mois,use.date.annee);


                }while(!feof(f));
                fclose(ftemp);
                fclose(f);
                remove("user.txt");
                rename("Tempclient.txt","user.txt");
                printf("\n\t\tModification Avec Succes.....\n");
        }
    }
    else{
            printf("\n\t\tCe numero n'existe pas.....");
        }
}



void main()
{
    int choix,u,p,A; char rep,utili[100],pwrd[100],t[100]=" ",tp[100]=" ";
    char user[100]="admin",pas[100]="admin";
    do
    {
        system("cls");
        printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =      Authentifiez-vous Pour Passer Au Menu      =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n\n");
        printf("\t\t\tNom User:");
        scanf("%s",&utili);
        printf("\n\n\t\t\tEntrer mot de passe: ");
        scanf("%s",&pwrd);system("cls");
        u=strcmp(utili,user); p=strcmp(pwrd,pas);
       if(u==0 && p==0)
       {
            Menu_Admin();
       }
       else if(u!=0 || p!=0)
        {
            FILE *f;
           f=fopen("user.txt","r");
          if(ExistNuser(utili)!=1)
          {
              printf("\n\t\t\t\tUser Incorrect");
          }
                do
                {
                    fscanf(f,"\n%d  ;%s  ;%[^';']  ;%[^';']  ;%[^';']  ;%s ;%c  ;%d-%d-%d\n",&use.Numero,&use.Nomc,&use.Nom,&use.Telephone,&use.Mail,&use.Password,&use.Eta,&use.date.jour,&use.date.mois,&use.date.annee);
                    fflush(stdin);
                    if(strcmp(utili,use.Nomc)==0 )
                    {

                        u=strcmp(pwrd,use.Password);
                        if(u==0)
                            {
                                if(use.Eta=='A')
                                {
                                    Menu_User();
                                }
                                else
                                {
                                    printf("\n\t\t\t\tVotre Compte est Desactive");
                                }

                            }
                            else{printf("\n\t\t\t\tMot De Passe Incorrect");}


                        }

                }while(!feof(f));
            fclose(f);
            fflush(stdin);
       }
       else
       {
           printf("Nom Utilisateur ou Mot De Passe Incorrect");
       }


    printf("\n\n\t\t\t\tVoulez-vous Continuer O/N: ");
    scanf("%c",&rep); fflush(stdin);
    }while(rep=='o'||rep=='O');

}

void Menu_User()
{
    int choix; char rep;

    do
    {
        system("cls");
        printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =            Menu utilisateur                =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
    printf("\t\t1-Afficher La Liste Des Clients ........... \n");
    printf("\t\t2-Afficher Les Info Sur Un Client....... \n");
    printf("\t\t3-Ajouter Un Nouveau Client ....... \n");
    printf("\t\t4-Passer Un Paiement ....... \n");
    printf("\t\t5-Passer Un Renversement ... \n");
    printf("\t\t6-Effecutuer Un Biling ... \n");
    printf("\t\t7-Sortir Du Systeme ...............................: \n");
        do
        {
        printf("\n\t\t\tVotre choix:");
        scanf("%d",&choix);
        printf("\n");
        }while(choix<1 || choix>7);
    switch(choix)
    {
    case 1:
    system("cls");
      Afficher();
      break;
    case 2:
    system("cls");
     Rechercher();
      break;
    case 3:
    system("cls");
    Ajouter();
     //Supprimer();
    break;
    case 4:
    system("cls");
    Paiement();
    break;
    case 5:
    system("cls");
    Renverser();
    break;
    case 6:
    system("cls");
    Bilan();
    break;
    case 7:
    system("cls");
    printf("\t\t\t\tfin du programme \n\n\n\t\t\t\tAurevoir!!!!!\n\n");
    break;
    default:
      printf("Erreur de saisie, recommencez...\n");
      break;
    }
    printf("\n\n\t\t\t\tVoulez-vous Continuer O/N: ");
    scanf("%c",&rep);if(choix==7){printf("\n\n\t\t\t\tDeconnexion..... ");}
    }while(rep=='o'||rep=='O');
}


void Menu_Admin()
{ int choix; char rep;
    do
    {
        system("cls");
        printf("\n");
        printf("              ----------------- Digital Carte---------------   \n");
        printf("              =                  Menu Admin                =   \n");
        printf("              ----------------------------------------------   \n");
        printf("################################################################################\n");
    printf("\n\t\t1-Afficher La Liste Des Utilisateurs ........... \n");
    printf("\t\t2-Afficher Les Info Sur Un Utilisateur....... \n");
    printf("\t\t3-Creer Compte Pour Un Utilisateur ....... \n");
    printf("\t\t4-Activer Le Compte d'un Utilisateur ....... \n");
    printf("\t\t5-Desactiver Le Compte d'un Utilisateur ....... \n");
    printf("\t\t6-Changer Le mot De Passe d'Un Utilisateur ... \n");
    printf("\t\t7-Sortir Du Systeme ...............................: \n");
        do
        {
        printf("\n\t\tVotre choix:");
        scanf("%d",&choix);
        printf("\n");
        }while(choix<1 || choix>7);
    switch(choix)
    {
    case 1:
    system("cls");
      AfficherUser();
      break;
    case 2:
    system("cls");
     RechercherCompte();
      break;
    case 3:
    system("cls");
    AjouterUser();
    break;
    case 4:
    system("cls");
    Activer();
    break;
    case 5:
    system("cls");
    Desactiver();
    break;
    case 6:
    system("cls");
    ModifierPass();
    break;
    case 7:
    system("cls");
    printf("\t\t\t\tDeconnexion... \n\n\n\t\t\t\tAurevoir!!!!!\n\n");
    break;
    default:
      printf("Erreur de saisie, recommencez...\n");
      break;
    }
    printf("\n\n\t\t\t\tVoulez-vous Continuer O/N: ");
    scanf("%c",&rep);
    }while(rep=='o'||rep=='O');
}

/*
#-------------------------------------------------------------------------------
# Code beginner
# Name:        Petite_banque
# Purpose:     Transaction Bancaire
#
# Author:      Petit-Homme Ben-Jacques
# E-Mail:      pbenjacques@gmail.com
#
# Created:     17-06-2017
# Copyright:   (c) Benito 2017
# Licence:     <your licence>
#-------------------------------------------------------------------------------

*/


