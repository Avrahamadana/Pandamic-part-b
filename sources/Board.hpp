#pragma once
#include "City.hpp"
//#include "Player.hpp"
#include "Color.hpp"
#include <map>
#include <vector>

#include "CitysString.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
namespace pandemic
{
    class Board
    {
    public:
        void init();
        //map<City,vector<Color>> disease;
        map<City, Color> cityColor;
        map<City, vector<City>> cityNi;
        map<string, City> stringToCity;
        map<string, Color> stringToColor;
        map<City,bool> researchStations;
        map<Color,bool> curesDiscovered;
        map<City,int> diseaseOfCity;
    
        Board()
        {
            init();
        }
        int &operator[](City c);
        // Board &operator=(int numOfDiseases);
        bool is_clean();
        void remove_cures();
        friend ostream &operator<<(ostream &os, Board &b);
        void print();
    };
    template <typename Out>
    void split(const string &s, char delim, Out result);
    vector<string> split(const string &s, char delim);

};