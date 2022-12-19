//---------------------------------------------------------------------------


#pragma hdrstop

#include "Galaxy.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <dir.h>
#include <stdio.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)
using namespace std;

Galaxy::Galaxy()
{
        for (int i=0;i<100;i++)
        {
                for (int j=0;j<100;j++)
                {
                        maps[i][j]=NULL;
                }
        }
        LosujGalaxy();
}
//---------------------------------------------------------------------------
void Galaxy::LosujGalaxy()
{
        string path="Maps\\"+intToStr(seed);
        _mkdir(path.c_str());
        ofstream plik;
        path="Maps\\"+intToStr(seed)+"\\region.dat";
        plik.open(path.c_str());
        for (int i=0;i<100;i++)
        {
                int posx=rand()%100;
                int posy=rand()%100;
                idgw[i]=new star();
                idgw[i]->id=0;
                idgw[i]->type=rand()%3+1;
                idgw[i]->x=posx;
                idgw[i]->y=posy;
                plik << posx;
                plik << " ";
                plik << posy;
                plik << " ";
                maps[posx][posy]=(object *)idgw[i];
                for (int j=0;j<12;j++)
                {

                }
        }
        plik.close();
}
//---------------------------------------------------------------------------
Region *Galaxy::GetRegion(int regX, int regY)
{
        Region *region=new Region(regX,regY);
        //region->Wczytaj(regX);
        return region;
}
//---------------------------------------------------------------------------
bool Galaxy::HaveStar(int regX, int regY)
{
        if (maps[regX][regY]!=NULL)
                return true;
        return false;
}
//---------------------------------------------------------------------------
void Galaxy::Czysc()
{
        for (int i=0;i<100;i++)
        {
                for (int j=0;j<100;j++)
                {
                        if (maps[i][j]!=NULL)
                        {
                                delete maps[i][j];
                                maps[i][j]=NULL;
                        }
                }
        }
}
//---------------------------------------------------------------------------
Galaxy::~Galaxy()
{
        Czysc();
}
//---------------------------------------------------------------------------
