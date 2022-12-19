//---------------------------------------------------------------------------

#ifndef RenderSH
#define RenderSH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "Lisc.h"
//---------------------------------------------------------------------------
class TRenderS : public TThread
{            
private:
        planet *id;
        int tx,ty;
        TImage *img;
protected:
        void __fastcall Execute();
public:
        __fastcall TRenderS(bool CreateSuspended);
        void __fastcall Uptade();
        void __fastcall Action();
        void __fastcall Team();
        Graphics::TBitmap *star;
        Graphics::TBitmap *plid[7];
        Graphics::TBitmap *space;
        TCanvas *Can;
        void __fastcall DrawBmp();
        bool stop;
        int bmpx;
        int bmpy;
};
//---------------------------------------------------------------------------
#endif
