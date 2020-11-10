// Visual Micro is in vMicro>General>Tutorial Mode
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
/*
    Name:       Reklam.ino
    Created:  2020-11-09 13:46:46
    Author:     LAPTOP-KD93PMUU\willi
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
//#include <LiquidCrystal.h>

typedef struct
{
  char name[15];
  char mesages[3][30];
  int money;

} CUSTOMER;
typedef struct
{
  CUSTOMER* allCustomers;
  //int numOfCustomers;
  //int totalMoney;
} STATE;

CUSTOMER lista[5];

STATE state;
CUSTOMER winnerCustomer;

void setup()
{
  Serial.begin(9600);
  start(&state, &winnerCustomer);
  lcd.begin(16, 2);

}
void start(STATE* state, CUSTOMER* winnerCustomer) //den her startar upp alla customers och kors en gang i setup den legger even till alla i var lista som vi anvender i winner().
{
  CUSTOMER harry;
  strcpy(harry.name, "Hederlige Harrys Bilar");
  harry.money = 5000;
  strcpy(harry.mesages[0], "Kop bil hos Harry");
  strcpy(harry.mesages[1], "En god bilaffer(for Harry!)");
  strcpy(harry.mesages[2], "Hederlige Harrys Bilar");
  /* for (int i = 0; i < 3; i++)
    {
       printf(harry.mesages[i]);
    }*/
  CUSTOMER farmor;
  strcpy(farmor.name, "Farmor Ankas Pajer AB");
  farmor.money = 3000;
  strcpy(farmor.mesages[0], "Kop paj hos Farmor Anka"); //Scroll
  strcpy(farmor.mesages[1], "Skynda innan Marten etit alla pajer");//Text

  CUSTOMER petter;
  strcpy(petter.name, "Svarte Petters Svartbyggen");
  petter.money = 1500;
  strcpy(petter.mesages[0], "Lat Petter bygga at dig"); //jemna minuter scroll
  strcpy(petter.mesages[1], "Bygga svart? Ring Petter"); //ojemna minuter


  CUSTOMER langben;
  langben.money = 4000;
  strcpy(langben.name, "Langbens detektivbyra");
  strcpy(langben.mesages[0], "Mysterier? Ring Langben");
  strcpy(langben.mesages[1], "Langben fixar biffen");


  CUSTOMER self;
  self.money = 1000;
  strcpy(self.name, "Oss sjelva");
  strcpy(self.mesages[0], "Synas her? #IoT:s Reklambyra");


  lista[0] = self;
  lista[1] = petter;
  lista[2] = farmor;
  lista[3] = langben;
  lista[4] = harry;


}

/*int totalMoneyz(STATE* state)// den her reknar bara ut totalt antal pengar, summerar alltihop.
  {
    int allTheMoney;
    for (int i = 0; i < state->numOfCustomers; i++)
    {
        allTheMoney += state->allCustomers[i].money;
    }
    return allTheMoney;

  }*/
void handleWinner(STATE* state, CUSTOMER* winnerCustomer)//det her er en mall for hur vi ska hemta messages fran varje customer. Vi ska gora en san her for varje customer
{
  int randomIndex = random(0, 6);//det her er for att vi har 5 mojliga messages i var struct.
  char getMessage[30];
  strcpy(getMessage, winnerCustomer->mesages[randomIndex]);
  lcd.print(getMessage);
  delay(4000);
  for (int positionCounter = -16; positionCounter < 32; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(200);
    lcd.clear();
  }
}

