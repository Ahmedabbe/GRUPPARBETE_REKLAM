// Visual Micro is in vMicro>General>Tutorial Mode
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int Li = 16;
int Lii = 0;

typedef struct
{
  char name[15];
  char messages[3][30];

} CUSTOMER;

CUSTOMER lista[5];

bool notSame[5] = {1, 1, 1, 1, 1};

void setup()
{
  Serial.begin(9600);
  start();
  lcd.begin(16, 2);
}
void start() //den her startar upp alla customers och kors en gang i setup den legger even till alla i var lista som vi anvender i winner().
{
  CUSTOMER harry;
  strcpy(harry.name, "Hederlige Harrys Bilar");
  //harry.money = 5000;
  strcpy(harry.messages[0], "Kop bil hos Harry");
  strcpy(harry.messages[1], "En god bilaffer\n(for Harry!)");
  strcpy(harry.messages[2], "Hederlige\nHarrys Bilar");

  CUSTOMER farmor;
  strcpy(farmor.name, "Farmor Ankas Pajer AB");
  //farmor.money = 3000;
  strcpy(farmor.messages[0], "Kop paj hos \nFarmor Anka"); //Scroll
  strcpy(farmor.messages[1], "Skynda innan Marten etit alla pajer");//Text

  CUSTOMER petter;
  strcpy(petter.name, "Svarte Petters Svartbyggen");
  //petter.money = 1500;
  strcpy(petter.messages[0], "Lat Petter bygga at dig"); //jemna minuter scroll
  strcpy(petter.messages[1], "Bygga svart? \nRing Petter"); //ojemna minuter

  CUSTOMER langben;
  //langben.money = 4000;
  strcpy(langben.name, "Langbens detektivbyra");
  strcpy(langben.messages[0], "Mysterier? \nRing Langben");
  strcpy(langben.messages[1], "Langben fixar \nbiffen");

  CUSTOMER self;
  //self.money = 1000;
  strcpy(self.name, "Oss sjelva");
  strcpy(self.messages[0], "Synas her? #IoT:s Reklambyra");

  lista[0] = self;
  lista[1] = petter;
  lista[2] = farmor;
  lista[3] = langben;
  lista[4] = harry;
}
void DisplayDelay()
{
  delay(10000);
}
void DisplaySelf()
{
  lcd.setCursor(3, 0);
  lcd.print("Synas Her?");
  for (int i = 0; i < 67; i++)
  {
    lcd.print(ScrollLeft("#Camilos Reklambyra :D"));
    delay(300);
  }
  lcd.clear();
}
String ScrollLeft(String str_display)
{
  lcd.setCursor(15, 1);
  String result;
  String str_process = "                " + str_display + "                ";
  result = str_process.substring(Li, Lii);
  Li++;
  Lii++;
  Serial.println(Li);
  Serial.println(Lii);
  if (Li > str_process.length())
  {
    Li = 16;
    Lii = 0;
  }
  return result;
}
void BlinkText(String message)
{
  for (int i = 0; i < 20; i++)
  {
    if (message.length() > 16)
    {
      lcd.setCursor(0, 0);
      int counter = 0;
      for (int i = 0; i < 16; i++)
      {
        if (message[i] == '\n')
        {
          break;
        }
        lcd.print(message[i]);
        counter ++;
      }
      lcd.setCursor(0, 1);
      for (int i = counter + 1; i < message.length(); i++)
      {
        lcd.print(message[i]);
      }
      delay(500);
      lcd.clear();
      delay(500);
    }
  }
}
void DisplayText(String message)
{
  if (message.length() > 16)
  {
    lcd.setCursor(0, 0);
    int counter = 0;
    for (int i = 0; i < 16; i++)
    {
      if (message[i] == '\n')
      {
        break;
      }
      lcd.print(message[i]);
      counter ++;
    }
    lcd.setCursor(0, 1);
    for (int i = counter + 1; i < message.length(); i++)
    {
      lcd.print(message[i]);
    }
  }
  else
  {
    lcd.print(message);
  }
  DisplayDelay();
  lcd.clear();
}
void GetHarrys()//det her er en mall for hur vi ska hemta messages fran varje customer. Vi ska gora en san her for varje customer
{
  int randomIndex = random(0, 3);//det her er for att vi har 5 mojliga messages i var struct.
  String getMessage = lista[4].messages[randomIndex];
  //strcpy(getMessage, lista[4].messages[randomIndex]);
  switch (randomIndex + 1)
  {
    case 1:
      for (int i = 0; i < getMessage.length() + 67; i++)
      {
        lcd.print(ScrollLeft(getMessage));
        delay(300);
      }
      lcd.clear();
      break;
    case 2:
      DisplayText(getMessage);
      break;
    case 3:
      BlinkText(getMessage);
      break;
  }
}
void GetFarmor()
{
  int randomIndex = random(0, 2); //det her er for att vi har 5 mojliga messages i var struct.
  String getMessage = lista[2].messages[randomIndex];
  //strcpy(getMessage, lista[2].messages[randomIndex]);
  switch (randomIndex + 1)
  {
    case 1:
      DisplayText(getMessage);
      break;
    case 2:
      for (int i = 0; i < (getMessage.length() + 67); i++)
      {
        lcd.print(ScrollLeft(getMessage));
        delay(300);
      }
      lcd.clear();
      break;
  }
}
void GetPetter()
{
  int minute = random(0, 61);
  if (minute % 2 == 0)
  {
    String getMessage = lista[1].messages[0];
    //strcpy(getMessage, lista[1].messages[0]);
    for (int i = 0; i < getMessage.length() + 67; i++)
    {
      lcd.print(ScrollLeft(getMessage));
      delay(300);
    }
    lcd.clear();
  }
  else
  {
    String getMessage = lista[1].messages[1];
    //strcpy(getMessage, lista[1].messages[1]);
    DisplayText(getMessage);
  }
}
void GetLangben()
{
  int hour = random(0, 24);
  if (hour >= 6 && hour < 17)
  {
    String getMessage = lista[3].messages[0];
    //strcpy(getMessage, lista[3].messages[0]);
    DisplayText(getMessage);
  }
  else
  {
    String getMessage = lista[3].messages[1];
    //strcpy(getMessage, lista[3].messages[1]);
    DisplayText(getMessage);
  }
}
void GetSelf()
{
  String getMessage = lista[0].messages[0];
  //strcpy(getMessage, lista[0].messages[0]);
  DisplayText(getMessage);
}
void winner() // den her veljer ut en vinnare och setter var winningCustomer som det index i listan som vi tilldelade innan..
{
  int randNum = random(0, (14501));
  if (randNum <= 1000)
  {
    if (notSame[0])
    {
      DisplaySelf();
      char selfArray[5] = {0, 1, 1, 1, 1};
      memcpy(notSame, selfArray, 5);
    }
  }
  else if (randNum > 1000 && randNum <= 2500)
  {
    if (notSame[1])
    {
      GetPetter();
      char petterArray[5] = {1, 0, 1, 1, 1};
      memcpy(notSame, petterArray, 5);
    }
  }
  else if (randNum > 2500 && randNum <= 5500)
  {
    if (notSame[2])
    {
      GetFarmor();
      char farmorArray[5] = {1, 1, 0, 1, 1};
      memcpy(notSame, farmorArray, 5);
    }
  }
  else if (randNum > 5500 && randNum <= 9500)
  {
    if (notSame[3])
    {
      GetLangben();
      char langbenArray[5] = {1, 1, 1, 0, 1};
      memcpy(notSame, langbenArray, 5);
    }
  }
  else
  {
    if (notSame[4])
    {
      GetHarrys();
      char harryArray[5] = {1, 1, 1, 1, 0};
      memcpy(notSame, harryArray, 5);
    }
  }
}
// Add the main program code into the continuous loop() function
void loop()
{
  winner();
}
