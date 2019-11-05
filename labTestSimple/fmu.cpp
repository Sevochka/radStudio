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
void __fastcall Tfm::FormCreate(TObject *Sender)
{
	tc->First();
	tc->TabPosition = TTabPosition::None;
    pb->Max = tc->TabCount-1;


}
//---------------------------------------------------------------------------
void __fastcall Tfm::buStartClick(TObject *Sender)
{
	FCountCorrect = 0;
    FCountWrong = 0;
    me->Lines->Clear();
	tc->Next();
}
//---------------------------------------------------------------------------
void __fastcall Tfm::Button2Click(TObject *Sender)
{
	UnicodeString x;
	//x = ((TControl *) Sender)->Tag == 1 ? L"correct" : L"incorrect";

	if(((TControl *) Sender)->Tag == 1){
		 x = L"correct";
		 FCountCorrect++;
	}
	else{
		x = L"incorrect";
		FCountWrong++;
    }
	me->Lines->Add(L"Question " + tc->ActiveTab->Text +  " - " + x);
	//me->Lines->Add(Format(L"Question %s - %s", ARRAYOFCONST((tc->ActiveTab)));
	tc->Next();
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buRestartClick(TObject *Sender)
{
	me->Lines->Clear();
	tc->First();
}
//---------------------------------------------------------------------------
void __fastcall Tfm::tcChange(TObject *Sender)
{
	pb->Value = tc->ActiveTab->Index;
	//Ind->Text = (tc->ActiveTab->Index)->ConvertToString();

	if(tc->ActiveTab == tResult){
		laCorrect->Text = Format(L"Correct = %d", ARRAYOFCONST((FCountCorrect)));
		laWrong->Text = Format(L"Incorrect = %d", ARRAYOFCONST((FCountWrong)));
		imCorrect->Visible = (FCountCorrect > FCountWrong);
        imWrong->Visible = (FCountCorrect < FCountWrong);
	}
	Ind->Text = Format(L"(%d из %d)",
		ARRAYOFCONST((tc->ActiveTab->Index, tc->TabCount-2)));
	Ind->Visible = (tc->ActiveTab != tMenu) && (tc->ActiveTab != tResult);
}
//---------------------------------------------------------------------------

