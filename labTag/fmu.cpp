//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TTag *Tag;
//---------------------------------------------------------------------------
__fastcall TTag::TTag(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTag::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	tc->TabPosition = TTabPosition::None;
	tc->ActiveTab = tiPlay;

	if(Key == vkLeft){
		m[2]->ImageIndex = 0;
		m[3]->ImageIndex = 1;
	}
	if(Key == vkRight) {
		m[2]->ImageIndex = 1;
		m[3]->ImageIndex = 0;
	}
}
//---------------------------------------------------------------------------
void __fastcall TTag::FormCreate(TObject *Sender)
{
	m[0] = Glyph1;
	m[1] = Glyph2;
	m[2] = Glyph3;
	m[3] = Glyph4;
	m[4] = Glyph5;
	m[5] = Glyph6;
	m[6] = Glyph7;
	m[7] = Glyph8;
	m[8] = Glyph9;
}
//---------------------------------------------------------------------------
void __fastcall TTag::Layout1Click(TObject *Sender)
{
	int i = ((TGlyph*)Sender)->Tag;
	ShowMessage(i);
}
//---------------------------------------------------------------------------
