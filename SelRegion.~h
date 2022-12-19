//---------------------------------------------------------------------------

#ifndef SelRegionH
#define SelRegionH

#include "Lisc.h"
//---------------------------------------------------------------------------
class Region
{
public:
        object *maps[100][100];
        bool Losuj();
        void Czysc();
        bool Zapisz();
        bool Wczytaj(int regX, int regY);
        int regx;
        int regy;
        Region(int regX, int regY);
        char *RegionInfo();
        char *ObjectInfo(int x, int y);
        bool HaveObject(int x, int y);
        ~Region();
};
//seed
extern int seed;
#endif
