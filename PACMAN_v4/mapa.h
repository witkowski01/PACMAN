//W³asnoœæ Konrada Witkowskiego
//Nie wyra¿am zgody na kopiowanie choæ fragmentu kodu, zw³aszcza bez mojej wiedzy
//Nie za³¹czam plików potrzebnych do odpalenia gry jak grafiki, muzyka, czcionki. W celu ich uzyskania pisz na e-mail witkowski01@wp.pl

#include <allegro.h>
#include "mapaModel.h"
#include "BitMapy.h"

int px=30*14,py=30*18;  // pocz¹tkowe po³o¿enie pacmana

SAMPLE *music2;

int zycie=3;
int punkty=0;
int predkosc=70;       //Zmienna przechowuj¹ca prêdkoœæ im mniejsza tym szybciej chodzi i poacman i duchy


class Cmapa{
private: char maps;
		 int row, col;   // row- wiersze   col - kolumny;
public:
	void modelMapy()
		{
			maps=mapa[MAXWier][MAXKol];

	};



void rysoj_mapa()
{
		for(row=0; row<MAXWier; row++){
	
		for(col=0;col<MAXKol;col++){

			if(mapa[row][col]== 'X' ){
				draw_sprite(buffer , rock, col*30,row*30 ) ; 
			}
			else if (mapa[row][col]== 'o' ){
				                                                          //wstawianie potionków
				draw_sprite(buffer , potion, col*30,row*30 ) ; 
				
				if(py/30 == row && px/30 == col){
					play_sample(music2,300,150,1000,0)   ;
					punkty++;
					
					                        //zjadanie potionków
					mapa[row][col] = 'a' ;

				}
			}
			else if (mapa[row][col] == 'z' ){
				draw_sprite(buffer , serce,col*30,row*30 ) ;
				if(py/30 == row && px/30 == col){
					play_sample(music2,300,150,1000,0)   ;
					zycie++;
					mapa[row][col] = 'h' ;
				}
			}
		}
	}
}


void ekran(){

	blit(buffer, screen, 0,0,0,0,880,700); 

}


void Potionki_back(){

	int row,col;
	
	for(row=0; row<MAXWier; row++){
	
		for(col=0;col<MAXKol;col++){

			if(mapa[row][col]== 'X' ){
				draw_sprite(buffer , rock, col*30,row*30 ) ; 
			}
			else if (mapa[row][col]== 'a' ){
				mapa[row][col] = 'o' ;
				                                                          //wstawianie potionków spowrotem na mapê
				
				}
			else if (mapa[row][col]== 'h' ){
				mapa[row][col] = 'z' ;
				                                                          //wstawianie ¿ycia spowrotem na mapê
				
				}
			}
		}
	}





};