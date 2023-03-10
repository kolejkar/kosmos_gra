//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SmallMap.h"
#include "SelRegion.h"
#include "Galaxy.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tmap1 *map1;
Region *region;
object *(*idgw)[100];
//---------------------------------------------------------------------------
__fastcall Tmap1::Tmap1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tmap1::FormCreate(TObject *Sender)
{
        World->DoubleBuffered=true;
        map=new Graphics::TBitmap();
        Can=map->Canvas;
        Can->Brush->Color=clBlack;
        Losuj();
}
//---------------------------------------------------------------------------
void __fastcall Tmap1::BackSpaceMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        if (move && Shift.Contains(ssRight))
        {
                tx2=(X-tx);
                ty2=(Y-ty);
                px=tx2+tx1;
                py=ty2+ty1;
        }
        else
        if (Statistic->Visible)
                Statistic->Visible=false;
        workpanel->Caption="X: "+IntToStr(px)+" Y: "+IntToStr(py);
}
//---------------------------------------------------------------------------
void __fastcall Tmap1::FormCloseQuery(TObject *Sender, bool &CanClose)
{

        if (MessageBox(Handle,"Czy zako?czy? gr??","Ko?czenie gry",MB_YESNO)==IDYES)
        {
                CanClose=true;
                //RS->Resume();
        }
        else
        {
                CanClose=false;
                //RS->Resume();
        }
}
//---------------------------------------------------------------------------

void __fastcall Tmap1::SpaceMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        if (Shift.Contains(ssRight))
        {
                tx=X;
                ty=Y;
                move=true;

        }
}
//---------------------------------------------------------------------------

void __fastcall Tmap1::SpaceMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        if (move)
        {
                move=false;
                tx1=tx2+tx1;
                ty1=ty2+ty1;
        }
}
//---------------------------------------------------------------------------

void __fastcall Tmap1::AttackClick(TObject *Sender)
{
        //Refresh();
}
//---------------------------------------------------------------------------
void __fastcall Tmap1::MakeShipClick(TObject *Sender)
{
        //ReadRegion();
}
//---------------------------------------------------------------------------
bool Tmap1::ReadRegion()
{
        return true;
}
//---------------------------------------------------------------------------
bool Tmap1::Losuj()
{
        seed=1;//time(NULL);
        srand(seed);
        string path="Maps\\"+intToStr(seed);
        _mkdir(path.c_str());
        region=new Region(0,0);
        Drawing->Enabled=true;
        return true;
}
//---------------------------------------------------------------------------
void Tmap1::DrawGalaxy()
{
        int con1=World->ControlCount;
        while (con1>0)
        {
                AnsiString str = World->Controls[con1-1]->Name.SubString(1,1);
                if (str == "P")
                {
                        delete World->Controls[con1-1];
                }
                con1--;
        }
        Graphics::TBitmap *space=new Graphics::TBitmap();
        idgw=region->maps;
        for (int i=0;i<100;i++)
        {
                for (int j=0;j<100;j++)
                {
                        if (idgw[i][j]!=NULL)
                        {
                        img=new TImage(this);
                        img->OnClick=&MauseImageClick;
                        img->OnMouseMove=&MauseImage;
                        img->Parent=World;
                        //img->BringToFront();
                        img->AutoSize=true;
                        if (idgw[i][j]->id==0)
                        {
                                img->Width=120;
                                img->Height=img->Width;
                                space->LoadFromFile("Items\\gwiazda"+IntToStr(idgw[i][j]->type)+".bmp");
                        }
                        if (idgw[i][j]->id==1)
                        {
                                img->Width=20;
                                img->Height=img->Width;
                                space->LoadFromFile("Items\\planetoida"+IntToStr(idgw[i][j]->type)+".bmp");
                        }
                        if (idgw[i][j]->id==2)
                        {
                                img->Width=30;
                                img->Height=img->Width;
                                space->LoadFromFile("Items\\planeta"+IntToStr(idgw[i][j]->type)+".bmp");
                        }
                        img->Picture->Bitmap=space;
                        img->Left=i*20+px;
                        img->Top=j*20+py;
                        img->Visible=true;
                        img->Name="P"+IntToStr(i)+"_"+IntToStr(j);
                        }
                }
        }
        delete space;
        space=NULL;
}
//---------------------------------------------------------------------------
void Tmap1::UptadeStatisticPopup()
{
        if (Statistic->Visible)
        {
                Statistic->BringToFront();
        }
}
//---------------------------------------------------------------------------
void __fastcall Tmap1::DrawingTimer(TObject *Sender)
{
        map->Height=Space->ClientHeight;
        map->Width=Space->ClientWidth;
        //Can->Handle=GetDC(Space->Handle);
        TCanvas *MCan=new TCanvas();
        MCan->Handle=GetDC(mini->Handle);
        Graphics::TBitmap *space=new Graphics::TBitmap();
        Can->Rectangle(0+px,0+py,100*20+px,100*20+py);
        idgw=region->maps;
        for (int i=0;i<100;i++)
        {
                for (int j=0;j<100;j++)
                {
                        if (idgw[i][j]!=NULL)
                        {
                        if (idgw[i][j]->id==0)
                        {
                                MCan->Brush->Color=clYellow;
                                MCan->Rectangle(i*3,j*3,i*3+18,j*3+18);
                        }
                        if (idgw[i][j]->id==1)
                        {
                                MCan->Brush->Color=clGreen;
                                MCan->Rectangle(i*3,j*3,i*3+3,j*3+3);
                        }
                        if (idgw[i][j]->id==2)
                        {
                                MCan->Brush->Color=clRed;
                                MCan->Rectangle(i*3,j*3,i*3+6,j*3+6);
                        }
                        }
                }
        }
        Space->Picture->Bitmap=map;
        Can->Brush->Color=clBlack;
        delete MCan;
        MCan=NULL;
        DrawGalaxy();
        UptadeStatisticPopup();
}
//---------------------------------------------------------------------------
void __fastcall Tmap1::FormDestroy(TObject *Sender)
{
        if (region!=NULL)
        {
                delete region;
                region=NULL;
        }
        delete map;
}
//---------------------------------------------------------------------------
void __fastcall Tmap1::MauseImage(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        //ShowMessage(Sender->ClassName());
        if (AnsiString(Sender->ClassName())=="TImage")
        {
                TControl *con=(TControl *)Sender;
                //i*20+px;
                int regx=(con->Left-px)/20;
                int regy=(con->Top-py)/20;
                if (region->HaveObject(regx,regy))
                {
                                Statistic->Top=con->Top+5+Y;
                                Statistic->Left=con->Left+5+X;
                                Statistic->Caption=region->ObjectInfo(regx,regy);
                                Statistic->Visible=true;
                }

        }
}
//---------------------------------------------------------------------------
void __fastcall Tmap1::MauseImageClick(TObject *Sender)
{
       /* if (Sender->ClassType()==__classid(TImage))
        {
                TControl *con=(TControl *)Sender;
                Statistic->Visible=false;
                int regx=con->Left/20;
                int regy=con->Top/20;
                region=galaxy->GetRegion(regx,regy);
                //selreg=false;
        }*/
}
//---------------------------------------------------------------------------


