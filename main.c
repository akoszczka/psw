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

void glider(char plansza[rozmiar_y][rozmiar_x])
{
  plansza[0][1]='X';
  plansza[1][2]='X';
  plansza[2][0]='X';
  plansza[2][1]='X';
  plansza[2][2]='X';
}

void glider_gun(char plansza[rozmiar_y][rozmiar_x])
{
  plansza[5][1]='X';
  plansza[5][2]='X';
  plansza[6][1]='X';
  plansza[6][2]='X';
  plansza[5][11]='X';
  plansza[6][11]='X';
  plansza[7][11]='X';
  plansza[4][12]='X';
  plansza[3][13]='X';
  plansza[3][14]='X';
  plansza[8][12]='X';
  plansza[9][13]='X';
  plansza[9][14]='X';
  plansza[6][15]='X';
  plansza[4][16]='X';
  plansza[5][17]='X';
  plansza[6][17]='X';
  plansza[7][17]='X';
  plansza[6][18]='X';
  plansza[8][16]='X';
  plansza[3][21]='X';
  plansza[4][21]='X';
  plansza[5][21]='X';
  plansza[3][22]='X';
  plansza[4][22]='X';
  plansza[5][22]='X';
  plansza[2][23]='X';
  plansza[6][23]='X';
  plansza[1][25]='X';
  plansza[2][25]='X';
  plansza[6][25]='X';
  plansza[7][25]='X';
  plansza[3][35]='X';
  plansza[4][35]='X';
  plansza[3][36]='X';
  plansza[4][36]='X';
}
void pento(char plansza[rozmiar_y][rozmiar_x])
{
  plansza[7][11]='X';
  plansza[6][12]='X';
  plansza[7][12]='X';
  plansza[8][12]='X';
  plansza[6][13]='X';
}


void beacon(char plansza[rozmiar_y][rozmiar_x])
{
  plansza[1][1]='X';
  plansza[2][1]='X';
  plansza[1][2]='X';
  plansza[4][3]='X';
  plansza[3][4]='X';
  plansza[4][4]='X';
}

void cross(char plansza[rozmiar_y][rozmiar_x])
{
    int i,j;
    for(i=0;i<rozmiar_y;i++)
        plansza[i][rozmiar_x/2]='X';
     for(j=0;j<rozmiar_x;j++)
        plansza[rozmiar_y/2][j]='X';
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
    printf("1. Glider\n");
    printf("2. Gosper Glider Gun\n");
    printf("3. R-Pentomimo\n");
    printf("4. Beacon\n");
    printf("5. Krzyz\n");
    printf("6. Dane wprowadzone z pliku\n");
    scanf("%d", &wybor);
    wyczysc(plansza_b);
    wyczysc(plansza_a);
    rysuj(plansza);
    switch(wybor)
    {
        case 1 : glider(plansza_a); glider(plansza_b); break;
        case 2 : glider_gun(plansza_a); glider_gun(plansza_b); break;
        case 3 : pento(plansza_a); pento(plansza_b); break;
        case 4 : beacon(plansza_a); beacon(plansza_b); break;
        case 5 : cross(plansza_a); cross(plansza_b); break;
        case 6 : pobierz(plansza_a); pobierz(plansza_b); break;
        default : printf("Wybor spoza listy - wybrano domyslnie glider"); glider(plansza_a); glider(plansza_b); break;
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
