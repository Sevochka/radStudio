//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmu.h"
#include <dos.h>
#include <windows.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tfm *fm;
//---------------------------------------------------------------------------
__fastcall Tfm::Tfm(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall Tfm::FormCreate(TObject *Sender)
{
	Randomize();
	tc->First();
	tc->TabPosition = TTabPosition::None;
	balance = 500;
	laBalance->Text = Format("Balance: %d RUB", ARRAYOFCONST((balance)));
	laMinus->Visible = false;
	laPlus->Visible = false;
	isRouletteSpinning = false;


	//Start chances and tabs initialize
	zeroChance = 1;
	blackChance = 50;
	redChance = 50;

}
//---------------------------------------------------------------------------
void Tfm::ChangeImg(int imgValue){
	//gs1->ImageIndex = imgValue;
	//gs2->ImageIndex = imgValue;
	//gs3->ImageIndex = imgValue;
	//gs4->ImageIndex = imgValue;
	//gs5->ImageIndex = imgValue;
	//gs6->ImageIndex = imgValue;
	//gs7->ImageIndex = imgValue;
	//gs8->ImageIndex = imgValue;
	//gs9->ImageIndex = imgValue;
	//gs10->ImageIndex = imgValue;
	//gs11->ImageIndex = imgValue;
	//gs12->ImageIndex = imgValue;
	//gs13->ImageIndex = imgValue;
	//gs14->ImageIndex = imgValue;
	//gs15->ImageIndex = imgValue;
	//gs16->ImageIndex = imgValue;
	//gs17->ImageIndex = imgValue;
	//gs18->ImageIndex = imgValue;
	//gs19->ImageIndex = imgValue;

	if (imgValue == 1) {
		laCaptionHalf1->Text = "You Won't";
	}
}
//---------------------------------------------------------------------------
void Tfm::DetermineWinColor(int colorNum){

	int imgValue;
	if (chosenColor == colorNum) {
		imgValue = 0;
		if (chosenColor == 2) {
		  balance = balance + bet*10;
		  laPlus->Text = Format("+%d", ARRAYOFCONST((bet*10)));;
		}
		else{
		  balance = balance + bet*2;
		  laPlus->Text = Format("+%d", ARRAYOFCONST((bet*2)));;
		}
		laPlus->Visible = true;
		animPlusPosition->Enabled = true;
		animPlusOpasity->Enabled = true;
	}
	else{
		imgValue = 1;
	}

	animMinusPosition->Enabled = false;
	animMinusOpasity->Enabled = false;

	isRouletteSpinning = false;
	MakeStartButtonsEnabled(false);
	MakeBetButtonsEnabled(true);

	laBalance->Text = balance;
	laBalance->Text = Format("Balance: %d RUB", ARRAYOFCONST((balance)));
	ChangeImg(imgValue);
	tSmile->Enabled = true;

	tLoading->Enabled = false;
	laBet->Text = "Make Your Bet";

	bet = 0;
	edBet->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall Tfm::tRouletteTimer(TObject *Sender)
{
    //x1, x2 - previous color variables

	isRouletteSpinning = true;

	if (TimeToStr(Now() - FTimeStart) == "0:00:07") {
	  tRoulette->Enabled = false;
	  DetermineWinColor(g5->ImageIndex);
	}
	else{
		tRoulette->Interval = tRoulette->Interval + tRoulette->Interval/17;

		if (Random(100) <= zeroChance) {
			isColor = 2;
		}
		else{
			if (Random(100) < blackChance)  {
				isColor = 0;
			}
			else{
				isColor = 1;
			}
		 }


		x1 = g1->ImageIndex;
			g1->ImageIndex = isColor;
		x2 = g2->ImageIndex;
			g2->ImageIndex = x1;
		x1 = g3->ImageIndex;
			g3->ImageIndex = x2;
		x2 = g4->ImageIndex;
			g4->ImageIndex = x1;
		x1 = g5->ImageIndex;
			g5->ImageIndex = x2;
		x2 = g6->ImageIndex;
			g6->ImageIndex = x1;
		x1 = g7->ImageIndex;
			g7->ImageIndex = x2;
		x2 = g8->ImageIndex;
			g8->ImageIndex = x1;
		x1 = g9->ImageIndex;
			g9->ImageIndex = x2;
    }


}
//---------------------------------------------------------------------------




void __fastcall Tfm::tSmileTimer(TObject *Sender)
{
		//2 - blank image
		ChangeImg(2);
		laCaptionHalf1->Text = "You Will";

		tSmile->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall Tfm::buttonAllMouseEnter(TObject *Sender)
{
 	TButton *x = ((TButton*)Sender);
	x->Margins->Rect = TRect(0,0,0,0);
	x->TextSettings->Font->Size += 10;

}
//---------------------------------------------------------------------------

void __fastcall Tfm::buttonAllMouseLeave(TObject *Sender)
{
	TButton *x = ((TButton*)Sender);
	x->Margins->Rect = TRect(5,5,5,5);
	x->TextSettings->Font->Size -= 10;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buAboutClick(TObject *Sender)
{

	MessageBox (NULL,L"There are so many hidden features. I don't want to describe them all. So find it by yourself. Actually it took a lot to figure out how to perform here. I should say I've never done something better than these pop-ups. I know they're awful, but they're MINE! I HATE the fucking system of configuring columns. I LOST ALL MY BRAIN CELLS DOING THAT STUFF THANKS FOR LISTENING I'M DONE! I LITERALY HAVE ANGER ISSUES!",L"Author's Words", NULL);
}
//---------------------------------------------------------------------------




void __fastcall Tfm::edBetChangeTracking(TObject *Sender)
{
	int counter;
	String num = "1234567890";
	String text = edBet->Text;
	bool flag = true;

	if (text.Length() == 6) {
		laBet->Text = "Make Your REAL Bet";
		edBet->Text = "";
		MakeStartButtonsEnabled(false);
		ShowMessage("Don't lie. You haven't got such money.");
	}

	if (edBet->Text == "") {
		laBet->Text = "Make Your Bet";
		MakeStartButtonsEnabled(false);
		return;
	}

	for (int i = 0; i < text.Length(); i++) {
		for (int j = 1; j < num.Length()+1; j++) {

			if (text.SubString(i+1,1) == num[j]) {
				flag = false;
			}
		}
		if (flag) {
			edBet->Text = "";
			MakeStartButtonsEnabled(false);
			ShowMessage("Oopsie, you entered an unexpected symbol for [NUMBER] BET. Use [INTEGER] numbers only!.");
			return;
		}
		else{
			flag = true;
		}
	}

	MakeStartButtonsEnabled(true);
	bet = StrToInt(edBet->Text);
	laBet->Text = Format("Your bet is %d", ARRAYOFCONST((bet)));
}
//---------------------------------------------------------------------------



void __fastcall Tfm::buttonsBetClick(TObject *Sender)
{
	TButton *x = ((TButton*)Sender);
	bet = StrToInt(x->Text);
	edBet->Text = "";
	laBet->Text = Format("Your bet is %d", ARRAYOFCONST((bet)));
	MakeStartButtonsEnabled(true);

}
//---------------------------------------------------------------------------

void __fastcall Tfm::buttonsStartSpinning(TObject *Sender)
{

	if (bet > balance) {
		ShowMessage("Oopsie, you haven't got such money.");
		edBet->Text = "";
		return;
	}

	TButton *x = ((TButton*)Sender);
	chosenColor = x->Tag;
	balance = balance - bet;
    laBalance->Text = Format("Balance: %d RUB", ARRAYOFCONST((balance)));
	FTimeStart = Now();
	tRoulette->Interval = 30;
	tRoulette->Enabled = true;

	tLoading->Enabled = true;

	MakeStartButtonsEnabled(false);
	MakeBetButtonsEnabled(false);

	laMinus->Text = Format("-%d", ARRAYOFCONST((bet)));;
	laMinus->Visible = true;
	animMinusPosition->Enabled = true;
	animMinusOpasity->Enabled = true;

	laPlus->Visible = false;
	animPlusPosition->Enabled = false;
	animPlusOpasity->Enabled = false;




}
//---------------------------------------------------------------------------
void Tfm::MakeStartButtonsEnabled(bool flag){
	if (!isRouletteSpinning) {
		buBlack->Enabled = flag;
		buZero->Enabled = flag;
		buRed->Enabled = flag;
	}
}
//---------------------------------------------------------------------------
void Tfm::MakeBetButtonsEnabled(bool flag){
	bu25->Enabled = flag;
	bu50->Enabled = flag;
	bu100->Enabled = flag;
	bu200->Enabled = flag;
	bu500->Enabled = flag;
	edBet->Enabled = flag;
}
void __fastcall Tfm::tLoadingTimer(TObject *Sender)
{
    tLoading->Interval = 250;
	spinCounter++;
	if (spinCounter == 1) {
		laBet->Text = "Spinning";
	}
	else if (spinCounter == 2){
		laBet->Text = "Spinning.";
	}
	else if (spinCounter == 3){
		laBet->Text = "Spinning..";
	}
	else if (spinCounter == 4){
		laBet->Text = "Spinning...";
        spinCounter = 0;
    }

}
//---------------------------------------------------------------------------

void __fastcall Tfm::buSettingsClick(TObject *Sender)
{
	tc->Next();
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buThemeClick(TObject *Sender)
{
	if (buTheme->Text == "Light") {
	  fm->StyleBook = sbLight;
	  buTheme->Text = "Dark";
	  return;
	}
	fm->StyleBook = sbDark;
	buTheme->Text = "Light";

}
//---------------------------------------------------------------------------

void __fastcall Tfm::buPreviousClick(TObject *Sender)
{
	zeroChance = 100 - tbZeroChance->Value;;
	blackChance = tbBlackChance->Value;
	tc->Previous();
}
//---------------------------------------------------------------------------

void __fastcall Tfm::tbBlackChanceChange(TObject *Sender)
{
   laBlackChance->Text = tbBlackChance->Value;
   laRedChance->Text = 100 - tbBlackChance->Value;

}
//---------------------------------------------------------------------------


void __fastcall Tfm::tbZeroChanceChange(TObject *Sender)
{
	laBRChance->Text = tbZeroChance->Value;
	laZeroChance->Text = 100 - tbZeroChance->Value;
}
//---------------------------------------------------------------------------


