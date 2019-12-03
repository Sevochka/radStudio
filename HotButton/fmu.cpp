//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tfm *fm;
//---------------------------------------------------------------------------
__fastcall Tfm::Tfm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfm::ButtonAllMouseEnter(TObject *Sender)
{
	TButton *x = ((TButton*)Sender);
	x->Margins->Rect = TRect(0,0,0,0);
	x->TextSettings->Font->Size += 10;
	x->TextSettings->Font->Style = x->TextSettings->Font->Style << TFontStyle::fsBold;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::ButtonAllMouseLeave(TObject *Sender)
{
     TButton *x = ((TButton*)Sender);
	x->Margins->Rect = TRect(15,15,15,15);
	x->TextSettings->Font->Size -= 10;
	x->TextSettings->Font->Style = x->TextSettings->Font->Style >> TFontStyle::fsBold;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::ImageAllMouseEnter(TObject *Sender)
{
	((TImage*)Sender)->Margins->Rect = TRect(10,10,10,10);
}
//---------------------------------------------------------------------------

void __fastcall Tfm::ImageAllMouseLeave(TObject *Sender)
{
	 ((TImage*)Sender)->Margins->Rect = TRect(0,0,0,0);
}
//---------------------------------------------------------------------------


