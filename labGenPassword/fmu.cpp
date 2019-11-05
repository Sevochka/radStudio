//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmu.h"
#include "uUtils.h"
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
void __fastcall Tfm::buPasswordClick(TObject *Sender)
{

	String Text = RandomStr(StrToIntDef(edLenght->Text, 9),
		ckLower->IsChecked, ckUpper->IsChecked, ckNumber->IsChecked, ckSpec->IsChecked);

	edPassword->Text = Text;

	me->Lines->Add(Text);
}
//---------------------------------------------------------------------------
