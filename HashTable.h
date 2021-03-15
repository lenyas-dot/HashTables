
#include "Game.h"
#pragma once
#include "string"

class HashTable
{
    private:
        int hashSize;
        Game* games;
        bool* arrAddress;
        int tableFullness;
#pragma region HashFuncs
        int value_hash_func(int& address, int hashSize)
        {
          //  srand(time(nullptr));
            int k = 3;
            address = (address + k) % hashSize;
            return address;
        }
        bool checkCollision(bool* addresses, int address,int sizeOfArr)
        {


                if (arrAddress[address] == false)
                {
                    return false;
                }

            return true;
        }
        int key_hash_func(long key, int hashSize)
        {
            int address = -1;
            address = key % hashSize;
            return address;
        }

#pragma endregion

    public:

        HashTable(int hashSize)
        {
            this->hashSize = hashSize;
            games = new Game[hashSize];
            arrAddress = new bool[hashSize];
            tableFullness = 0;
        }
        ~HashTable()
        {
        }
        void Add(Game game)
        {
            if ((hashSize - tableFullness) < 3)
            {
                Game* tempGames = games;
                bool* tempAdr = arrAddress;
                hashSize+=20;
                arrAddress = new bool[hashSize];
                games = new Game[hashSize];
                for (int i = 0; i < hashSize - 20; ++i)
                {
                    if (!tempAdr[i])
                    {
                        Add(tempGames[i]);
                    }
                }
                /*
                arrAddress = new bool[hashSize + 20];
                arrAddress = tempAdr;
                games = new Game[hashSize + 20];
                games = tempGames;
                hashSize += 20;
                 */
            }
           int index = key_hash_func(game.id, hashSize);
           if(checkCollision(arrAddress, index, hashSize))
           {
               arrAddress[index] = false;
           }
           else
           {
               int a = value_hash_func(index, hashSize);
               while(!checkCollision(arrAddress, a, hashSize))
               {
                   a = value_hash_func(a, hashSize);
               }
               arrAddress[a] = false;
               index = a;
           }
           games[index] = game;
           tableFullness++;
        }
        int Search(Game game)
        {

            int index = key_hash_func(game.id, hashSize);
            if (arrAddress[index])
            {
                while (arrAddress[index])
                {
                    index = value_hash_func(index, hashSize);
                }
            }
                if (games[index].id == game.id)
                {
                    if (games[index].manufacturer == game.manufacturer && games[index].date == game.date && games[index].genre == game.genre && games[index].name == game.name)
                    {
                        return index;
                    }
                    else
                    {
                        index = value_hash_func(game.id, hashSize);
                        if (games[index].manufacturer == game.manufacturer && games[index].date == game.date && games[index].genre == game.genre && games[index].name == game.name)
                        {
                            return index;
                        }
                        while (!checkCollision(arrAddress, index, hashSize))
                        {
                            index = value_hash_func(game.id, hashSize);
                            if (games[index].manufacturer == game.manufacturer && games[index].date == game.date && games[index].genre == game.genre && games[index].name == game.name)
                            {
                                return index;
                            }
                        }

                    }
                }

            return -1;
        }

        void Delete(Game game)
        {
            int index = Search(game);
            if (index == -1)
            {
                return;
            }
            arrAddress[index] = true;
            games[index].name = "";
            games[index].genre = "";
            games[index].manufacturer = "";
            games[index].date = "";
            games[index].id = 0;
            tableFullness--;
        }

        friend std::ostream& operator<<(std::ostream &out, const HashTable &table)
        {
            out << "=================Hash table=============" << endl;
            for (int i = 0; i < table.hashSize; ++i)
            {
                if (!table.arrAddress[i])
                {
                    out << i << ". Game: " << table.games[i].name << ", date of release: " << table.games[i].date << ", id: " << table.games[i].id << endl;
                }
            }
            return out;
        }

};


