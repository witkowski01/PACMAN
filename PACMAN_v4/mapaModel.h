//W�asno�� Konrada Witkowskiego
//Nie wyra�am zgody na kopiowanie cho� fragmentu kodu, zw�aszcza bez mojej wiedzy
//Nie za��czam plik�w potrzebnych do odpalenia gry jak grafiki, muzyka, czcionki. W celu ich uzyskania pisz na e-mail witkowski01@wp.pl


#define MAXWier 20   // wysoko�� y  , ilo�� wierszy  row
#define MAXKol  31   // szeroko�� x , ilo�� kolumn   col


char mapa[MAXWier][MAXKol]={
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "Xoooo|ooooo|ooooo|ooooo|ooooX",
  "X XXX XXXXX XXXXX XXXXX XXX X",
  "XoXXX XXXXX XXXXX XXXXX XXXoX",
  "Xoooo|oo|o | o o | o|oo|ooooX",
  "XoXXXoXXXXXX XXX XXXXXXoXXXoX",
  "Xoooo|X  XXX XXX XXX  X|ooooX",
  "XoXXXoX Xooo|ooo|oooX XoXXXoX",
  "XoXXXoXXXoXXXXzXXXXoXXXoXXXoX",
  " oooo|o|ooX   |   Xoo|oo|ooo ",
  "XXXXXXXoXoX       XoXoXXXXXXX",
  "X     XoXoXXXXXXXXXoXoX     X",
  "XXXXXXXoXooo|ooo|oooXoXXXXXXX",
  "X    |oo XXX XXX XXX |o     X",
  "X XXXoXX XXXoXXXoXXX XXoXXX X",
  "XoXXX  o| | | o | | |o  XXXoX",
  "X    |XXXX XXXXXXX XXXX|   |X",
  "XoXXXoXXXX XXXXXXX XXXX XXXoX",
  "X  o |o o | o o o | o o| o  X",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",

};