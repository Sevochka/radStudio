//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "dmu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tdm *dm;
//---------------------------------------------------------------------------
__fastcall Tdm::Tdm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tdm::FormCreate(TObject *Sender)
{
	FDConnection1->Params->Values["DataBase"] = "..\\..\\BLINCHIKI.FDB";
    FDConnection1->Connected = true;
}
//---------------------------------------------------------------------------
void __fastcall Tdm::FDConnection1AfterConnect(TObject *Sender)
{
	quCategory->Open();
	quProducts->Open();
	quFeedback->Open();
    quOrder->Open();
}
//---------------------------------------------------------------------------
void Tdm::FeedbackIns(UnicodeString aFIO, UnicodeString aPhone,
	UnicodeString aEmail, UnicodeString aNote)
{
	spFeedbackIns->ParamByName("FIO")->Value=aFIO;
	spFeedbackIns->ParamByName("PHONE")->Value=aPhone;
	spFeedbackIns->ParamByName("EMAIL")->Value=aEmail;
	spFeedbackIns->ParamByName("NOTE")->Value=aNote;
	spFeedbackIns->ExecProc();
}
//---------------------------------------------------------------------------
void Tdm::AddToCart(int aId, double aPrice,
	int aQu, UnicodeString aName)
{
	spAddToCart->ParamByName("PRODUCT_ID")->Value=1;
	spAddToCart->ParamByName("PRODUCT_PRICE")->Value=aPrice;
	spAddToCart->ParamByName("QUANTITY")->Value=aQu;
	spAddToCart->ParamByName("NAME")->Value=aName;
	spAddToCart->ExecProc();
}
//---------------------------------------------------------------------------
void Tdm::BuyIns(UnicodeString aFIO, UnicodeString aPhone, UnicodeString aEmail, UnicodeString aAddress, UnicodeString aNote)
{
	spBuy->ParamByName("CLIENT_FIO")->Value=aFIO;
	spBuy->ParamByName("CLIENT_TEL")->Value=aPhone;
	spBuy->ParamByName("CLIENT_EMAIL")->Value=aEmail;
	spBuy->ParamByName("CLIENT_ADDRESS")->Value=aAddress;
	//spBuy->ParamByName("CLIENT_DATE")->Value=aDate;
	//spBuy->ParamByName("CLIENT_TIME")->Value=aTime;
	spBuy->ParamByName("CLIENT_NOTE")->Value=aNote;
	spBuy->ExecProc();
}
