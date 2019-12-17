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
void Tdm::addNoteToDo(UnicodeString aTitle, UnicodeString aDesc) {
	addNote->ParamByName("TITLE")->Value = aTitle;
	addNote->ParamByName("DESCRIPTION")->Value = aDesc;
    addNote->ExecProc();
}
