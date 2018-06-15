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
            if((plansza[i][j])=='X')
            komorki++;
        }
    }
    printf("Liczba zywych komorek: %d \n", komorki);
}
void pisz(char plansza[rozmiar_y][rozmiar_x])
{
   /* int i, j;
    char wybierz;
    FILE *dane;
    dane = fopen("dane1.txt", "r");

    switch(wybierz)
    {
        case '1':
            for(i=0; i<rozmiar_y; i++)
                for(j=0; j<rozmiar_x; j++)
                {
                        plansza[i][j]=getc(dane);
                        if(j==0 && plansza[i][j]==10) plansza[i][j]=getc(dane);
                        if(plansza[i][j]==10)
                        {
                        plansza[i][j]=0;
                        }
                }

        break;

      case '2':
      case '3':
      case '4':*/
  plansza[0][1]='X';
  plansza[1][2]='X';
  plansza[2][0]='X';
  plansza[2][1]='X';
  plansza[2][2]='X';
  int i;
    for(i=0;i<rozmiar_x;i++)
        plansza[rozmiar_y/2][i]='X';
}
void plansza_krok(char plansza_a[rozmiar_y][rozmiar_x], char plansza_b[rozmiar_y][rozmiar_x]){
    int i,j;

    for(i=0; i<rozmiar_y; i++)
        for(j=0; j<rozmiar_x; j++){
            plansza_a[i][j]=plansza_b[i][j];
        }
}

void krok(char plansza_a[rozmiar_y][rozmiar_x], char plansza_b[rozmiar_y][rozmiar_x], int *martwe)
{
    *martwe=0;
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
            martwe++;
            plansza_b[i][j]=' ';
            }
            ls=0;
        }


    }

    plansza_krok(plansza_a,plansza_b);
}




int main()
{
    int martwe=0;
    char plansza[rozmiar_y][rozmiar_x];
    char plansza_a[rozmiar_y][rozmiar_x];
    char plansza_b[rozmiar_y][rozmiar_x];
    char wybierz;
    int generacja=0;
    char koniec;
    wyczysc(plansza_a);
    wyczysc(plansza_b);
    rysuj(plansza);
   /* printf("Podaj wybor: ");
    scanf("%d", &wybierz);*/
    pisz(plansza_a);
    pisz(plansza_b);
    do{
    system("cls");
    rysuj(plansza_b);
    licz_komorki(plansza_b);
    printf("Generacja numer: %d\n", ++generacja);
    printf("Liczba komorek ktore umarly od startu programu: %d\n", martwe);
    scanf("%c", &koniec);
    krok(plansza_a,plansza_b,&martwe);
    }while(koniec != 'q');
    return 0;
}
