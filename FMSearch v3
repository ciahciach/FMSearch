#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <array>
#include <chrono>
#include <thread>
#include <stdlib.h>

using namespace std;

int iloscStacji()
{
   int ilosc_stacji=0;

   string line;
   ifstream plik2("fm.txt");
   if(plik2.good()==false){return 0;}
    while (getline(plik2,line))
    {
        ilosc_stacji++;
    }
    plik2.close();
    return ilosc_stacji;
}


int main()
{
    float best=0;
    float stacja_min;
    float stacja_max;
    float opt;


    cout<<fixed<<setprecision(1);
    cout<<"W pliku fm.txt w katalogu z programem zapisz czestotliwosci stacji wykrywanych przez twoje radio."<<endl;
    cout<<"Czestotliwosci zapisuj w pliku jedna pod druga. "<<endl<<endl;
    cout<<"Nacisnij dowolny klawisz...";
    getchar();
    this_thread::sleep_for(chrono::milliseconds(700));



    int ile=iloscStacji();
    if (ile==0)
    {
        cout<<endl<<"Blad z wczytywaniem stacji, sproboj ponownie."<<endl;
        getchar();
        main();
    }
    if (ile>0&&ile<3)
    {
        cout<<endl<<"Wprowadz minimum 3 stacje."<<endl;
        getchar();
        main();
    }
    ile+=2;
    float *roznica=new float[ile];
    float *fm=new float[ile];
    //cout<<ile<<endl;
    fstream plik;
    plik.open("fm.txt",ios::in|ios::out);
    float help;
    cout<<endl<<"Z pliku pobrano "<<iloscStacji()<<" stacj(i/e)."<<endl;

    //0 1 2 3 4 5 6
    //0 108 x x x x 87.5

    for(int i=2;i<=ile;i++)
    {
    plik>>help;
    fm[i]=help;
    }
//    for (int i = 2;i<=ile-1;i++)
//    {
//        cout<<fm[i]<<" "<<fm[i+1]<<" "<<fm[i+2]<<endl;
//        //
//    }
    //getchar();
    plik.close();

//    for(int i=0;i<ile+1;i++)
//    {
//    cout<<fm[i]<<" ";
//    }
//    cout<<" po alokacji"<<endl;

    fm[1]=108.0;
    fm[ile]=87.5;

    //Sortowanie stacji

//     for(int i=0;i<ile+1;i++)
//    {
//    cout<<fm[i]<<" ";
//    }
//    cout<<" po przypisaniu 1 i ostatniej"<<endl;


    sort (fm+1, fm + ile, greater<float>());

//    for(int i=0;i<ile+1;i++)
//    {
//    cout<<fm[i]<<" ";
//    }
//    cout<<" po sortowaniu"<<endl;

    cout<<"Trwa obliczanie.";

    for(int i=1;i<ile-2;i++)
    {
      roznica[i]=fm[i-1]-fm[i];
      cout<<".";
      roznica[i]=(round(roznica[i]*10))/10;
      cout<<".";
      this_thread::sleep_for(chrono::milliseconds(30));
     if (roznica[i]>best)
     {
      best=roznica[i];
      cout<<".";
      stacja_min=fm[i-1];
      cout<<".";
      stacja_max=fm[i];
      cout<<".";
     }

    }


    opt=(stacja_max+stacja_min)/2;
    int opt1=int(opt*100);
    if ((opt1)%10!=0)
    {
          cout<<endl<<endl<<endl<<"Optymalna stacja dla transmitera to --> "<<opt-0.05<<" <-- lub --> "<<opt+0.05<<" <--"<<endl;
    }
    else {cout<<endl<<endl<<endl<<"Optymalna stacja dla transmitera to --> "<<opt<<" <--"<<endl;}
    getchar();
    return 0;
}
