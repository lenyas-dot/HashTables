#include <iostream>
#include "Game.h"
#include "HashTable.h"

int main() {

    string name = "metro";
    string genre = "horror";
    string date = "02.05.2015";
    string manufacturer = "4A Games";
    Game metro1(name, genre, date, manufacturer);
    Game metro(name, genre, date, manufacturer);

    HashTable table(10);

    for (int i=1;i<10;i++) {
        table.Add(metro);
        metro.name[0]--;
        metro.date[0]++;
    }

    table.Add(metro);
    cout << table;

 /*   name = "GTA V";
    genre = "Casual";
    date = "12.12.2014";
    manufacturer = "Rockstar Games";
    Game gta(name, genre, date, manufacturer);
    table.Add(gta);
    table.Add(gta);
    table.Add(gta);
    table.Add(gta);
    table.Add(gta);
*/

    //cout << table;
    table.Delete(metro1);
    cout << table;
    for (int i=1;i<10;i++) {
        table.Delete(metro1);
        metro1.name[0]-=2;
        metro1.date[0]+=2;
    }

    cout << table;


    return 0;

}
