//W³asnoœæ Konrada Witkowskiego
//Nie wyra¿am zgody na kopiowanie choæ fragmentu kodu, zw³aszcza bez mojej wiedzy
//Nie za³¹czam plików potrzebnych do odpalenia gry jak grafiki, muzyka, czcionki. W celu ich uzyskania pisz na e-mail witkowski01@wp.pl
//Chcê zwolnienie z egzaminu

#include  "initAllegro.h";
#include <iostream>



class Cmenu{
private:
	BITMAP * kursor;
    BITMAP * bufor;
    BITMAP * meni;
    BITMAP * przycisk11;
    BITMAP * przycisk13;
    BITMAP * przycisk15;
    BITMAP * przycisk2;
	BITMAP * przycisk3;
	BITMAP * przycisk32;
	BITMAP * autor;

public:

void menu(){

	Cmapa menuMapa;
	Chead menuHead;

	kursor = load_bmp( "Bitmapy/kursor.bmp", default_palette );
    install_mouse();
	
	show_mouse( screen );
    set_mouse_sprite( kursor );
    unscare_mouse();

	bufor = create_bitmap( 880,700);

    meni = load_bmp( "Bitmapy/menu.bmp", default_palette );
    przycisk11 = load_bmp( "Bitmapy/przycisk1.bmp", default_palette );
    przycisk13 = load_bmp( "Bitmapy/przycisk1.bmp", default_palette );
    przycisk15 = load_bmp( "Bitmapy/przycisk1.bmp", default_palette );
    przycisk2 = load_bmp( "Bitmapy/przycisk1.bmp", default_palette );
	przycisk3 = load_bmp( "Bitmapy/przycisk1.bmp", default_palette );
	przycisk32 = load_bmp( "Bitmapy/przycisk1.bmp", default_palette );
	serce = load_bmp("Bitmapy/serce.bmp",default_palette );

	autor = load_bmp( "Bitmapy/autor.bmp", default_palette );

    int menu = 1;
    
    while( !menu == 0 && !key[ KEY_ESC ] )
    {
        clear_to_color( bufor, makecol( 150, 150, 150 ) );
        FONT * fontMenuKlawisze = load_font( "Fonty/font24.pcx", default_palette, NULL );
        myszka();
        
        if( menu == 1 )
        {

			if( mx > 500 && mx < 650 && my < 355 && my > 325 )
            {
                masked_blit( przycisk2, meni, 0, 0, 500, 325, przycisk2->w, przycisk2->h );
                textprintf_ex( meni, fontMenuKlawisze, 490, 325, makecol( 0, 128, 0 ), - 1, " Pomoc" );
               if( mb & 1 )
				{
					bufferPomoc=pomocbmp;
					FONT * fontMenu = load_font( "Fonty/mojaczcionka.pcx", default_palette, NULL );
					FONT * fontMenu1 = load_font( "Fonty/mojaczcionka3.pcx", default_palette, NULL );
					clear(screen);
					while(!key[KEY_ENTER]/*&&!key[KEY_ESC]*/){					
						textprintf_ex(bufferPomoc, fontMenu, 30, 670, makecol(168, 8, 8), -1, "VERSION 1.0");
					textprintf_ex( bufferPomoc, fontMenu1, 350, 0, makecol( 168,8,8 ), - 1, "ENTER - cofnij" );
					blit( bufferPomoc, screen, 0, 0, 0, 0,880,700);
					
					};
					menu=1;
			   }
            }
            else
            {
                masked_blit( przycisk32, meni, 0, 0, 500, 325, przycisk32->w, przycisk32->h );
                textprintf_ex( meni, fontMenuKlawisze, 490, 325, makecol( 147,246,0 ), - 1, " Pomoc" );
            }


            if( mx > 400 && mx < 550 && my < 580 && my > 525 )
            {
                masked_blit( przycisk2, meni, 0, 0, 400, 550, przycisk2->w, przycisk2->h );
                textprintf_ex( meni, fontMenuKlawisze, 400, 550, makecol( 0, 128, 0 ), - 1, "  Start" );
                if( mb & 1 )
                {
					level_1();
                    menuMapa.Potionki_back();
					menuHead.koniecLvl();
					menu = 1;
                }
            }
            else
            {
                masked_blit( przycisk11, meni, 0, 0, 400, 550, przycisk11->w, przycisk11->h );
				textprintf_ex( meni, fontMenuKlawisze, 400, 550, makecol( 147,246,0 ), - 1, "  Start" );
            }

			////////////////////////////////////////////////////////////////
			
			if( mx > 600 && mx < 750 && my < 580 && my > 525 )
            {
                masked_blit( przycisk2, meni, 0, 0, 600, 550, przycisk2->w, przycisk2->h );
                textprintf_ex( meni, fontMenuKlawisze, 600, 550, makecol( 0, 0, 0 ), - 1, "  MODE" );
                if( mb & 1 )
                {
					predkosc=40;
					level_1();
					
if(zycie<=0)
    {
		while(!key[KEY_ENTER]/*&&!key[KEY_ESC]*/){
		
          bufferPrzegrana=przegranabmp;
					FONT * fontMenu = load_font( "Fonty/mojaczcionka.pcx", default_palette, NULL );
					FONT * fontMenu1 = load_font( "Fonty/mojaczcionka3.pcx", default_palette, NULL );
					
										
					textprintf_ex(bufferPrzegrana, fontMenu, 30, 670, makecol(168, 8, 8), -1, "VERSION 1.0");
					textprintf_ex( bufferPrzegrana, fontMenu1, 350, 0, makecol( 168,8,8 ), - 1, "ENTER - cofnij" );
					blit( bufferPrzegrana, screen, 0, 0, 0, 0,880,700);
					
		};
					
					}
                    menuMapa.Potionki_back();
					menuHead.koniecLvl();
					predkosc=70;
					menu = 1;
                }
            }
            else
            {
                masked_blit( przycisk32, meni, 0, 0, 600, 550, przycisk32->w, przycisk32->h );
				textprintf_ex( meni, fontMenuKlawisze, 600, 550, makecol( 0, 0, 0 ), - 1, "  HARD" );
            }
			
            if( mx > 500 && mx < 650 && my < 430 && my > 400 )
            {
                masked_blit( przycisk2, meni, 0, 0, 500, 400, przycisk2->w, przycisk2->h );
                textprintf_ex( meni, fontMenuKlawisze, 500, 400, makecol( 0, 128, 0 ), - 1, " Autor" );
                if( mb & 1 )
				{
					bufferAutor=autor;
					FONT * fontMenu = load_font( "Fonty/mojaczcionka.pcx", default_palette, NULL );
					FONT * fontMenu1 = load_font( "Fonty/mojaczcionka3.pcx", default_palette, NULL );
					clear(screen);
					while(!key[KEY_ENTER]/*&&!key[KEY_ESC]*/){
					
					if(menu==2){
					
					textprintf_ex(bufferAutor, fontMenu,   30, 670,  makecol(168,8,8), -1, "VERSION 1.0");
					textprintf_ex( bufferAutor, fontMenu1, 350, 0, makecol( 168,8,8 ), - 1, "ENTER - cofnij" );
					blit( bufferAutor, screen, 0, 0, 0, 0,880,700);
					
					         }
					
					};
					menu=1;
                }
            }
            else
            {
                masked_blit( przycisk13, meni, 0, 0, 500, 400, przycisk13->w, przycisk13->h );
                textprintf_ex( meni, fontMenuKlawisze, 500, 400, makecol( 147,246,0 ), - 1, " Autorzy" );

            }
            
            if( mx > 500 && mx < 650 && my < 280 && my > 250 )
            {
                masked_blit( przycisk2, meni, 0, 0, 500, 250, przycisk2->w, przycisk2->h );
                textprintf_ex( meni, fontMenuKlawisze, 500, 250, makecol( 0, 128, 0 ), - 1, " Wyjscie" );
                if( mb & 1 )
                {
					
                    menu = 0;
					//koniec();
                }
            }
            else
            {
                masked_blit( przycisk15, meni, 0, 0, 500, 250, przycisk15->w, przycisk15->h );
                textprintf_ex( meni, fontMenuKlawisze, 500, 250, makecol( 147,246,0 ), - 1, " Wyjscie" );
            }
            if( key[ KEY_ESC ] )
            {
                menu = 0;
				//koniec();
            }
            blit( meni, bufor, 0, 0, 0, 0, 880,700 );
        }
        if( key[ KEY_ENTER ] )
        {
            menu = 1;
        }
		
		
		FONT * fontMenu2 = load_font( "Fonty/mojaczcionka3.pcx", default_palette, NULL );
		//wyœwietlanie informacji o menu powinno byæ wy³¹czone niewidoczne dla klienta :D
      //  textprintf_ex( bufor, fontMenu2, 0, 0, makecol( 168,8,8 ), - 1, "menu= %d klik= %d mx= %d my=%d", menu, mb, mx, my );
       
		
		//clear_to_color( bufor, makecol( 150, 150, 150 ) );
        blit( bufor, screen, 0, 0, 0, 0,880,700);
    }
	

}


void koniecMenu(){

destroy_bitmap( bufor );
destroy_bitmap( meni );
destroy_bitmap( przycisk11 );
destroy_bitmap( przycisk13 );
destroy_bitmap( przycisk15 );
destroy_bitmap( przycisk2 );

}

};