//W³asnoœæ Konrada Witkowskiego
//Nie wyra¿am zgody na kopiowanie choæ fragmentu kodu, zw³aszcza bez mojej wiedzy
//Nie za³¹czam plików potrzebnych do odpalenia gry jak grafiki, muzyka, czcionki. W celu ich uzyskania pisz na e-mail witkowski01@wp.pl
//Chcê zwolnienie z egzaminu

#include "Cduch.h";

int level_1(){
	
	Cmapa level_1Mapa;
	Chead level_1Head;


	//Instalacja czcionek
	FONT * font_moja = load_font( "Fonty/mojaczcionka.pcx", default_palette, NULL );
	FONT * font_moja2 = load_font( "Fonty/mojaczcionka2.pcx", default_palette, NULL );
	FONT * font_moja3 = load_font( "Fonty/mojaczcionka3.pcx", default_palette, NULL );
	FONT * font36 = load_font( "Fonty/font36.pcx", default_palette, NULL );
	
	wrog A(30*17,30*9);
	wrog B(30*15,30*9);
	wrog2 C(30*13,30*9);
	wrog2 D(30*16,30*9);
	wrog2 E(30*17,30*9);
	wrog F(30*15,30*9);
	wrog G(30*13,30*9);
	wrog H(30*16,30*9);
	wrog I(30*17,30*9);
	wrog J(30*15,30*9);
	wrog K(30*13,30*9);
	wrog L(30*16,30*9);



	


//clear(pacman);
//direction = 4;

while(!key[KEY_ESC]&& level_1Head.game_over()&&!(zycie==0)){

if (direction!=4)
	play_sample(music3,100,150,1000,0);

		 zapami_px=px;             //Zmienne pamiêtaj¹ce po³o¿enie pacmana
		 zapami_py=py;
		
	if(px %15 ==0 && py % 15 == 0 ) {   //tylko ruchy pasuj¹ce do planszy

		if (key[KEY_LEFT]) direction = 0;           //ruch pacmana
		else if (key[KEY_RIGHT]) direction = 1;
		else if (key[KEY_UP]) direction = 2;
		else if (key[KEY_DOWN]) direction = 3;
		if (key[KEY_A]) direction = 0;           //ruch pacmana
		else if (key[KEY_D]) direction = 1;
		else if (key[KEY_W]) direction = 2;
		else if (key[KEY_S]) direction = 3;

		else if (key[KEY_0_PAD] & key[KEY_ALT]) zycie = zycie + 1;  // KOD NA ¯YCIE
		 
		if (direction==0){
			
			if (mapa[py/30][(px-30)/30] != 'X' )  // by pacman nie przechodzi³ przez œcianê
			px -= 30;
			else direction = 4;

		}

		if (direction==1){
			
			if (mapa[py/30][(px+30)/30] != 'X' )
			px += 30;
		    else direction = 4;


		}
		if (direction==2){
			
			if (mapa[(py-30)/30][px/30] != 'X' )
			py -= 30;
			else direction = 4;

		}
		if (direction==3){
			
			if (mapa[(py+30)/30][px/30] != 'X' )
			py += 30;
			else direction = 4;

		} 



	//TELEPORT
		if( px <= -30 ){
		    px = 870;
		}
		else if( px >= 870 ){
			px = -30;
		}



		
	clear(buffer);
	
	level_1Mapa.rysoj_mapa();
	
	

	//Wyœwietlanie iloœci punktów i ¿ycia
	textprintf_ex(buffer, font_moja3, 500, 620, makecol(255,239,0), -1, "LIFE: %d, SCORE: %d",zycie, punkty);
	//textprintf_ex(buffer, font_moja,   30, 670,  makecol(168,8,8), -1, "ALPHA VERSION v5");
	textprintf_ex(buffer, font36, 320, 640, makecol(168,8,8), -1, "WITPMAN");
	textprintf_ex( buffer, font_moja, 360, 285, makecol(168,8,8), - 1, "witkowski01" );

	level_1Head.rysoj_postac();
	A.ruch_duch();
	B.ruch_duch();
	C.ruch_duch();
	D.ruch_duch();
	E.ruch_duch();
	F.ruch_duch();
	G.ruch_duch();
	//H.ruch_duch();
	//I.ruch_duch();
	//J.ruch_duch();
	//K.ruch_duch();
	//L.ruch_duch();


level_1Mapa.ekran();

rest(predkosc);// prêdkoœæ  im mniejsza liczba tym szybciej siê chodzi
	
		  clear(pacman);
		           blit(pacbmp,pacman, 4*33 , 0 , 0 , 0 , 33 , 33 );
	               draw_sprite(buffer, pacman , px , py );

				  level_1Mapa.ekran();
				      rest(predkosc);  //dalsza czêœæ do prêkoœci


	}


	if((key[KEY_N])&&(key[KEY_M])&&(key[KEY_5])){punkty+=100;}



  if(punkty>=127)
    {
		while(!key[KEY_ENTER]/*&&!key[KEY_ESC]*/){
		
        //allegro_message("Wygrales!!!");
		punkty=0;
       bufferLevel=levelbmp;
					FONT * fontMenu = load_font( "Fonty/mojaczcionka.pcx", default_palette, NULL );
					FONT * fontMenu1 = load_font( "Fonty/mojaczcionka3.pcx", default_palette, NULL );
					
										
					textprintf_ex(bufferLevel, fontMenu,   30, 670,  makecol(168,8,8), -1, "FINAL-BETA VERSION");
					textprintf_ex( bufferLevel, fontMenu1, 350, 0, makecol( 168,8,8 ), - 1, "ENTER - cofnij" );
					blit( bufferLevel, screen, 0, 0, 0, 0,880,700);
					
					       
					
					};

		
		//allegro_exit();
		return 0;
    }

  if(zycie<=0)
    {
		while(!key[KEY_ENTER]/*&&!key[KEY_ESC]*/){
		
        //allegro_message("Wygrales!!!");
		punkty=0;
       bufferPrzegrana=przegranabmp;
					FONT * fontMenu = load_font( "Fonty/mojaczcionka.pcx", default_palette, NULL );
					FONT * fontMenu1 = load_font( "Fonty/mojaczcionka3.pcx", default_palette, NULL );
					
										
					textprintf_ex(bufferPrzegrana, fontMenu,   30, 670,  makecol(168,8,8), -1, "FINAL-BETA VERSION");
					textprintf_ex( bufferPrzegrana, fontMenu1, 350, 0, makecol( 168,8,8 ), - 1, "ENTER - cofnij" );
					blit( bufferPrzegrana, screen, 0, 0, 0, 0,880,700);
					
					       
					
					};

		
		//allegro_exit();
		return 0;
	  }


}


//koniec();

}

