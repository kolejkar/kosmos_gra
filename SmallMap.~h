//---------------------------------------------------------------------------

#ifndef SmallMapH
#define SmallMapH
//---------------------------------------------------------------------------
#include "Lisc.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include <math.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
//---------------------------------------------------------------------------
class Tmap1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *workpanel;
        TLabel *info;
        TBitBtn *Attack;
        TBitBtn *MakeShip;
        TLabel *life;
        TLabel *Label1;
        TTimer *Drawing;
        TPanel *mini;
        TLabel *Statistic;
        TPanel *World;
        TImage *Space;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BackSpaceMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall SpaceMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall SpaceMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall AttackClick(TObject *Sender);
        void __fastcall MakeShipClick(TObject *Sender);
        void __fastcall DrawingTimer(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
        int tx,ty;
        int tx1,ty1,ty2,tx2;
        int px,py;
        bool move;
        Graphics::TBitmap *map;
        TCanvas *Can;
        TImage *img;
        void UptadeStatisticPopup();
public:		// User declarations
        __fastcall Tmap1(TComponent* Owner);
        bool ReadRegion(); //wczytywanie galaktyki
        void __fastcall MauseImage(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall MauseImageClick(TObject *Sender);
        bool selreg; //wybór regionu
        bool Losuj();
        void DrawGalaxy();
};
//---------------------------------------------------------------------------
extern PACKAGE Tmap1 *map1;
//---------------------------------------------------------------------------
#endif
