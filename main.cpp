#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <windows.h>
#include <time.h>

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
    cout<<"Zapisz w pliku fm.txt w katalogu z programem czestotliwosci stacji ktore wykrywa twoje radio,"<<endl;
    cout<<"czestotliwosci zapisuj jedna pod druga, w kolejnosci malejacej,"<<endl<<"zapisz plik, a nastepnie kilknij dowolny klawisz"<<endl<<endl;
    cout<<"Nacisnij dowolny klawisz...";
    getchar();
    _sleep(700);



    int ile=iloscStacji();
    if (ile==0)
    {
        cout<<endl<<"Blad z wczytywaniem stacji, sproboj ponownie"<<endl;
        getchar();
        main();
    }
    float *roznica=new float[ile+2];
    float *fm=new float[ile+2];
    fstream plik;
    plik.open("fm.txt",ios::in|ios::out);
    float help;
    cout<<endl<<"Z pliku pobrano nastepujace stacje: "<<endl;
    for(int i=2;i<=ile+1;i++)
    {
    plik>>help;
    fm[i]=help;
    cout<<fm[i]<<endl;
    }
    plik.close();
    fm[1]=108.0;
    fm[ile+2]=87.5;

    cout<<"Trwa obliczanie.";

    for(int i=1;i<ile;i++)
    {
      roznica[i]=fm[i-1]-fm[i];
      cout<<".";
      roznica[i]=(round(roznica[i]*10))/10;
      cout<<".";
      _sleep(30);
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
