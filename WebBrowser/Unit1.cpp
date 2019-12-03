//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
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
void __fastcall Tfm::buGoClick(TObject *Sender)
{
	wb->URL = edURL->Text;
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buBackClick(TObject *Sender)
{
	wb->GoBack();
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buForwardClick(TObject *Sender)
{
	wb->GoForward() ;
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buReloadClick(TObject *Sender)
{
   wb->Reload();
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buStopClick(TObject *Sender)
{
	wb->Stop() ;
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buAboutClick(TObject *Sender)
{
	ShowMessage("LabWebBrowser - Vsevolod Kochnev (171-333");
}
//---------------------------------------------------------------------------
void __fastcall Tfm::edURLKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
		  TShiftState Shift)
{
	if(Key == vkReturn){
		wb->URL = edURL->Text;
	}
}
//---------------------------------------------------------------------------
void __fastcall Tfm::wbDidFinishLoad(TObject *ASender)
{
	edURL->Text = wb->URL;
}
//---------------------------------------------------------------------------
void __fastcall Tfm::FormCreate(TObject *Sender)
{
	wb->URL = edURL->Text;
}
//---------------------------------------------------------------------------
