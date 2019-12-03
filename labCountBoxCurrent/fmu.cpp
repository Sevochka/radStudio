//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "uUtils.cpp"
#include "uUtils.h"

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

	FListBox = new TList;
	for (int i = 1; i <= cMaxBox; i++) {
		FListBox->Add(this->FindComponent("Rectangle"+IntToStr(i)));
	}

	FListAnswer = new TList;
	FListAnswer->Add(buAnswer1);
	FListAnswer->Add(buAnswer2);
	FListAnswer->Add(buAnswer3);
	FListAnswer->Add(buAnswer4);
	FListAnswer->Add(buAnswer5);
	FListAnswer->Add(buAnswer6);

}
//---------------------------------------------------------------------------

void __fastcall Tfm::FormDestroy(TObject *Sender)
{
	delete FListBox;
    delete FListAnswer;
}
//---------------------------------------------------------------------------

void Tfm::DoReset()
{
	FCountCorrect = 0;
	FCountWrong = 0;
	FTimeValue = Time().Val + (double)30/(24*60*60); // 30 seconds
	tmPlay->Enabled = true;
	DoContinue();
}

void Tfm::DoContinue()
{
    for (int i = 0; i < cMaxBox; i++) {
	   ((TRectangle*)FListBox->Items[i])->Fill->Color = TAlphaColorRec::Lightgray;
	}
	//
	FNumberCorrect = RandomRange(cMinPossible, cMaxPossible);
    int *x = RandomArrayUnique(cMaxBox, FNumberCorrect);
	for (int i = 0; i < FNumberCorrect; i++) {
	   ((TRectangle*)FListBox->Items[x[i]])->Fill->Color = TAlphaColorRec::Blue;
	}

	//

	int xAnswerStart = FNumberCorrect - Random(cMaxAnswer);
	if (xAnswerStart < cMinPossible) {
		xAnswerStart = cMinPossible;
	}

	for (int i = 0; i < cMaxAnswer-1; i++) {
		((TButton*)FListAnswer->Items[i])->Text = IntToStr(xAnswerStart + i);
	}
}

void Tfm::DoAnswer(int aValue)
{
    (aValue == FNumberCorrect) ? FCountCorrect++ : FCountWrong++;
	if (FCountWrong > 5) {
		tc->Next();
		laCorrect->Text = Format(L"Correct = %d", ARRAYOFCONST((FCountCorrect)));
		laIncorrect->Text = Format(L"Incorrect = %d", ARRAYOFCONST((FCountWrong)));
	}
	DoContinue();
}

void Tfm::DoFinish()
{
    tmPlay->Enabled = true;
}



//---------------------------------------------------------------------------

void __fastcall Tfm::tmPlayTimer(TObject *Sender)
{
	double x = FTimeValue - Time().Val;
	laTime->Text = FormatDateTime("nn:ss", x);
	if (x <= 0) {
		DoFinish();
	}
}
//---------------------------------------------------------------------------


void __fastcall Tfm::buAnswerAllClick(TObject *Sender)
{
	DoAnswer(StrToInt(((TButton*)Sender)->Text));
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buResetClick(TObject *Sender)
{
    DoReset();
}
//---------------------------------------------------------------------------


void __fastcall Tfm::buGoToPlayClick(TObject *Sender)
{
    tc->Previous();
}
//---------------------------------------------------------------------------

void __fastcall Tfm::Button1Click(TObject *Sender)
{
	tc->ActiveTab = tiPlay;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::Button2Click(TObject *Sender)
{
    tc->ActiveTab = tiAbout;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::Button3Click(TObject *Sender)
{
    tc->ActiveTab = tiLevel;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::Button4Click(TObject *Sender)
{
	tc->ActiveTab = tiOptions;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::Button5Click(TObject *Sender)
{
	tc->ActiveTab = tiMenu;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::tbBlackChanceChange(TObject *Sender)
{
	if (tbBlackChance->Value == 0) {
		laDif->Text = "Simple";
	}
	if (tbBlackChance->Value == 1) {
		laDif->Text = "Med";
	}
	if (tbBlackChance->Value == 2) {
		laDif->Text = "Hard";
	}
}
//---------------------------------------------------------------------------

