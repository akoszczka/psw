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
void pisz(char plansza[rozmiar_y][rozmiar_x])
{
  plansza[rozmiar_y/2][rozmiar_x/2]='X';
  plansza[(rozmiar_y/2)][(rozmiar_x/2)+1]='X';
  plansza[(rozmiar_y/2)][(rozmiar_x/2)-1]='X';

  plansza[0][1]='X';
  plansza[1][2]='X';
  plansza[2][0]='X';
  plansza[2][1]='X';
  plansza[2][2]='X';
}

void plansza_krok(char plansza_a[rozmiar_y][rozmiar_x], char plansza_b[rozmiar_y][rozmiar_x]){
    int i,j;

    for(i=0; i<rozmiar_y; i++)
        for(j=0; j<rozmiar_x; j++){
            plansza_a[i][j]=plansza_b[i][j];
        }
}

void krok(char plansza_a[rozmiar_y][rozmiar_x], char plansza_b[rozmiar_y][rozmiar_x]){

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
                    plansza_b[i][j]=' ';

            ls=0;
        }
    }
    plansza_krok(plansza_a,plansza_b);
}




int main()
{
    char plansza[rozmiar_y][rozmiar_x];
    char plansza_a[rozmiar_y][rozmiar_x];
    char plansza_b[rozmiar_y][rozmiar_x];
    int generacja=0;
    char koniec;
    wyczysc(plansza_a);
    wyczysc(plansza_b);
    rysuj(plansza);
    pisz(plansza_a);
    pisz(plansza_b);
    do{
    system("cls");
    rysuj(plansza_b);
    printf("Generacja numer: %d\n", ++generacja);
    scanf("%c", &koniec);
    krok(plansza_a,plansza_b);
    }while(koniec != 'q');
    return 0;
}
