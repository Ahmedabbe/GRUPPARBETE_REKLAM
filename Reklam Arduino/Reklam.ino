// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       Reklam.ino
    Created:	2020-11-09 13:46:46
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
    char name[50];
    char mesages[5][50];
    //char messages2[200];
    int money;

}CUSTOMER;
typedef struct
{
    CUSTOMER* allCustomers;
    int numOfCustomers = 5;
    int totalMoney;
}STATE;

CUSTOMER lista[5];


void setup()
{
    STATE state;
    start(&state);
    
}
void start(STATE* state) //den här startar upp alla customers och körs en gång i setup den lägger även till alla i vår lista som vi använder i winner().
{
    CUSTOMER harry;
    strcpy(harry.name, "Hederlige Harrys Bilar");
    harry.money = 5000;
    strcpy(harry.mesages[0], "Köp bil hos Harry");
    strcpy(harry.mesages[1], "En god bilaffär(för Harry!)");
    strcpy(harry.mesages[2], "Hederlige Harrys Bilar");
    /* for (int i = 0; i < 3; i++)
     {
         printf(harry.mesages[i]);

     }*/
    CUSTOMER farmor;
    strcpy(farmor.name, "Farmor Ankas Pajer AB");
    farmor.money = 3000;
    strcpy(farmor.mesages[0], "Köp paj hos Farmor Anka"); //Scroll
    strcpy(farmor.mesages[1], "Skynda innan Mårten ätit alla pajer");//Text

    CUSTOMER petter;
    strcpy(petter.name, "Svarte Petters Svartbyggen");
    petter.money = 1500;
    strcpy(petter.mesages[0], "Låt Petter bygga åt dig"); //jämna minuter scroll
    strcpy(petter.mesages[1], "Bygga svart? Ring Petter"); //ojämna minuter


    CUSTOMER långben;
    långben.money = 4000;
    strcpy(långben.name, "Långbens detektivbyrå");
    strcpy(långben.mesages[0], "Mysterier? Ring Långben");
    strcpy(långben.mesages[1], "Långben fixar biffen");


    CUSTOMER self;
    self.money = 1000;
    strcpy(self.name, "Oss själva");
    strcpy(self.mesages[0], "Synas här? IoT:s Reklambyrå");


    lista[0] = self;
    lista[1] = petter;
    lista[2] = farmor;
    lista[3] = långben;
    lista[4] = harry;


}

int totalMoneyz(STATE* state)// den här räknar bara ut totalt antal pengar, summerar alltihop.
{
    int allTheMoney;
    for (int i = 0; i < state->numOfCustomers; i++)
    {
        allTheMoney += state->allCustomers[i].money;
    }
    return allTheMoney;

}
void handleWinner(STATE* state, CUSTOMER* winnerCustomer)//det här är en mall för hur vi ska hämta messages från varje customer. Vi ska göra en sån här för varje customer
{
    int randomIndex = random(0, 6);//det här är för att vi har 5 möjliga messages i vår struct.
    char getMessage[50];
    strcpy(getMessage, winnerCustomer->mesages[randomIndex]);
    Serial.println(getMessage);
    lcd.print(getMessage)
    
}

void winner(STATE* state, int allTheMoney)// den här väljer ut en vinnare och sätter vår winningCustomer som det index i listan som vi tilldelade innan..
{
    CUSTOMER winnerCustomer;
    allTheMoney = totalMoneyz(state);
    int randNum = random(0, (allTheMoney + 1));
    if (randNum <= 1000)
    {
        winnerCustomer = lista[0];
    }
    else if (randNum > 1000 && randNum <= 2500)
    {
        winnerCustomer = lista[1];
    }
    else if (randNum > 2500 && randNum <= 5500)
    {
        winnerCustomer = lista[2];
    }
    else if (randNum > 5500 && randNum <= 9500)
    {
        winnerCustomer = lista[3];
    }
    else
    {
        winnerCustomer = lista[4];
    }
    handleWinner(state, &winnerCustomer);

}

// Add the main program code into the continuous loop() function
void loop()
{
    

}
