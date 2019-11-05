//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tfm *fm;

inline int Low(const UnicodeString &)
{
#ifdef _DELPHI_STRING_ONE_BASED
	return 1;
#else
	return 0;
#endif
}

inline int High(const UnicodeString &S)
{	
#ifdef _DELPHI_STRING_ONE_BASED
	return S.Length();
#else
	return S.Length()-1;
#endif
}

//---------------------------------------------------------------------------
__fastcall Tfm::Tfm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfm::FormCreate(TObject *Sender)
{
	tc->First();

	UnicodeString x;
	//Accross a line
	for (int i = 1; i < meFull->Lines->Count; i++) {
		x = meFull->Lines->Strings[i];
		if(i%2==1){
			
			for(int j = Low(x); j <= High(x); j++){
				if(x[j] != ' ')
					x[j] = 'x';
			}
		}
		me1->Lines->Add(x);
	}

	//Fisrt words
	bool xFlag;
	for (int i = 0; i < meFull->Lines->Count; i++) {
		x = meFull->Lines->Strings[i];
		xFlag = false;
		for(int j = Low(x); j<= High(x) ;j++){
			if ((xFlag) && (x[j] != ' '))
				x[j] = 'x';
			if ((!xFlag) && (x[j] == ' ')) {
				xFlag = true;
			}
		}
		me2->Lines->Add(x);
		
	}

	//First letter
	bool xFlag2;
	for (int i = 0; i < meFull->Lines->Count; i++) {
		x = meFull->Lines->Strings[i];
		xFlag2 = false;
		for(int j = Low(x); j<= High(x) ;j++){
			if ((xFlag2) && (x[j] != ' '))
				x[j] = 'x';
			if (j<3) {
				xFlag2 = true;
			
			}
		}
		me3->Lines->Add(x);
		
	}
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buSizeOutClick(TObject *Sender)
{
	meFull->TextSettings->Font->Size -= 2;
	me1->TextSettings->Font->Size -= 2;	
	me2->TextSettings->Font->Size -= 2;
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buSizeInClick(TObject *Sender)
{
	meFull->TextSettings->Font->Size += 2;
	me1->TextSettings->Font->Size += 2;	
	me2->TextSettings->Font->Size += 2;	
}
//---------------------------------------------------------------------------
