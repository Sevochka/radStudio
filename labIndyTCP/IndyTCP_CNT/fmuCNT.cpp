//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmuCNT.h"
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
void __fastcall Tfm::acConnectExecute(TObject *Sender)
{
	IdTCPClient->Host = edHost->Text;
	IdTCPCLient->Port = StrToInt(edport->Text);
    IdTCPClient->Connect();
}
//---------------------------------------------------------------------------
void __fastcall Tfm::acDisconnectExecute(TObject *Sender)
{
    IdTCPClient->Disconnect();
}
//---------------------------------------------------------------------------
void __fastcall Tfm::acGetTimeExecute(TObject *Sender)
{
	IdTCPClient->Socket->WriteLn("time");
	UnicodeString x;
	x = IdTCPClient->Socket->ReadLn();
	me->Lines->Add(x);
}
//---------------------------------------------------------------------------
void __fastcall Tfm::acGetStrExecute(TObject *Sender)
{
	IdTCPClient->Socket->WriteLn("str");
	UnicodeString x;
	x = IdTCPClient->Socket->ReadLn();
	me->Lines->Add(x);
}
//---------------------------------------------------------------------------
