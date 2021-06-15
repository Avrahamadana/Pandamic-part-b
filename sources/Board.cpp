#include "City.hpp"
#include "Board.hpp"

using namespace pandemic;
using namespace std;

void Board::init()
{
    stringToColor["Red"] = Color::Red;
    stringToColor["Black"] = Color::Black;
    stringToColor["Blue"] = Color::Blue;
    stringToColor["Yellow"] = Color::Yellow;

    for (unsigned long i = 0; i < (int)citysString.size(); i++)
    {
        stringToCity[citysString[i]] = static_cast<City>(i);
    }

    string line;
    ifstream myfile("cities_map.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            vector<string> temp = split(line, ' ');
            City currCity = stringToCity[temp[0]];
            Color currColor = stringToColor[temp[1]];
            cityColor[currCity] = currColor;

            vector<City> citiesRelated;
            vector<Color> colorRelated;
    
    //        disease[currCity] = colorRelated;
            researchStations[currCity] = false;
            curesDiscovered[currColor] = false;
            
            for (unsigned long i = 2; i < (int)temp.size(); i++)
            {
                City city = stringToCity[temp[i]];
                citiesRelated.push_back(city);
            }
            cityNi[currCity] = citiesRelated;
        }
        myfile.close();
    }
}

void Board::print()
{
    //     map<City, Color> cityColor;
    //         map<City, vector<City>> cityNi;
    // map<City,Color>::iterator itr;
    // for(itr = cityColor.begin(); itr != cityColor.end(); itr++)
    // {
    //     cout<<itr->second;
    // }
}

// Board &Board::operator=(int numOfDiseases)
// {
//     return *this;
// }

int &Board::operator[](City c)
{
    
    return diseaseOfCity[c];
}

bool Board::is_clean()
{
    // if()
    return true;
}

void Board::remove_cures()
{
    for(auto &cure : curesDiscovered)
    {
        cure.second = false;
    }
    return;
}

ostream& pandemic::operator<<(ostream &os, Board &b)
{
    for(const auto& city : b.cityColor)
    {
        os << static_cast<int>(city.first) << "Cubes: " << static_cast<int>(city.second)<< endl;
    }
    return os;
}

template <typename Out>
void pandemic::split(const string &s, char delim, Out result)
{
    istringstream iss(s);
    string item;
    while (getline(iss, item, delim))
    {
        *result++ = item;
    }
}

vector<string> pandemic::split(const string &s, char delim)
{
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}