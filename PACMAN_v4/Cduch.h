//W�asno�� Konrada Witkowskiego
//Nie wyra�am zgody na kopiowanie cho� fragmentu kodu, zw�aszcza bez mojej wiedzy
//Nie za��czam plik�w potrzebnych do odpalenia gry jak grafiki, muzyka, czcionki. W celu ich uzyskania pisz na e-mail witkowski01@wp.pl

#include "Header.h";

class wrog{

private:

	BITMAP *duchbmp;
    BITMAP *duch;

	Cmapa wrogMapa;

    int fdirection;
    int _x ,  _y;


public:
	wrog(int x , int y); //KOnstruktor
	void rysoj_duch() const;
	void ruch_duch();
	void smierc_pacmana();

};

wrog::wrog(int x , int y){
	_x = x;
	_y = y;
	fdirection = rand()%4;
	duch = create_bitmap(30,30);
	pacman = create_bitmap(33,33);
    duchbmp =  load_bitmap("Bitmapy/duch_3.bmp", NULL);
}

void wrog::rysoj_duch() const{
	Cmapa rysoj_duchMapa;
	blit(duchbmp,duch, 0 , 0 , 0 , 0 , 30 , 30 );
	draw_sprite(buffer, duch , _x , _y );

}

void wrog::smierc_pacmana(){
	
	
	if(py == _y && px == _x || _y == zapami_py && _x == zapami_px){
		
		play_sample(smierc,100,150,1000,0);
		zycie--;
		
		
		for(int j = 0 ; j <= 5; j++){
			
			clear(pacman);
			clear(buffer);
			wrogMapa.rysoj_mapa();

			blit(smiercbmp,pacman, j * 33 , 0 ,0,0,33,33);
			draw_sprite(buffer,pacman,px,py);

			wrogMapa.ekran();
			rest(100); 

 		}
		/*    dostane zwolnienie to to naprawi�, w przeciwnym razie nie widz� sensu by po�wi�ca� wi�cej czasu na projekt kt�ry jak do tej pory nic mi nie da�
		bufferGiniesz=ginieszbmp;
					FONT * fontMenu = load_font( "mojaczcionka.pcx", default_palette, NULL );
					FONT * fontMenu1 = load_font( "mojaczcionka3.pcx", default_palette, NULL );
					clear(screen);
					while(!key[KEY_ENTER]/*&&!key[KEY_ESC]*///){					
					/*textprintf_ex(bufferGiniesz, fontMenu,   30, 670,  makecol(168,8,8), -1, "FINAL-BETA VERSION");
					textprintf_ex( bufferGiniesz, fontMenu1, 350, 0, makecol( 168,8,8 ), - 1, "ENTER - cofnij" );
					blit( bufferGiniesz, screen, 0, 0, 0, 0,880,700);
					*/
					//};
		//allegro_message("Straciles zycie!!!",zycie);
		px = 30*14;     //ustawienie pacmana na pozycji startowej
		py = 30*18;
		direction =4;

	}

}

void wrog::ruch_duch(){

	rysoj_duch();
	smierc_pacmana();

	if (mapa[_y/30][(_x)/30] == '|' ){
			fdirection=rand()%4;
	}

	  if (fdirection == 0 ){
		  		if (mapa[_y/30][(_x-30)/30] != 'X' ){		_x -= 30;
		}
		else fdirection = rand()%4;
	  }

	 if (fdirection == 1 ){
		        if (mapa[_y/30][(_x+30)/30] != 'X' ){    	_x += 30;
		}
		else fdirection = rand()%4;
	  }
	  if (fdirection == 2 ){
		  		if (mapa[(_y-30)/30][(_x)/30] != 'X' ){		_y -= 30;
		}
		else fdirection = rand()%4;
	  }

	   if (fdirection == 3 ){
		   		if (mapa[(_y+30)/30][(_x)/30] != 'X' ){  	_y += 30;
		}
		else fdirection = rand()%4;
	  }

//TELEPORT ducha
	   if (_x <= -30) _x = 870;
	   else if (_x >= 870) _x = -30;


}



class wrog2{

private:

	BITMAP *duchbmp;
    BITMAP *duch;

	Cmapa wrog2Mapa;

    int fdirection;
    int _x ,  _y;

public:
	wrog2(int x , int y); //KOnstruktor
	void rysoj_duch() const;
	void ruch_duch();
	void smierc_pacmana();

};

wrog2::wrog2(int x , int y){
	_x = x;
	_y = y;
	fdirection = rand()%4;
	duch = create_bitmap(30,30);
	pacman = create_bitmap(33,33);
    duchbmp =  load_bitmap("Bitmapy/duch.bmp", NULL);
}

void wrog2::rysoj_duch() const{

	blit(duchbmp,duch, 0 , 0 , 0 , 0 , 30 , 30 );
	draw_sprite(buffer, duch , _x , _y );

}

void wrog2::smierc_pacmana(){
	
	if(py == _y && px == _x || _y == zapami_py && _x == zapami_px){
		
		play_sample(smierc,100,150,1000,0);
		zycie--;
		
		
		for(int j = 0 ; j <= 5; j++){
			
			clear(pacman);
			clear(buffer);
			wrog2Mapa.rysoj_mapa();

			blit(smiercbmp,pacman, j * 33 , 0 ,0,0,33,33);
			draw_sprite(buffer,pacman,px,py);

			wrog2Mapa.ekran();
			rest(100); 

 		}
		/*      dostane zwolnienie to to naprawi�, w przeciwnym razie nie widz� sensu by po�wi�ca� wi�cej czasu na projekt kt�ry jak do tej pory nic mi nie da�
		bufferGiniesz=ginieszbmp;
					FONT * fontMenu = load_font( "mojaczcionka.pcx", default_palette, NULL );
					FONT * fontMenu1 = load_font( "mojaczcionka3.pcx", default_palette, NULL );
					clear(screen);
					while(!key[KEY_ENTER]/*&&!key[KEY_ESC]*///){				
				/*		textprintf_ex(bufferGiniesz, fontMenu,   30, 670,  makecol(168,8,8), -1, "FINAL-BETA VERSION");
					textprintf_ex( bufferGiniesz, fontMenu1, 350, 0, makecol( 168,8,8 ), - 1, "ENTER - cofnij" );
					blit( bufferGiniesz, screen, 0, 0, 0, 0,880,700);
					
					};*/
		//allegro_message("Straciles zycie!!!",zycie);
		px = 30*14;  //ustawienie pacmana na pozycji startowej
		py = 30*18;
		direction =4;

	}

}

void wrog2::ruch_duch(){

	rysoj_duch();
	smierc_pacmana();

	if (mapa[_y/30][(_x)/30] == '|' ){
			fdirection=rand()%4;
	}

	  if (fdirection == 0 ){
		  		if (mapa[_y/30][(_x-30)/30] != 'X' ){		_x -= 30;
		}
		else fdirection = rand()%4;
	  }

	 if (fdirection == 1 ){
		        if (mapa[_y/30][(_x+30)/30] != 'X' ){    	_x += 30;
		}
		else fdirection = rand()%4;
	  }
	  if (fdirection == 2 ){
		  		if (mapa[(_y-30)/30][(_x)/30] != 'X' ){		_y -= 30;
		}
		else fdirection = rand()%4;
	  }

	   if (fdirection == 3 ){
		   		if (mapa[(_y+30)/30][(_x)/30] != 'X' ){  	_y += 30;
		}
		else fdirection = rand()%4;
	  }

//TELEPORT ducha
	   if (_x <= -30) _x = 870;
	   else if (_x >= 870) _x = -30;


}