//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmu.h"
#include "dmu.h"
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
void Tfm::SelectionAll(TObject *Sender)
{
	if (FSel != NULL) {
		FSel->HideSelection = true;
	}
	FSel = dynamic_cast<TSelection*>(Sender);
	if (FSel != NULL) {
        FSel->HideSelection = false;
	}
	//
	tbOptions->Visible = (FSel != NULL);
	if (tbOptions->Visible) {
		trRotation->Value = FSel->RotationAngle;
	}
	//
	tbImage->Visible = (FSel != NULL) && (dynamic_cast<TGlyph*>(FSel->Controls->Items[0]));

	tbRect->Visible = (FSel != NULL) && (dynamic_cast<TRectangle*>(FSel->Controls->Items[0]));

	tbText-> Visible = (FSel != NULL) && (dynamic_cast<TLabel*>(FSel->Controls->Items[0]));
	if (tbRect->Visible) {
		ComboColorBox->Color = ((TRectangle*)FSel->Controls->Items[0])->Fill->Color;
		trRectRadious->Value = ((TRectangle*)FSel->Controls->Items[0])->XRadius;
	}

	if (tbText->Visible) {
		ComboColorText->Color = ((TLabel*)FSel->Controls->Items[0])->FontColor;
		trRotation->Value = ((TLabel*)FSel->Controls->Items[0])->Font->Size;
	}

}
void __fastcall Tfm::FormCreate(TObject *Sender)
{
	FSel = NULL;
	SelectionAll(ly);
}
//---------------------------------------------------------------------------

void __fastcall Tfm::SelectionAllMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y)
{
	SelectionAll(Sender);
}
//---------------------------------------------------------------------------

void __fastcall Tfm::biBringToFrontClick(TObject *Sender)
{
	FSel->BringToFront();
	FSel->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buSendToBackClick(TObject *Sender)
{
	FSel->SendToBack();
	FSel->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall Tfm::trRotationChange(TObject *Sender)
{
	FSel->RotationAngle = trRotation->Value;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buDelClick(TObject *Sender)
{
	FSel->DisposeOf();
	FSel = NULL;
	SelectionAll(ly);
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buImagePrevClick(TObject *Sender)
{
	TGlyph *x = (TGlyph*)FSel->Controls->Items[0];
	x->ImageIndex = ((int)x->ImageIndex <= 0) ? dm->il->Count - 1 : (int)x->ImageIndex - 1;

}
//---------------------------------------------------------------------------

void __fastcall Tfm::buImageNextClick(TObject *Sender)
{
	TGlyph *x = (TGlyph*)FSel->Controls->Items[0];
	x->ImageIndex = ((int)x->ImageIndex >= dm->il->Count - 1) ? 0 : (int)x->ImageIndex + 1;

}
//---------------------------------------------------------------------------

void __fastcall Tfm::buImageSelectClick(TObject *Sender)
{
		//todod
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buImageRNDClick(TObject *Sender)
{
	TGlyph *x = (TGlyph*)FSel->Controls->Items[0];
	x->ImageIndex = Random(dm->il->Count);
}
//---------------------------------------------------------------------------

void __fastcall Tfm::ComboColorBoxChange(TObject *Sender)
{
	TRectangle *x = (TRectangle*)FSel->Controls->Items[0];
	x->Fill->Color = ComboColorBox->Color;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::trRectRadiousChange(TObject *Sender)
{
	TRectangle *x = (TRectangle*)FSel->Controls->Items[0];
	x->XRadius = trRectRadious->Value;
	x->YRadius = x->XRadius;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buNewImageClick(TObject *Sender)
{
	TSelection *x = new TSelection(ly);
	x->Parent = ly;
	x->GripSize = 7;
	x->Width = 50 + Random(100);
	x->Height = 50 + Random(100);
	x->Position->X = Random(ly->Width - x->Width);
	x->Position->Y = Random(ly->Height - x->Height);
	x->RotationAngle = Random(100) - 50;
	x->OnMouseDown = SelectionAllMouseDown;
	TGlyph *xGlyph = new TGlyph(x);
	xGlyph->Parent = x;
	xGlyph->Align = TAlignLayout::Client;
	xGlyph->Images = dm->il;
	xGlyph->ImageIndex = Random(dm->il->Count);
	//
	SelectionAll(x);
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buNewRectClick(TObject *Sender)
{

	TSelection *x = new TSelection(ly);
	x->Parent = ly;
	x->GripSize = 7;
	x->Width = 50 + Random(100);
	x->Height = 50 + Random(100);
	x->Position->X = Random(ly->Width - x->Width);
	x->Position->Y = Random(ly->Height - x->Height);
	x->RotationAngle = Random(100) - 50;
	x->OnMouseDown = SelectionAllMouseDown;
	TRectangle *xRectangle = new TRectangle(x);
	xRectangle->Parent = x;
	xRectangle->Align = TAlignLayout::Client;
	xRectangle->HitTest = false;
	xRectangle->XRadius = Random(20);
	xRectangle->YRadius = xRectangle->XRadius;
	xRectangle->Fill->Color = TAlphaColorF::Create(Random(256),Random(256),Random(256))
		.ToAlphaColor();

	//
	SelectionAll(x);
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buClearClick(TObject *Sender)
{
	SelectionAll(ly);
	for (int i = ly->ControlsCount-1; i >=0; i--) {
		if (dynamic_cast<TSelection*>(ly->Controls->Items[i])) {
			ly->RemoveObject(i);
		}

	}

}
//---------------------------------------------------------------------------


void __fastcall Tfm::ComboColorTextChange(TObject *Sender)
{
	TLabel *x = (TLabel*)FSel->Controls->Items[0];
	x->FontColor = ComboColorText->Color;

}
//---------------------------------------------------------------------------

void __fastcall Tfm::trTextSizeChange(TObject *Sender)
{
	TLabel *x = (TLabel*)FSel->Controls->Items[0];
	x->Font->Size = trTextSize->Value;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buNewLabelClick(TObject *Sender)
{
	TSelection *x = new TSelection(ly);
	x->Parent = ly;
	x->GripSize = 7;
	x->Width = 50 + Random(100);
	x->Height = 50 + Random(100);
	x->Position->X = Random(ly->Width - x->Width);
	x->Position->Y = Random(ly->Height - x->Height);
	x->RotationAngle = Random(100) - 50;
	x->OnMouseDown = SelectionAllMouseDown;
	TLabel *xLabel = new TLabel(x);
	xLabel->Parent = x;
	xLabel->Align = TAlignLayout::Client;
	xLabel->HitTest = false;
	xLabel->Text = "Hello, World";


	xLabel->FontColor = TAlphaColorF::Create(Random(256),Random(256),Random(256))
		.ToAlphaColor();

	//
	SelectionAll(x);
}
//---------------------------------------------------------------------------

