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
void Tfm::DoReset(){
	FCountCorrect = 0;
	FCountWrong = 0;
	RandomValue = 20;
	DoContinue();
}
//---------------------------------------------------------------------------
void Tfm::DoContinue(){
	laCorrect->Text = Format(L"Correct = %d", ARRAYOFCONST((FCountCorrect)));
	laWrong->Text = Format(L"Incorrect = %d", ARRAYOFCONST((FCountWrong)));
	//
	int xValue1 = Random(RandomValue);
	int xValue2 = Random(RandomValue);
	int xSign = (Random(2) == 1) ? 1: -1;

	if(RandomValue == 20){
		int xResult = xValue1 + xValue2;
		int xResultNew = (Random(2) == 1) ? xResult : xResult + (Random(7) * xSign);
		FAnswerCorrect = (xResult == xResultNew);
		laCode->Text = Format("%d + %d = %d", ARRAYOFCONST((xValue1, xValue2, xResultNew)));
	}


	else if(RandomValue == 50){
		int xMode = (Random(2) == 1) ? 1: -1;

		if(xMode == 1){
			int xResult = xValue1 + xValue2;
			int xResultNew = (Random(2) == 1) ? xResult : xResult + (Random(7) * xSign);
			FAnswerCorrect = (xResult == xResultNew);
			laCode->Text = Format("%d + %d = %d", ARRAYOFCONST((xValue1, xValue2, xResultNew)));
		}
		else{
			int xResult = xValue1 - xValue2;
			int xResultNew = (Random(2) == 1) ? xResult : xResult - (Random(7) * xSign);
			FAnswerCorrect = (xResult == xResultNew);
			laCode->Text = Format("%d - %d = %d", ARRAYOFCONST((xValue1, xValue2, xResultNew)));
		}

	}


	else if(RandomValue == 80){
	   int xMode = Random(3);
	   if(xMode == 1){
			int xResult = xValue1 + xValue2;
			int xResultNew = (Random(2) == 1) ? xResult : xResult + (Random(7) * xSign);
			FAnswerCorrect = (xResult == xResultNew);
			laCode->Text = Format("%d + %d = %d", ARRAYOFCONST((xValue1, xValue2, xResultNew)));
		}
		else if (xMode == 2) {
			int xResult = xValue1 - xValue2;
			int xResultNew = (Random(2) == 1) ? xResult : xResult - (Random(7) * xSign);
			FAnswerCorrect = (xResult == xResultNew);
			laCode->Text = Format("%d - %d = %d", ARRAYOFCONST((xValue1, xValue2, xResultNew)));
		}
		else{
			xSign = (Random(2) == 1) ? 1: 1.3;
			int xResult = xValue1 * xValue2;
			int xResultNew = (Random(2) == 1) ? xResult : xResult * (Random(7) * xSign);
			FAnswerCorrect = (xResult == xResultNew);
			laCode->Text = Format("%d * %d = %d", ARRAYOFCONST((xValue1, xValue2, xResultNew)));
		}
	}


	else if(RandomValue == 100){
	   int xMode = Random(4);
	   if(xMode == 1){
			int xResult = xValue1 + xValue2;
			int xResultNew = (Random(2) == 1) ? xResult : xResult + (Random(7) * xSign);
			FAnswerCorrect = (xResult == xResultNew);
			laCode->Text = Format("%d + %d = %d", ARRAYOFCONST((xValue1, xValue2, xResultNew)));
		}
		else if (xMode == 2) {
			int xResult = xValue1 - xValue2;
			int xResultNew = (Random(2) == 1) ? xResult : xResult - (Random(7) * xSign);
			FAnswerCorrect = (xResult == xResultNew);
			laCode->Text = Format("%d - %d = %d", ARRAYOFCONST((xValue1, xValue2, xResultNew)));
		}
		else if (xMode == 3) {
			xSign = (Random(2) == 1) ? 1: 1.3;
			int xResult = xValue1 * xValue2;
			int xResultNew = (Random(2) == 1) ? xResult : xResult * (Random(7) * xSign);
			FAnswerCorrect = (xResult == xResultNew);
			laCode->Text = Format("%d * %d = %d", ARRAYOFCONST((xValue1, xValue2, xResultNew)));
		}
	}



}
//---------------------------------------------------------------------------
void Tfm::DoAnswer(bool aValue){
	(aValue == FAnswerCorrect) ?
		FCountCorrect++ : FCountWrong++;
	DoContinue();
}
void __fastcall Tfm::buYesClick(TObject *Sender)
{
    DoAnswer(true);
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buNoClick(TObject *Sender)
{
    DoAnswer(false);
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buRestartClick(TObject *Sender)
{
    DoReset();
}
//---------------------------------------------------------------------------

void __fastcall Tfm::FormCreate(TObject *Sender)
{
	Randomize();
	DoReset();
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buAboutClick(TObject *Sender)
{
    ShowMessage("Huh. Fish in the bucket");
}
//---------------------------------------------------------------------------


void __fastcall Tfm::buEasyClick(TObject *Sender)
{
	RandomValue = 20;
	DoContinue();
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buNormalClick(TObject *Sender)
{

	RandomValue = 50;
	DoContinue();
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buHardClick(TObject *Sender)
{

	RandomValue = 80;
	DoContinue();
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buChallengingClick(TObject *Sender)
{

	RandomValue = 100;
	DoContinue();
}
//---------------------------------------------------------------------------

