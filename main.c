#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define rozmiar_x 70
#define rozmiar_y 25

void wyczysc(char plansza[rozmiar_y][rozmiar_x])
{
    int i,j;
     for(i=0; i<rozmiar_y; i++)
        for(j=0; j<rozmiar_x; j++)
            plansza[i][j]=' ';
}
void rysuj(char plansza[rozmiar_y][rozmiar_x])
{
    system("cls");
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
}
int main()
{
    char plansza[rozmiar_y][rozmiar_x];
    wyczysc(plansza);
    rysuj(plansza);
    pisz(plansza);
    rysuj(plansza);
    return 0;
}
