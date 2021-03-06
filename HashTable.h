
#include "Game.h"
#pragma once
#include "string"

class HashTable
{
    private:
        int hashSize;
        Game* games;
        void key_hash_func(long key)
        {

        }
    public:
        HashTable()
        {
            hashSize = 100;
            games = new Game[hashSize];
        }
        ~HashTable()
        {

        }
        void Add(long key)
        {

        }


};


