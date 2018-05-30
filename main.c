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

  plansza[0][0]='X';
  plansza[0][1]='X';
  plansza[0][2]='X';
  plansza[1][0]='X';
  plansza[2][1]='X';
}

void check(char plansza[rozmiar_y][rozmiar_x])
{
    int ls=0, i=0, j=0;
    for(i=0; i<26;i++)
    {
        for(j=0; j<71; j++)
        {
    if (plansza[i-1][j-1]=='X'){
        ls++;
    }
    if (plansza[i][j-1]=='X'){
        ls++;
    }
    if (plansza[i-1][j]=='X'){
        ls++;
    }
    if (plansza[i+1][j+1]=='X'){
        ls++;
    }
    if (plansza[i][j+1]=='X'){
        ls++;
    }
    if (plansza[i+1][j]=='X'){
        ls++;
    }
   /* if(ls<2){
        plansza[i][j]=' ';
    }
    else{
        plansza[i][j]='X';
    }*/
        }
    }
}


int main()
{
    char plansza[rozmiar_y][rozmiar_x];
    int generacja=0;
    char koniec;
    wyczysc(plansza);
    rysuj(plansza);
    do{
    pisz(plansza);
    rysuj(plansza);
    check(plansza);
    printf("Generacja numer: %d\n", ++generacja);
    scanf("%c", &koniec);
    }while(koniec != 'q');
    return 0;
}
