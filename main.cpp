#include <iostream>
#include "Game.h"
#include "HashTable.h"

int main() {

    string name = "metro";
    string genre = "horror";
    string date = "12.05.2015";
    string manufacturer = "4A Games";

    Game metro(name, genre, date, manufacturer);

    HashTable table(5);
    table.Add(metro);

    name = "GTA";
    genre = "Casual";
    date = "12.12.2014";
    manufacturer = "Rockstar Games";
    Game gta(name, genre, date, manufacturer);
    table.Add(gta);
    table.Add(gta);
    table.Add(gta);
    table.Add(gta);
    table.Add(gta);


    cout << table;

    table.Delete(metro);

    cout << table;

    table.Delete(gta);

    cout << table;

    return 0;
}
