//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buSaveClick(TObject *Sender)
{
    ta->Post();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buCancelClick(TObject *Sender)
{
    ta->Cancel();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buFilterOnClick(TObject *Sender)
{
	ta->Filter = edFilter->Text;
    ta->Filtered = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CancelClick(TObject *Sender)
{
    ta->Filter = edFilter->Text;
	ta->Filtered = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buSaveToFileClick(TObject *Sender)
{
	ta->SaveToFile(Ioutils::TPath::GetDocumentsPath() + PathDelim + edFileName->Text + ".json");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buLoadFromFileClick(TObject *Sender)
{
	ta->LoadFromFile(Ioutils::TPath::GetDocumentsPath() + PathDelim + edFileName->Text + ".json");
}

//---------------------------------------------------------------------------
void __fastcall TForm1::buAddAge1Click(TObject *Sender)
{
	ta->Edit();
	taAge->Value += 1;
	ta->Post();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buAddAge100Click(TObject *Sender)
{
	ta->First();
	while(! ta -> Eof) {
		ta->Edit();
		taMoney->Value +=100;
		ta->Post();
        ta->Next();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Change(TObject *Sender)
{
	Grid1->ReadOnly = CheckBox1->IsChecked;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox2Change(TObject *Sender)
{
	ta->ReadOnly = CheckBox2->IsChecked;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buLocateClick(TObject *Sender)
{
	ta->Locate(taAge->FieldName, edL->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buLookupClick(TObject *Sender)
{
	ShowMessage(ta->Lookup(taAge->FieldName, edL->Text, taFIO->FieldName));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::getSumClick(TObject *Sender)
{
	int sum;
	for (int i = 0; i < ; i++) {
		ta->Lookup(taMoney->
	}
}
//---------------------------------------------------------------------------
