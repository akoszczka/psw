#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define rozmiar_x 70
#define rozmiar_y 26

void wyczysc(char plansza[rozmiar_y][rozmiar_x])
{
    int i,j;
     for(i=0; i<rozmiar_y; i++)
        for(j=0; j<rozmiar_x; j++)
            plansza[i][j]=' ';
}
void rysuj(char plansza[rozmiar_y][rozmiar_x])
{
    int i,j;
    for(i=0; i<rozmiar_y; i++){
        for(j=0; j<rozmiar_x; j++){
            printf("%c", plansza[i][j]);
        }
        printf("\n");
    }
}

void licz_komorki(char plansza[rozmiar_y][rozmiar_x])
{
    int i,j;
    int komorki = 0;
    for(i=0; i<rozmiar_y; i++)
    {
        for(j=0; j<rozmiar_x; j++)
        {
            if(plansza[i][j]=='X')
            komorki++;
        }
    }
    printf("Liczba zywych komorek: %d \n", komorki);
}
void martwe(char plansza_a[rozmiar_y][rozmiar_x],char plansza_b[rozmiar_y][rozmiar_x],int (*dead))
{
    int i,j;
    for(i=0; i<rozmiar_y; i++)
    {
        for(j=0; j<rozmiar_x; j++)
        {
            if(plansza_a[i][j]=='X' && plansza_b[i][j]==' ') (*dead)++;
        }
    }

}

void pisz(char plansza[rozmiar_y][rozmiar_x])
{
  plansza[0][1]='X';
  plansza[1][2]='X';
  plansza[2][0]='X';
  plansza[2][1]='X';
  plansza[2][2]='X';
  int i;
    for(i=0;i<rozmiar_x;i++)
        plansza[rozmiar_y/2][i]='X';
}

void pobierz(char plansza[rozmiar_y][rozmiar_x])
{
     int i,j;
     FILE *dane;
     dane=fopen("dane1.txt","r");
     if(dane==NULL) printf("W tym katalogu nie ma takiego pliku\n");
     else
     {
        for(i=0; i<rozmiar_y; i++)
        {
            for(j=0; j<rozmiar_x; j++)
            {
                 if(feof(dane)) break;
                 fscanf(dane,"%c",&plansza[i][j]);
                 printf("%c", plansza[i][j]);
            }
        }
    }
}
void plansza_krok(char plansza_a[rozmiar_y][rozmiar_x], char plansza_b[rozmiar_y][rozmiar_x]){
    int i,j;

    for(i=0; i<rozmiar_y; i++)
        for(j=0; j<rozmiar_x; j++){
            plansza_a[i][j]=plansza_b[i][j];
        }
}

void krok(char plansza_a[rozmiar_y][rozmiar_x], char plansza_b[rozmiar_y][rozmiar_x])
{
    int i,j;
    int ls=0;

    for(i=0; i<rozmiar_y; i++){
        for(j=0; j<rozmiar_x; j++)
        {
            if(plansza_a[i-1][j-1]=='X') ls++;
            if(plansza_a[i-1][j]=='X') ls++;
            if(plansza_a[i-1][j+1]=='X') ls++;
            if(plansza_a[i][j-1]=='X') ls++;
            if(plansza_a[i][j+1]=='X') ls++;
            if(plansza_a[i+1][j-1]=='X') ls++;
            if(plansza_a[i+1][j]=='X') ls++;
            if(plansza_a[i+1][j+1]=='X') ls++;

            if(ls==3)
                plansza_b[i][j]='X';
            else if(ls==2 && plansza_a[i][j]=='X')
                    plansza_b[i][j]='X';

            else if(ls<2 || ls>3)
            {
            plansza_b[i][j]=' ';
            }
            ls=0;
        }


    }
}




int main()
{
    char plansza[rozmiar_y][rozmiar_x];
    char plansza_a[rozmiar_y][rozmiar_x];
    char plansza_b[rozmiar_y][rozmiar_x];
    char wybierz, koniec, wybor;
    int generacja=0, dead=0;
    printf("1. x\n");
    printf("2. x\n");
    printf("3. x\n");
    printf("4. plik\n");
    scanf("%d", &wybor);
    wyczysc(plansza_b);
    wyczysc(plansza_a);
    rysuj(plansza);
    switch(wybor)
    {
        case '1' : pisz(plansza_a); pisz(plansza_b); break;
        case '2' : pisz(plansza_a); pisz(plansza_b); break;
        case '3' : pisz(plansza_a); pisz(plansza_b); break;
        case '4' : pobierz(plansza_a); pobierz(plansza_b); break;
        default : pisz(plansza_a); pisz(plansza_b); break;
    }
    do{
    system("cls");
    rysuj(plansza_b);
    licz_komorki(plansza_b);
    printf("Generacja numer: %d\n", ++generacja);
    printf("Komorki, ktore umarly od poczatku: %d", dead);
    scanf("%c", &koniec);
    krok(plansza_a,plansza_b);
    martwe(plansza_a,plansza_b,&dead);
    plansza_krok(plansza_a,plansza_b);

    }while(koniec != 'q');




    return 0;
}
