#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include <chrono>
#include "galbalas.h"
#include "ivedimas.h"
#include "failai.h"
#include "sukurimas.h"
#include "struktura.h"
using std::cout; using std::cin; using std::string; using std::vector; using std::cerr;
[[ noreturn ]] void wrong();
int main (int, char *argv[]) 
{
    cout<<"Jei norite duomenis suvesti, įveskite 1, jei norite nuskaityti iš failo - 2, jei norite sukurti atsitiktinį studentų failą - bet kokį kitą skaičių: ";
    int f=0;
    cin>>f;
    if (cin.fail()) wrong();
    if (f==1) duomenu_ivedimas();
    else if (f==2)
    {
        cout<<"Jei norite naudoti 1strategiją dalinant studentus i dvi kategorijas spauskite 1, jei 2strategija - bet kokį kitą skaičių: ";
        int strategija=0;
        cin>>strategija;
        if (cin.fail()) wrong();
        cout<<"Jei norite naudoti vektorius, įveskite 1, jei list'ą - 2, jei deką - bet kokį kitą skaičių: ";
        int vld=0;
        cin>>vld;
        if (cin.fail()) wrong();
        if (vld==1)
        {
            auto start = std::chrono::high_resolution_clock::now();
            vector<studentas>studentai;
            vector<studentas>good;
            vector<studentas>bad;
            failai(argv, good, bad, studentai, strategija);
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            cout << "Programos vykdymo laikas: " << elapsed.count() << " s\n";
        }
        else if (vld==2)
        {
            auto start = std::chrono::high_resolution_clock::now();
            std::list<studentas>studentai;
            std::list<studentas>good;
            std::list<studentas>bad;
            failai(argv, good,bad, studentai, strategija);
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            cout << "Programos vykdymo laikas: " << elapsed.count() << " s\n";
        }
        else
        {
            auto start = std::chrono::high_resolution_clock::now();
            std::deque<studentas>studentai;
            std::deque<studentas>good;
            std::deque<studentas>bad;
            failai(argv, good,bad, studentai, strategija);
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            cout << "Programos vykdymo laikas: " << elapsed.count() << " s\n";
        }
        
    }
    else
    {
        cout<<"Iveskite,kiek įrašų norite, kad būtų sugeneruota: ";
        int kiekis=0;
        cin>>kiekis;
        if (cin.fail()) wrong();
        auto start = std::chrono::high_resolution_clock::now();
        sukurimas(kiekis,argv);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        cout << "Programos vykdymo laikas: " << elapsed.count() << " s\n";
    }
    return 0;
}
void wrong()
{
    cin.clear();
    cerr<<"KĄ TU ČIA VEDI?!"<<endl;
    exit (1);
}
