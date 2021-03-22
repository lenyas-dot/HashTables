#include <iostream>
#include "Game.h"
#include "HashTable.h"

int main() {
    setlocale(LC_ALL, "Russian");
    string name = "metro";
    string genre = "horror";
    string date = "02.05.2015";
    string manufacturer = "4A Games";
    Game metro1(name+'1', genre, date, manufacturer);
    Game metro(name+'2', genre, date, manufacturer);

    HashTable table(23, 80);
   for (int i=1;i<10;i++) {
        table.Add(metro);
        metro.name[0]-=1;
        metro.date[0]+=1;
       table.Add(metro1);
        metro1.name[0]-=1;
        metro1.date[0]+=1;
    }

   // table.Add(metro);
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
        metro1.name[0]+=3;
        metro1.date[0]-=3;
    }
    cout << table;
    metro1.manufacturer="00";
    for (int i=1;i<10;i++) {

        table.Add(metro1);
        metro1.name[0]+=1;
        metro1.date[0]-=1;
        }

    // table.Add(metro);
    cout << table;




    return 0;

}
