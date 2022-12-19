//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "Dialog.h"
#include "ShowMessageBox.h"
#include "Window.h"
//---------------------------------------------------------------------------
class TMain : public TThread
{            
private:
        //bool BtnClick1;
        TWin *win;
        TBtn *btn;
        TWin *MsgWin;
        TCatalog *catalog;
        void __fastcall BtnClick(TObject *Sender);
        void __fastcall StartUpClick(TObject *Sender);
protected:
        void __fastcall Execute();
public:
        __fastcall TMain(bool CreateSuspended);
        void __fastcall MakePulpit();
        void __fastcall MakeDialog();
        bool __stdcall CallBack(HWND Control,int Command);
};
//---------------------------------------------------------------------------
#endif
