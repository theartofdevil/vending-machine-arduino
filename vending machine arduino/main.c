#include <LiquidCrystal.h>

static int PARA_5 = 20;
static int PARA_10 = 20;
static int PARA_20 = 10;
static int PARA_50 = 30;
static int PARA_100 =5;

int para5 , para10 , para20 , para50 ,para100;

int Button1_State = 0;
int Button2_State = 0;
int Button3_State = 0;
int Button4_State = 0;
int Button5_State = 0;
int Button6_State = 0;

int button1_Click =0;
int button2_Click =0;
int button3_Click =0;
int button4_Click =0;
int button5_Click =0;
int button6_Click =0;

struct hizmet{
  int HizmetID;
  char HizmetAd;
  int KalanHizmet;
  int HizmetFiyati;
};


struct hizmet hizmet1;
struct hizmet hizmet2;
struct hizmet hizmet3;
struct hizmet hizmet4;

int h1 = 0 , h2 = 0 , h3 = 0 , h4 = 0;
int cash , paid , serviceAmount , moneyBack;

LiquidCrystal lcd (12,11,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,4);
  pinMode(A1,OUTPUT); // red light
  pinMode(A0,OUTPUT); // green light

  pinMode(13,INPUT);
  pinMode(10,INPUT);
  pinMode(9,INPUT);
  pinMode(8,INPUT);
  pinMode(1,INPUT);
  pinMode(0,INPUT);
  
  hizmet1.HizmetID = 1;
  //hizmet1.HizmetAd = "kopukleme";
  hizmet1.KalanHizmet = 30;
  hizmet1.HizmetFiyati = 15;

  hizmet2.HizmetID = 2;
  //hizmet2.HizmetAd = "yikama" ;
  hizmet2.KalanHizmet = 50;
  hizmet2.HizmetFiyati = 10 ;

  hizmet3.HizmetID = 3;
  //hizmet3.HizmetAd = "kurulama" ;
  hizmet3.KalanHizmet = 100;
  hizmet3.HizmetFiyati = 5 ;

  hizmet4.HizmetID = 4;
  //hizmet4.HizmetAd = "cilalama" ;
  hizmet4.KalanHizmet = 20 ;
  hizmet4.HizmetFiyati = 50 ;

  cash = (PARA_5*5)+(PARA_10*10)+(PARA_20*20)+(PARA_50*50)+(PARA_100*100);
  paid = 0;
  serviceAmount = 0;
  para5 = 0;
  para10 = 0;
  para20 = 0;
  para50 = 0;
  para100 = 0;
  moneyBack = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  Button1_State = digitalRead(13);
  Button2_State = digitalRead(10);
  Button3_State = digitalRead(9);
  Button4_State = digitalRead(8);
  Button5_State = digitalRead(1);
  Button6_State = digitalRead(0);

  if( button6_Click == 0 ) {

    if( Button1_State == 1){
    lcd.clear();
    lcd.print(" 5 TL attiniz   ");
    button1_Click ++ ;
    PARA_5 ++;
    cash += 5;
    paid += 5;
    delay(1000);
    lcd.print(PARA_5);
  }

   if( Button2_State == 1){
    lcd.clear();
    lcd.print(" 10 TL attiniz" );
    delay(150);
    button2_Click ++;
    PARA_10 ++ ;
    cash += 10 ;
    paid += 10;
    delay(1000);
    lcd.print(PARA_10);
  }
   if( Button3_State == 1){
    lcd.clear();
    lcd.print("20 TL attiniz ");
    delay(150);
    button3_Click ++;
    PARA_20 ++ ;
    cash += 20;
    paid += 20;
    delay(1000);
    lcd.print(PARA_20);
  }
   if( Button4_State == 1){
    lcd.clear();
    lcd.print(" 50 TL attiniz" );
    delay(150);
    button4_Click ++;
    PARA_50 ++ ;
    cash +=50 ;
    paid += 50;
    delay(1000);
    lcd.print(PARA_50);
  }

   if( Button5_State == 1){
    lcd.clear();
    lcd.print(" 100 TL attiniz ");
    delay(150);
    button5_Click ++ ;
    PARA_100 ++ ;
    cash += 100;
    paid += 100;
    delay(1000);
    lcd.print(PARA_100);
  }

   if( Button6_State == 1){
    lcd.clear();
    lcd.print("hizmet secimi icin tuslara basizniz");
    delay(150);
    button6_Click ++;
    delay(1000);
  }

  
  }
  
  if( button6_Click ==1 ){

   if(Button1_State == 1 ){
      if( h1 <= hizmet1.KalanHizmet ){
           lcd.clear();
           lcd.print("kopukleme yapildi.  ");
          lcd.print(hizmet1.HizmetFiyati);
          lcd.print(" TL  ");
          delay(150);
          h1 ++;
          serviceAmount += 15;
          delay(700);
    }
    if( h1 > hizmet1.KalanHizmet){
     lcd.clear();
      lcd.print("kopukleme hizmeti bitti :(");
   }
  }

  if( Button2_State == 1){

    if( h2 <= hizmet2.KalanHizmet ){
      lcd.clear();
      lcd.print(" yikama yapildi .  ");
      lcd.print(hizmet2.HizmetFiyati);
      lcd.print(" TL ");
      delay(150);
      h2 ++;
      serviceAmount += 10;
      delay(700);
    }

    if( h2> hizmet2.KalanHizmet ){
      lcd.clear();
      lcd.print(" yikama hizmeti bitti :(");
    }
  }

  if( Button3_State == 1){

    if( h3 <= hizmet3.KalanHizmet ) {
      lcd.clear();
      lcd.print("kurulama yapildi.  ");
      lcd.print( hizmet3.HizmetFiyati);
      lcd.print(" TL ");
      delay(150);
      h3 ++ ;
      serviceAmount += 5;
      delay(700);
    }

    if ( h3 > hizmet3.KalanHizmet ) {
      lcd.clear();
      lcd.print("kurulama hizmeti bitti :(");
    }
  }

  if ( Button4_State == 1 ){

    if( h4 <= hizmet4.KalanHizmet ){
      lcd.clear();
      lcd.print ("cilalama yapildi.  ");
      lcd.print(hizmet4.HizmetFiyati);
      lcd.print(" TL ");
      delay(150);
      h4 ++;
      serviceAmount += 50;
      delay(700);
    }

    if( h4 > hizmet4.KalanHizmet ) {
      lcd.clear();
      lcd.print("cilalama sayisi bitti :(");
    }
  }

  if( Button5_State == 1 ){
    int number ;
    number = rand()%4 + 1 ;
    if ( number == 2 ){
      digitalWrite(A1,HIGH);
      delay(4000);
      lcd.clear();
      lcd.print("para sikisti ");
      lcd.print(paid);
      lcd.print(" iade");
      delay(300);
      digitalWrite(A1,LOW);
    }
    if( number != 2){
      digitalWrite(A0,HIGH);
      delay(4000);
      if( cash -( paid - serviceAmount ) >= 0 ) {
        moneyBack = ( paid - serviceAmount ) ;
       while( PARA_100 >0 && moneyBack >= 100){
        para100++;
        moneyBack -= 100;
       }
       while ( PARA_50 > 0 && moneyBack >= 50){
        para50++;
        moneyBack -=50;
       }
       while ( PARA_20 > 0 && moneyBack >= 20){
        para20++;
        moneyBack -= 20;
       }
       while(PARA_10 > 0 && moneyBack >= 10){
        para10++;
        moneyBack -= 10;
       }
       while( PARA_5 > 0 && moneyBack >= 5){
        para5++;
        moneyBack -=5;
       }

       lcd.clear();
       lcd.print(para100);
       lcd.print(" ");
       lcd.print(para50);
       lcd.print(" ");
       lcd.print(para20);
       lcd.print(" ");
       lcd.print(para10);
       lcd.print(" ");
       lcd.print(para5);
       lcd.print(" ");
       delay(150);
       lcd.print(serviceAmount);
      }

      else if( cash -( paid - serviceAmount ) < 0 ){
        lcd.clear();
        lcd.print("yetersiz bakiye");
      }
    }
  }

  if ( Button6_State == 1 ){
    lcd.clear();
    lcd.print("hizmet resetleme yapildi");
    h1 = 0;
    h2 = 0;
    h3 = 0;
    h4 = 0;
    delay(1000);
  }
  
 }
 
}