void GetHarrys()//det her er en mall for hur vi ska hemta messages fran varje customer. Vi ska gora en san her for varje customer
{
  int randomIndex = random(0, 3);//det her er for att vi har 5 mojliga messages i var struct.
  char getMessage[30];
  strcpy(getMessage, lista[4].mesages[randomIndex]);
  char blank[16] = "                ";
  
  switch (randomIndex + 1) {
    case 1:
     lcd.print(blank);
     lcd.print(getMessage);
      for (int positionCounter = 0; positionCounter < 32; positionCounter++)
      {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        Serial.print(positionCounter);
        // wait a bit:
        delay(300);      
      }
      
      lcd.print(blank);
      lcd.clear();
      break;
    case 2:
      if (strlen(getMessage) > 16)
      {
        lcd.setCursor(0, 0);
        for (int i = 0; i < 16; i++)
        {
          lcd.print(getMessage[i]);
        }
        lcd.setCursor(0, 1);
        for (int i = 16; i < strlen(getMessage); i++)
        {
          lcd.print(getMessage[i]);
        }
      }
      else
      {
        lcd.print(getMessage);
      }
      delay(4000);
      lcd.clear();
      break;
    case 3:
      //lcd.clear();
      for (int i = 0; i < 4; i++)
      {
        if (strlen(getMessage) > 16)
      {
        lcd.setCursor(0, 0);
        for (int i = 0; i < 16; i++)
        {
          lcd.print(getMessage[i]);
        }
        lcd.setCursor(0, 1);
        for (int i = 16; i < strlen(getMessage); i++)
        {
          lcd.print(getMessage[i]);
        }
        //lcd.print(getMessage);
        delay(1000);
        lcd.clear();
        delay(1000);
      }
      lcd.clear();
      break;
  }
}
}
void GetFarmor()
  {

   int randomIndex = random(0,2);//det her er for att vi har 5 mojliga messages i var struct.
   char getMessage[30];
   strcpy(getMessage, lista[2].mesages[randomIndex]);
   char blank[16] = "                ";
   switch(randomIndex +1)
   {
    case 1:
     lcd.print(blank);
     lcd.print(getMessage);
      for (int positionCounter = 0; positionCounter < 32; positionCounter++)
      {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        Serial.print(positionCounter);
        // wait a bit:
        delay(300);      
      }
      
      lcd.print(blank);
      lcd.clear();
      break;
     case 2:
      if (strlen(getMessage) > 16)
      {
        lcd.setCursor(0, 0);
        for (int i = 0; i < 16; i++)
        {
          lcd.print(getMessage[i]);
        }
        lcd.setCursor(0, 1);
        for (int i = 16; i < strlen(getMessage); i++)
        {
          lcd.print(getMessage[i]);
        }
      }
      else
      {
        lcd.print(getMessage);
      }
      delay(4000);
      lcd.clear();
      break;



   }
 }
 void GetPetter()
 {
  int minute = random(0,61);
  char blank[16] = "                ";
  if(minute % 2 == 0)
  {
     char getMessage[30];
     strcpy(getMessage, lista[1].mesages[0]);
     lcd.print(blank);
     lcd.print(getMessage);
      for (int positionCounter = 0; positionCounter < 32; positionCounter++)
      {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        Serial.print(positionCounter);
        // wait a bit:
        delay(300);      
      }
      
      lcd.print(blank);
      lcd.clear();
      return;
  }
  else
  {
    char getMessage[30];
    strcpy(getMessage, lista[1].mesages[1]);
    if (strlen(getMessage) > 16)
      {
        lcd.setCursor(0, 0);
        for (int i = 0; i < 16; i++)
        {
          lcd.print(getMessage[i]);
        }
        lcd.setCursor(0, 1);
        for (int i = 16; i < strlen(getMessage); i++)
        {
          lcd.print(getMessage[i]);
        }
      }
      else
      {
        lcd.print(getMessage);
      }
      delay(4000);
      lcd.clear();
      return;
  }
  
 }
 void GetLangben()
 {
  int hour = random(0,24);
  if (hour >= 6 && hour < 17)
  {
    char getMessage[30];
    strcpy(getMessage, lista[3].mesages[0]);
    if (strlen(getMessage) > 16)
      {
        lcd.setCursor(0, 0);
        for (int i = 0; i < 16; i++)
        {
          lcd.print(getMessage[i]);
        }
        lcd.setCursor(0, 1);
        for (int i = 16; i < strlen(getMessage); i++)
        {
          lcd.print(getMessage[i]);
        }
        
      }
      else
      {
        lcd.print(getMessage);
      }
      delay(4000);
      lcd.clear();
      return;
  
  }
  else
  {
    char getMessage[30];
    strcpy(getMessage, lista[3].mesages[1]);
    if (strlen(getMessage) > 16)
      {
        lcd.setCursor(0, 0);
        for (int i = 0; i < 16; i++)
        {
          lcd.print(getMessage[i]);
        }
        lcd.setCursor(0, 1);
        for (int i = 16; i < strlen(getMessage); i++)
        {
          lcd.print(getMessage[i]);
        }
      }
      else
      {
        lcd.print(getMessage);
      }
      delay(4000);
      lcd.clear();
      return;
  }
 }
 void GetSelf()
 {
    char getMessage[30];
    strcpy(getMessage, lista[0].mesages[0]);
    if (strlen(getMessage) > 16)
      {
        lcd.setCursor(0, 0);
        for (int i = 0; i < 16; i++)
        {
          lcd.print(getMessage[i]);
        }
        lcd.setCursor(0, 1);
        for (int i = 16; i < strlen(getMessage); i++)
        {
          lcd.print(getMessage[i]);
        }
      }
      else
      {
        lcd.print(getMessage);
      }
      delay(4000);
      lcd.clear();
      return;
 }


void winner(STATE * state) // den her veljer ut en vinnare och setter var winningCustomer som det index i listan som vi tilldelade innan..
{
  //int allTheMoney = totalMoneyz(state);
  int randNum = random(0, (14501));
  if (randNum <= 1000)
  {
    winnerCustomer = lista[0];
    GetSelf();
  }
  else if (randNum > 1000 && randNum <= 2500)
  {
    winnerCustomer = lista[1];
    GetPetter();
  }
  else if (randNum > 2500 && randNum <= 5500)
  {
    winnerCustomer = lista[2];
    GetFarmor();
  }
  else if (randNum > 5500 && randNum <= 9500)
  {
    winnerCustomer = lista[3];
    GetLangben();
  }
  else
  {
    winnerCustomer = lista[4];
    GetHarrys();
  }
  handleWinner(state, &winnerCustomer);

}

// Add the main program code into the continuous loop() function
void loop()
{
  
  winner(&state);
}
