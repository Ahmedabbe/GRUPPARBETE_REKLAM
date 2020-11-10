#include <stdio.h>
#include <stdbool.h>

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
    int numOfCustomers;
    int totalMoney;
}STATE;

CUSTOMER lista[5];


void setup()
{
    STATE state;
    start(&state);

}
void start(STATE* state) //den h?r startar upp alla customers och k?rs en g?ng i setup den l?gger ?ven till alla i v?r lista som vi anv?nder i winner().
{
    CUSTOMER harry;
    strcpy(harry.name, "Hederlige Harrys Bilar");
    harry.money = 5000;
    strcpy(harry.mesages[0], "K?p bil hos Harry");
    strcpy(harry.mesages[1], "En god bilaff?r(f?r Harry!)");
    strcpy(harry.mesages[2], "Hederlige Harrys Bilar");
    /* for (int i = 0; i < 3; i++)
     {
         printf(harry.mesages[i]);

     }*/
    CUSTOMER farmor;
    strcpy(farmor.name, "Farmor Ankas Pajer AB");
    farmor.money = 3000;
    strcpy(farmor.mesages[0], "K?p paj hos Farmor Anka"); //Scroll
    strcpy(farmor.mesages[1], "Skynda innan M?rten ?tit alla pajer");//Text

    CUSTOMER petter;
    strcpy(petter.name, "Svarte Petters Svartbyggen");
    petter.money = 1500;
    strcpy(petter.mesages[0], "L?t Petter bygga ?t dig"); //j?mna minuter scroll
    strcpy(petter.mesages[1], "Bygga svart? Ring Petter"); //oj?mna minuter


    CUSTOMER l?ngben;
    l?ngben.money = 4000;
    strcpy(l?ngben.name, "L?ngbens detektivbyr?");
    strcpy(l?ngben.mesages[0], "Mysterier? Ring L?ngben");
    strcpy(l?ngben.mesages[1], "L?ngben fixar biffen");


    CUSTOMER self;
    self.money = 1000;
    strcpy(self.name, "Oss sj?lva");
    strcpy(self.mesages[0], "Synas h?r? IoT:s Reklambyr?");


    lista[0] = self;
    lista[1] = petter;
    lista[2] = farmor;
    lista[3] = l?ngben;
    lista[4] = harry;


}

int totalMoneyz(STATE* state)// den h?r r?knar bara ut totalt antal pengar, summerar alltihop.
{
    int allTheMoney;
    for (int i = 0; i < state->numOfCustomers; i++)
    {
        allTheMoney += state->allCustomers[i].money;
    }
    return allTheMoney;

}
void handleWinner(STATE* state, CUSTOMER* winnerCustomer)//det h?r ?r en mall f?r hur vi ska h?mta messages fr?n varje customer. Vi ska g?ra en s?n h?r f?r varje customer
{
    int randomIndex = random(0, 6);//det h?r ?r f?r att vi har 5 m?jliga messages i v?r struct.
    char getMessage[50];
    strcpy(getMessage, winnerCustomer->mesages[randomIndex]);
    Printf("");
    //Serial.println(getMessage);
    //lcd.print(getMessage)

}

void winner(STATE* state, int allTheMoney)// den h?r v?ljer ut en vinnare och s?tter v?r winningCustomer som det index i listan som vi tilldelade innan..
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