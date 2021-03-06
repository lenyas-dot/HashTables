#include <iostream>
#include "Game.h"
#include "HashTable.h"

int main() {

    string name = "metro";
    string genre = "horror";
    string date = "12.05.2015";
    string manufacturer = "4A Games";

    Game *metro = new Game(name, genre, date, manufacturer);

     cout << metro->id;




    return 0;
}
