//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmu.h"
#include "DMU.h"
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
void __fastcall Tfm::FormCreate(TObject *Sender)
{
	tc->ActiveTab = tList;
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buAddClick(TObject *Sender)
{
	dm->taNotes->Append();
	tc->GotoVisibleTab(tilItem->Index);
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buSaveClick(TObject *Sender)
{
	dm->taNotes->Post();
	tc->GotoVisibleTab(tilItem->Index);
}
//---------------------------------------------------------------------------
void __fastcall Tfm::ListView2ItemClick(TObject * const Sender, TListViewItem * const AItem)

{
	dm->taNotes->Edit();
	tc->GotoVisibleTab(tilItem->Index);
}
//---------------------------------------------------------------------------
void __fastcall Tfm::FormShow(TObject *Sender)
{
	dm->FDConnection1->Connected = true;
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buCancelClick(TObject *Sender)
{
	dm->taNotes->Cancel();
	tc->GotoVisibleTab(tList->Index);
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buDeleteClick(TObject *Sender)
{
	dm->taNotes->Delete();
	tc->GotoVisibleTab(tList->Index);
}
//---------------------------------------------------------------------------
