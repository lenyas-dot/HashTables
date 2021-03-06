#include "string.h"
#pragma once
using namespace std;


struct Game
{
   private:
        long generateID()
        {
            long key = 0;
            for (int i = 0; i < name.length(); ++i)
            {
                key += (int)name[i];
            }
            for (int i = 0; i < date.length(); ++i) {
                if (date[i] == '.')
                {
                    continue;
                }
                else
                {
                    key += (int)date[i];
                }

            }
            return key;
        }

   public:
        string name;
        string genre;
        string date;
        string manufacturer;
        long id;
        Game(string _name, string _genre, string _date, string _manufacturer)
        {
            name = _name;
            genre = _genre;
            date = _date;
            manufacturer = _manufacturer;
            id = generateID();
        }
        Game() {}

};


