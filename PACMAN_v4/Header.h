//W³asnoœæ Konrada Witkowskiego
//Nie wyra¿am zgody na kopiowanie choæ fragmentu kodu, zw³aszcza bez mojej wiedzy
//Nie za³¹czam plików potrzebnych do odpalenia gry jak grafiki, muzyka, czcionki. W celu ich uzyskania pisz na e-mail witkowski01@wp.pl



#include <cstdlib>
#include <allegro.h> 
#include "mapa.h"
using namespace std;

BITMAP *pacbmp;
BITMAP *pacman;
BITMAP *smiercbmp;

MIDI *music1;
SAMPLE *music3;
SAMPLE *smierc;
  
    


int mx = 0, my = 0, mb = 0;
void myszka()
{
    if( mx != mouse_x || my != mouse_y || mb != mouse_b )
    {
        mx = mouse_x;
        my = mouse_y;
        mb = mouse_b;
    }
};


int direction=4;


int zapami_px;           //Zmienne pamiêtaj¹ce po³o¿enie pacmana
int zapami_py;



int main();
int level_1();

//Instalacja czcionek
	FONT * font_moja = load_font( "Fonty/mojaczcionka.pcx", default_palette, NULL );
	FONT * font_moja2 = load_font( "Fonty/mojaczcionka2.pcx", default_palette, NULL );
	FONT * font_moja3 = load_font( "Fonty/mojaczcionka3.pcx", default_palette, NULL );
	



class Chead{

public:
void rysoj_postac(){

	blit(pacbmp,pacman, direction*33 , 0 , 0 , 0 , 33 , 33 );
	draw_sprite(buffer, pacman , px , py );

};

bool game_over(){
	
	int row,col;
	
	while((zycie==-2)){
				
		allegro_message("Przegrales!!!");     
		return true;
		
		}
	
		
	
	for(row=0; row<MAXWier; row++){
	
		for(col=0;col<MAXKol;col++){

			if(mapa[row][col]== 'o' )
				allegro_message("WYGRA£EŒ");
				return true;
					
		}
	
	}
	return false;
}

int koniec(){
	
destroy_bitmap( buffer );
destroy_bitmap( rock );
destroy_bitmap( serce );
destroy_bitmap( pacbmp );
destroy_bitmap( pacman );
destroy_bitmap( potion );
destroy_bitmap( smiercbmp );

destroy_bitmap( levelbmp );
destroy_bitmap( bufferAutor );
destroy_bitmap( pomocbmp );
destroy_bitmap( bufferGiniesz );
destroy_bitmap( bufferPrzegrana );

destroy_midi( music1 );
destroy_sample( music2 );
destroy_sample( music3 );
destroy_sample( smierc );



allegro_exit();
    return 0;

}

void koniecLvl(){
	Cmapa koniecLvlMap;
		for(int j = 0 ; j <= 5; j++)
		{

	        clear(pacman);
		    clear(buffer);
			koniecLvlMap.rysoj_mapa();
			draw_sprite(buffer,pacman,px,py);
			koniecLvlMap.ekran();
			rest(100); 
        }
		
		px = 30*14;
		py = 30*18;
		direction =4;
		zycie=3;
		punkty=0;
}

	};