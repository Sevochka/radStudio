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