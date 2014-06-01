//W³asnoœæ Konrada Witkowskiego
//Nie wyra¿am zgody na kopiowanie choæ fragmentu kodu, zw³aszcza bez mojej wiedzy
//Nie za³¹czam plików potrzebnych do odpalenia gry jak grafiki, muzyka, czcionki. W celu ich uzyskania pisz na e-mail witkowski01@wp.pl
//Chcê zwolnienie z egzaminu

#include "level.h";


int initAllegro(){


	allegro_init();  // inicjalizacja allegro
	
	install_keyboard();  // instalacja klawiatury
    set_color_depth(32);

	set_gfx_mode(GFX_AUTODETECT_WINDOWED,880,700,0,0);   //okienko

	//inicjalizacja muzyki z allegro

	if (install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL) !=0){
	allegro_message("ERROR: b³¹d inicjalizacji plików dŸwiêkowych\n%s");
		return 1;
	}

	//Ustawianie g³oœnioœci
	set_volume(40, 100);
	music1= load_midi("Muzyka/game_of_thrones.mid");
	music2 = load_wav("Muzyka/coin.wav");
	music3 = load_wav("Muzyka/ruch.wav");
	smierc = load_wav("Muzyka/smierc.wav");
	
	play_midi(music1,1);
	
    buffer= create_bitmap(880,700);
	if (!buffer)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora !");
        allegro_exit();
        return 0;
    }

	serce = create_bitmap(30,30);
	if (!serce)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora !");
        allegro_exit();
        return 0;
    }

	bufferAutor= create_bitmap(880,700);
	if (!buffer)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora !");
        allegro_exit();
        return 0;
    }
	bufferLevel= create_bitmap(880,700);
	if (!bufferLevel)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora !");
        allegro_exit();
        return 0;
    }

	levelbmp=load_bitmap("Bitmapy/wygrana.bmp",NULL);
	if (!levelbmp)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora Level !");
        allegro_exit();
        return 0;
    }

	bufferGiniesz= create_bitmap(880,700);
	if (!bufferGiniesz)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora Giniesz!");
        allegro_exit();
        return 0;
    }

	ginieszbmp=load_bitmap("Bitmapy/giniesz.bmp",NULL);
	if (!ginieszbmp)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora giniesz !");
        allegro_exit();
        return 0;
    }

	bufferPrzegrana= create_bitmap(880,700);
	if (!bufferPrzegrana)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora Giniesz!");
        allegro_exit();
        return 0;
    }

	przegranabmp=load_bitmap("Bitmapy/przegrana.bmp",NULL);
	if (!przegranabmp)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora przegrana !");
        allegro_exit();
        return 0;
    }

	bufferPomoc= create_bitmap(880,700);
	if (!bufferPomoc)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ buforaPomoc !");
        allegro_exit();
        return 0;
    }

	pomocbmp=load_bitmap("Bitmapy/sterowanie.bmp",NULL);
	if (!pomocbmp)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora sterownie.bmp !");
        allegro_exit();
        return 0;
    }

	rock=load_bitmap("Bitmapy/rock.bmp",NULL);
	if (!rock)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora (rock) !");
        allegro_exit();
        return 0;
    }



	pacbmp = load_bitmap("Bitmapy/pacman.bmp",NULL);
	if (!pacbmp)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora (pacbmp) !");
        allegro_exit();
        return 0;
    }


	pacman = create_bitmap(33,33);

	if (!pacman)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora (pacman) !");
        allegro_exit();
        return 0;
    }


	potion = load_bitmap("Bitmapy/potion.bmp", NULL);    //wstawianie potionka

	if (!potion)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora (potion) !");
        allegro_exit();
        return 0;
    }



	smiercbmp = load_bitmap("Bitmapy/smierc.bmp", NULL); //animacja œmierci

	if (!smiercbmp)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora (smiercbmp) !");
        allegro_exit();
        return 0;
    }

	return 0;
}