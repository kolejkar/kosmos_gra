//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#pragma package(smart_init)
struct MQuery
{
        HWND Control;
        int Command;
} QMsg;
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Main::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
__fastcall TMain::TMain(bool CreateSuspended)
        : TThread(CreateSuspended)
{
        //FreeOnTerminate=true;
        //BtnClick1=false;
        /*catalog=NULL;
        win=NULL; */
}
//---------------------------------------------------------------------------
void __fastcall TMain::Execute()
{
        //---- Place thread code here ----
        MessageWin("Test 1","",0);
        Synchronize(MakePulpit);
        while (CallBack(QMsg.Control,QMsg.Command));
}
//---------------------------------------------------------------------------
void __fastcall TMain::BtnClick(TObject *Sender)
{
        TWinControl *con=(TWinControl *)Sender;
        QMsg.Control=con->Parent->Handle;
        QMsg.Command=1;
        //BtnClick1=true;

}
//---------------------------------------------------------------------------
void __fastcall TMain::StartUpClick(TObject *Sender)
{
        Synchronize(MakeDialog);
}
//---------------------------------------------------------------------------
void __fastcall TMain::MakePulpit()
{
        Form1->StartUp->Picture->LoadFromFile("Std_Btn.bmp");
        Form1->StartUp->Stretch=true;
        Form1->StartUp->OnClick=StartUpClick;
        //Form1->StartUp->Center=true;
        catalog=new TCatalog(Form1);
        catalog->Parent=Form1;
        catalog->Path="Test";
        catalog->Name="CatTest";
        catalog->CatalogIcon->OnClick=BtnClick;
        catalog->Replace();
        catalog->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMain::MakeDialog()
{
        win=new TWin(Form1);
        win->Parent=Form1;
        win->Name="Test";
        win->Height=500;
        win->Width=500;
        win->Top=50;
        win->Left=50;
        win->SetSysBtn(BtnClose|BtnMaximize);
        win->Show();
        //win->Visible=true;
        btn=new TBtn(win->Client);
        btn->Parent=win->Client;
        btn->Top=win->Client->ClientHeight-40;
        btn->Left=win->Client->ClientWidth-80;
        btn->Height=25;
        btn->Width=75;
        btn->BtnTitle->OnClick=BtnClick;
        btn->Show();
        btn->Name="Zamknij";
        //btn=NULL;
        //btn->Visible=true;
}
//---------------------------------------------------------------------------
void DefCallBack()
{
        if (QMsg.Control!=0)
                QMsg.Control=0;
        if (QMsg.Command>0)
                QMsg.Command=0;
}
//---------------------------------------------------------------------------
bool __stdcall TMain::CallBack(HWND Control,int Command)
{
        if ()
        {
                try
                {
                        if (Control==btn->Handle && Command==1)
                        {
                                MessageWin(IntToStr(MessageWin("Test message.","",1)),"",0);
                                win->Width=100;
                        }
                        if (Control==catalog->Handle && Command==1)
                        {
                                MessageWin("System error!","Error",0);
                        }
                }
                __finally
                {
                        DefCallBack();
                        return true;
                }
        }
}
//----------------------------------------------------------------------------
