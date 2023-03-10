//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RenderS.h"
#include "SmallMap.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TRenderS::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
__fastcall TRenderS::TRenderS(bool CreateSuspended)
        : TThread(CreateSuspended)
{
        FreeOnTerminate=true;
        stop=false;
        bmpx=0;
        bmpy=0;
}
//---------------------------------------------------------------------------
void __fastcall TRenderS::Execute()
{
        //---- Place thread code here ----
        do
        {
                space=new Graphics::TBitmap();
                Can=space->Canvas;
                Can->Brush->Color=clBlack;
                space->Width=map->size;
                space->Height=map->size;
                for (int i=0;i<map->_leafs.size();i++)
                {
                        if (map->_leafs[i]->gwiazda==NULL) continue;

                        /*Canvas->Pen->Color=rand();
                        Canvas->Brush->Color=rand();
                        Canvas->Rectangle(_leafs[i]->x,_leafs[i]->y,_leafs[i]->h,_leafs[i]->w); */

                        int x1=(map->cx-map->_leafs[i]->gwiazda->x)*(map->cx-map->_leafs[i]->gwiazda->x);
                        int y1=(map->cy-map->_leafs[i]->gwiazda->y)*(map->cy-map->_leafs[i]->gwiazda->y);
                        int r1=60*60;
                        if (x1+y1<=r1)
                        {
                                //zaznaczono gwiazd?
                        }
                        if (map->_leafs[i]->gwiazda->team==1)
                        {
                                Can->Pen->Color=clRed;
                                Can->Brush->Color=clBlack;
                                int size=map->_leafs[i]->gwiazda->planety*60+(60+80+10);
                                Can->Ellipse(map->_leafs[i]->gwiazda->x-size,map->_leafs[i]->gwiazda->y-size,map->_leafs[i]->gwiazda->x+size,map->_leafs[i]->gwiazda->y+size);
                        }
                        else
                        if (map->_leafs[i]->gwiazda->team==2)
                        {
                                Can->Pen->Color=clGreen;
                                Can->Brush->Color=clBlack;
                                int size=map->_leafs[i]->gwiazda->planety*60+(60+80+10);
                                Can->Ellipse(map->_leafs[i]->gwiazda->x-size,map->_leafs[i]->gwiazda->y-size,map->_leafs[i]->gwiazda->x+size,map->_leafs[i]->gwiazda->y+size);
                        }
                        star=new Graphics::TBitmap();
                        star->LoadFromFile("Items\\gwiazda1.bmp");
                        tx=map->_leafs[i]->gwiazda->x-60;
                        ty=map->_leafs[i]->gwiazda->y-60;
                        Can->Draw(tx,ty,star);
                        delete star;
                        star=NULL;
                        planet *earth=map->_leafs[i]->gwiazda->pl;
                        //earth=new planet[_leafs[i]->gwiazda->planety];
                        //earth=_leafs[i]->gwiazda->pl;
                        for (int i1=0;i1<map->_leafs[i]->gwiazda->planety;i1++)
                        {
                                if (map->_leafs[i]->gwiazda==NULL) continue;
                                if (map->clickl)
                                {

                                        int x1=(map->cx-earth[i1].x)*(map->cx-earth[i1].x);
                                        int y1=(map->cy-earth[i1].y)*(map->cy-earth[i1].y);
                                        int r1=30*30;
                                        if (x1+y1<=r1)
                                        {
                                                //dru?yna na planecie

                                                id=&earth[i1];
                                                if (id->team<=0)
                                                        Can->Pen->Color=clWhite;
                                                else
                                                if (id->team==1)
                                                        Can->Pen->Color=clRed;
                                                else
                                                if (id->team==2)
                                                        Can->Pen->Color=clGreen;
                                                Can->Ellipse(id->x-35,id->y-35,id->x+35,id->y+35);
                                                earth[i1].select=true;
                                                id=&earth[i1];
                                                Synchronize(Action);
                                                map->pl=id;
                                        }
                                }
                                else
                                        earth[i1].select=false;
                                if (earth[i1].team==1)
                                {
                                        map->_leafs[i]->gwiazda->team=1;
                                }
                                for (int l=0;l<earth[i1].pocisk.size();l++)
                                {
                                    Ship *st;
                                    st=earth[i1].pocisk[l]->statek;
                                    float wx=st->x-earth[i1].pocisk[l]->x; //oblicz wektor mi?dzy zombiakiem a graczem
                                    float wy=st->y-earth[i1].pocisk[l]->y;
                                    float length=sqrt(wx*wx+wy*wy); //oblicz d?ugo?? wektora
                                    wx=wx/length; //podziel wektor przez d?ugo??
                                    wy=wy/length;
                                    int sp=5;
                                    if (sp>length)
                                        sp=length;
                                    if (sp==0)
                                    {
                                        st->life-=earth[i1].pocisk[l]->demage;
                                        delete earth[i1].pocisk[l];
                                        earth[i1].pocisk.erase(earth[i1].pocisk.begin()+l-1);
                                        //l--;

                                    }
                                    earth[i1].pocisk[l]->y=earth[i1].pocisk[l]->y+floor(wy+0.5)*sp;  //zaokr?glij do jedno??i i przemie?? zombiaka
                                    earth[i1].pocisk[l]->x=earth[i1].pocisk[l]->x+floor(wx+0.5)*sp;
                                    Can->Brush->Color=clMaroon;
                                    Can->Ellipse(earth[i1].pocisk[l]->x-5,earth[i1].pocisk[l]->y-5,earth[i1].pocisk[l]->x+5,earth[i1].pocisk[l]->y+5);
                                }
                                for (int i=0;i<7;i++)
                                {
                                        plid[i]=new Graphics::TBitmap();
                                }
                                plid[0]->LoadFromFile("Items\\planeta1.bmp");
                                plid[1]->LoadFromFile("Items\\planeta2.bmp");
                                plid[2]->LoadFromFile("Items\\planeta3.bmp");
                                plid[3]->LoadFromFile("Items\\planeta4.bmp");
                                plid[4]->LoadFromFile("Items\\planeta5.bmp");
                                plid[5]->LoadFromFile("Items\\planeta6.bmp");
                                plid[6]->LoadFromFile("Items\\planeta7.bmp");
                                if (earth[i1].type==1)
                                {
                                        tx=earth[i1].x-30;
                                        ty=earth[i1].y-30;
                                        Can->Draw(tx,ty,plid[0]);
                                }
                                else
                                if (earth[i1].type==2)
                                {
                                        tx=earth[i1].x-30;
                                        ty=earth[i1].y-30;
                                        Can->Draw(tx,ty,plid[1]);
                                }
                                else
                                if (earth[i1].type==3)
                                {
                                        tx=earth[i1].x-30;
                                        ty=earth[i1].y-30;
                                        Can->Draw(tx,ty,plid[2]);
                                }
                                if (earth[i1].type==4)
                                {
                                        tx=earth[i1].x-30;
                                        ty=earth[i1].y-30;
                                        Can->Draw(tx,ty,plid[3]);
                                }
                                if (earth[i1].type==5)
                                {
                                        tx=earth[i1].x-30;
                                        ty=earth[i1].y-30;
                                        Can->Draw(tx,ty,plid[4]);
                                }
                                if (earth[i1].type==6)
                                {
                                        tx=earth[i1].x-30;
                                        ty=earth[i1].y-30;
                                        Can->Draw(tx,ty,plid[5]);
                                }
                                if (earth[i1].type==7)
                                {
                                        tx=earth[i1].x-30;
                                        ty=earth[i1].y-30;
                                        Can->Draw(tx,ty,plid[6]);
                                }
                                for (int i=0;i<7;i++)
                                {
                                        delete plid[i];
                                        plid[i]=NULL;
                                }
                                earth[i1].x=earth[i1].distance*cos((earth[i1].angle*M_PI)/180)+map->_leafs[i]->gwiazda->x;
                                earth[i1].y=earth[i1].distance*sin((earth[i1].angle*M_PI)/180)+map->_leafs[i]->gwiazda->y;
                                earth[i1].angle++;
                        }
                }
////////////////////////////////////////////////////////////////////////////////////////////////////
                for (int i1=0;i1<map->statki.size();i1++)
                {
                        if (map->statki[i1]->life==0)
                        {
                                delete map->statki[i1];
                                map->statki.erase(map->statki.begin()+i1-1);
                                //i1--;
                        }
                        for (int p=0;p<map->_leafs.size();p++)
                        {
                                if (map->_leafs[p]->gwiazda==NULL) continue;
                                planet *earth=map->_leafs[p]->gwiazda->pl;
                                for (int pi=0;pi<map->_leafs[p]->gwiazda->planety;pi++)
                                {
                                        if (earth[pi].attacked)
                                        {
                                                int x1=(earth[pi].x-map->statki[i1]->x)*(earth[pi].x-map->statki[i1]->x);
                                                int y1=(earth[pi].y-map->statki[i1]->y)*(earth[pi].y-map->statki[i1]->y);
                                                int r1=15*15;
                                                if (x1+y1<=r1)
                                                {
                                                        earth[pi].team=1;
                                                }
                                                r1=(15*5)*(15*5);
                                                if (x1+y1<=r1 && earth[pi].team!=1 && earth[pi].team>0)
                                                {
                                                        earth[pi].AttackShip(map->statki[i1],1);
                                                }
                                        }
                                }
                        }
                        if (map->clickl)
                        {
                                int x1=(map->cx-map->statki[i1]->x)*(map->cx-map->statki[i1]->x);
                                int y1=(map->cy-map->statki[i1]->y)*(map->cy-map->statki[i1]->y);
                                int r1=15*15;
                                if (x1+y1<=r1)
                                {
                                        map->statki[i1]->select=true;
                                        map->life->Caption="Life: "+IntToStr(map->statki[i1]->life);
                                }
                        }
                        else
                        if (map->clickr)
                        {
                                map->statki[i1]->select=false;
                        }
                        int i=map->statki[i1]->energy;
                        float wx=map->statki[i1]->pl->x-map->statki[i1]->x; //oblicz wektor mi?dzy zombiakiem a graczem
                        float wy=map->statki[i1]->pl->y-map->statki[i1]->y;
                        float length=sqrt(wx*wx+wy*wy); //oblicz d?ugo?? wektora
                        wx=wx/length; //podziel wektor przez d?ugo??
                        wy=wy/length;
                        int sp=map->statki[i1]->speed;
                        if (sp>length)
                                sp=length;
                        map->statki[i1]->y=map->statki[i1]->y+floor(wy+0.5)*sp;  //zaokr?glij do jedno??i i przemie?? zombiaka
                        map->statki[i1]->x=map->statki[i1]->x+floor(wx+0.5)*sp;
                        map->statki[i1]->energy=i-sp;
                        if (map->statki[i1]->select)
                                Can->Pen->Color=clGreen;
                        if (map->statki[i1]->team==1)
                                Can->Brush->Color=clRed;
                        else
                        if (map->statki[i1]->team==2)
                                Can->Brush->Color=clGreen;
                        Can->Rectangle(map->statki[i1]->x-15,map->statki[i1]->y-15,map->statki[i1]->x+15,map->statki[i1]->y+15);
                }
                Synchronize(Uptade);
                Sleep(10);
                delete space;
                space=NULL;
        }
        while (!stop);
}
//---------------------------------------------------------------------------
void __fastcall TRenderS::Uptade()
{
        map->Space->Canvas->Draw(-bmpx,-bmpy,space);
}

void __fastcall TRenderS::Action()
{
    if (id->select)
    {
        if (id->air)
        {
                map->info->Caption="Planet: \nIt is fit for life.";
                if (id->team==1)
                {
                        map->Attack->Enabled=false;
                        map->MakeShip->Enabled=true;
                }
                else
                {
                        map->Attack->Enabled=true;
                        map->MakeShip->Enabled=false;
                }
        }
        else
        {
                map->info->Caption="Planet: \nIt is not fit for life.";
                map->Attack->Enabled=false;
                map->MakeShip->Enabled=false;
        }
    }
    else
    {
        map->Attack->Enabled=false;
        map->MakeShip->Enabled=false;
    }
}
void __fastcall TRenderS::Team()
{
}
void __fastcall TRenderS::DrawBmp()
{
}