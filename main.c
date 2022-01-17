#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define KOLUMNA 7
#define RZAD 6

int notFinished = 1;

void wyswietl_tab(int plansza[RZAD][KOLUMNA],int kolor){
   int row, column;
   int x,y,z;
   char character;

   printf("\n");

   for (row = 0; row < RZAD; row++){
      for(column = 0; column< KOLUMNA; column++){

         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
         printf("| ");

         if(plansza[row][column] == 0){
         character=' ';
         }

         else if (plansza[row][column] == 1){
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
         character='O';
         }

         else if (plansza[row][column] == 2){
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
         character='O';
            
         }
         printf("%c ",character);
      }
      
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
      printf("|\n");  
   }

   for(x = 0; x < KOLUMNA; x++)
   printf("+---");

   printf("+\n");
   printf("  1   2   3   4   5   6   7\n");

}

void wstaw_krazek(int plansza[RZAD][KOLUMNA],int kolor){

   int wybor,rzad,kol;

   scanf("%d",&wybor);
         while (wybor > 7 || wybor < 1){
                printf("WYBIERZ POPRAWNY NUMER!!!\n");
                scanf("%d",&wybor);
        }

         wybor--;      

         if (plansza[0][wybor] != 0){
            printf("\nKOLUMNA PELNA, WYBIERZ INNA!\n");
         }

         else{
         
          for (rzad = 5; rzad >= 0; rzad--){
                if (plansza[rzad][wybor] == 0){
                   if (kolor == 0){
                        plansza[rzad][wybor] = 1;
                                break;
                   }
                   else if (kolor == 1){
                      plansza[rzad][wybor] = 2;
                        break;
                   }
                        }

                else
                {
                        continue;
                }
          }
                        
                        
        }  
                
} 

int check_draw(int plansza[RZAD][KOLUMNA]){
   int rzad,kolumna,licz;

   licz = 0;
   rzad = 0;

   for (kolumna = 0; kolumna < KOLUMNA; kolumna++){
      if (plansza[rzad][kolumna] == 0)
      {
         licz++;
         break;
      }

      else {
         continue;
      }
   }
   if (licz == 0)
   printf("\nGRA ZAKONCZYLA SIE REMISEM\n");

   return licz;
}

int check_win(int plansza[RZAD][KOLUMNA],int kolor){

   int kolumna,rzad,win;
   int gracz1,gracz2,kto;

   win = 1;
   gracz1 = 1;
   gracz2 = 2;
   
   for (rzad = 0; rzad < RZAD; rzad++){
      for (kolumna = 0; kolumna < KOLUMNA - 3; kolumna++){
         if (plansza[rzad][kolumna] == gracz1 && plansza[rzad][kolumna+1] == gracz1 && plansza[rzad][kolumna+2] == gracz1 && plansza[rzad][kolumna+3] == gracz1)
         {
            win = 0;
            kto = 1;
            break;
         }

         else if (plansza[rzad][kolumna] == gracz2 && plansza[rzad][kolumna+1] == gracz2 && plansza[rzad][kolumna+2] == gracz2 && plansza[rzad][kolumna+3] == gracz2)
         {
            win = 0;
            kto = 2;
            break;
         }
         
         else
         {
            continue;
         }
         
      }
   }

   for (rzad = 0; rzad < RZAD-3; rzad++){
      for (kolumna = 0; kolumna < KOLUMNA; kolumna++){
         if (plansza[rzad][kolumna] == gracz1 && plansza[rzad+1][kolumna] == gracz1 && plansza[rzad+2][kolumna] == gracz1 && plansza[rzad+3][kolumna] == gracz1)
         {
            win = 0;
            kto = 1;
            break;
         }

         else if (plansza[rzad][kolumna] == gracz2 && plansza[rzad+1][kolumna] == gracz2 && plansza[rzad+2][kolumna] == gracz2 && plansza[rzad+3][kolumna] == gracz2)
         {
            win = 0;
            kto = 2;
            break;
         }
         
         else
         {
            continue;
         }
         
      }
   }

   for (rzad = 5; rzad > 2; rzad--){
      for (kolumna = 0; kolumna < KOLUMNA-3; kolumna++){
         if (plansza[rzad][kolumna] == gracz1 && plansza[rzad-1][kolumna+1] == gracz1 && plansza[rzad-2][kolumna+2] == gracz1 && plansza[rzad-3][kolumna+3] == gracz1)
         {
            win = 0;
            kto = 1;
            break;
         }

         else if (plansza[rzad][kolumna] == gracz2 && plansza[rzad-1][kolumna+1] == gracz2 && plansza[rzad-2][kolumna+2] == gracz2 && plansza[rzad-3][kolumna+3] == gracz2)
         {
            win = 0;
            kto = 2;
            break;
         }
         
         else
         {
            continue;
         }
         
      }
   }

    for (rzad = 0; rzad < RZAD-3; rzad++){
      for (kolumna = 0; kolumna < KOLUMNA-3; kolumna++){
         if (plansza[rzad][kolumna] == gracz1 && plansza[rzad+1][kolumna+1] == gracz1 && plansza[rzad+2][kolumna+2] == gracz1 && plansza[rzad+3][kolumna+3] == gracz1)
         {
            win = 0;
            kto = 1;
            break;
         }

         else if (plansza[rzad][kolumna] == gracz2 && plansza[rzad+1][kolumna+1] == gracz2 && plansza[rzad+2][kolumna+2] == gracz2 && plansza[rzad+3][kolumna+3] == gracz2)
         {
            win = 0;
            kto = 2;
            break;
         }
         
         else
         {
            continue;
         }
         
      }
   }
   if (kto == 1){
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
      printf("\nWYGRAL CZERWONY\n");
   }

   else if(kto == 2){
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
      printf("\nWYGRAL ZIELONY\n");
   }
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

   return win;
}


int main(){

   int kolor=0;
   int i=1;   
   int plansza[RZAD][KOLUMNA] = {{0}};
   char imie1,imie2;
   printf("\n ***WITAJ W GRZE W CZWORKI!***\n\n Wybierz liczbe od 1 do 7\n");

      while (notFinished == 1)
      {
         kolor=i%2;
         i++;

         printf("\n Kolej gracza ");

         if (kolor == 0){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
            printf("CZERWONEGO\n");
         }

         else if (kolor == 1){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            printf("ZIELONEGO\n");
         }
         
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);


         wyswietl_tab(plansza,kolor);
         wstaw_krazek(plansza,kolor);
         notFinished = check_draw(plansza);
         notFinished = check_win(plansza,kolor);
      }
   wyswietl_tab(plansza,kolor);
}
