// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmu.h"
#include "dmu.h"
#include "fruCategory.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tfm *fm;

// ---------------------------------------------------------------------------
__fastcall Tfm::Tfm(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall Tfm::FormCreate(TObject *Sender) {
	tc->ActiveTab = tiMenu;
	tc->TabPosition = TTabPosition::Dots;
}

// ---------------------------------------------------------------------------
void __fastcall Tfm::buFeedbackClick(TObject *Sender) {
	tc->ActiveTab = tiFeedback;
}
// ---------------------------------------------------------------------------

void __fastcall Tfm::buBackAllClick(TObject *Sender) {
	tc->ActiveTab = tiMenu;
}

// ---------------------------------------------------------------------------
void __fastcall Tfm::buStoreClick(TObject *Sender) {
	tc->ActiveTab = tiCategory;
}

// ---------------------------------------------------------------------------
void __fastcall Tfm::buSendFeedbackClick(TObject *Sender) {
	dm->FeedbackIns(edFeedbackFIO->Text, edFeedbackPhone->Text,
		edFeedbackEmail->Text, meFeedbackNote->Text);
	ShowMessage("Отзыв отправлен");
	tc->GotoVisibleTab(tiMenu->Index);
}

// ---------------------------------------------------------------------------
void Tfm::ReloadCategoryList() {
	dm->quCategory->First();
	while (!dm->quCategory->Eof) {
		TfrCategory *x = new TfrCategory(glCategory);
		x->Parent = glCategory;
		x->Align = TAlignLayout::Client;
		x->Name = "frCategory" + IntToStr(dm->quCategoryID->Value);
		x->la->Text = dm->quCategoryNAME->Value;
		x->im->Bitmap->Assign(dm->quCategoryIMAGE);
		x->OnClick = CeilClick;
		dm->quCategory->Next();
	}
	glCategory->RecalcSize();
}

void __fastcall Tfm::glCategoryResize(TObject *Sender) {
	float x = (glCategory->Width < 400) ? glCategory->Width :
		glCategory->Width / 2;

	glCategory->ItemHeight = x;
	glCategory->ItemWidth = x;
	glCategory->Height =
		Ceil((glCategory->ComponentCount - 1) /
		(glCategory->Width / glCategory->ItemWidth)) * glCategory->ItemHeight;
}
// ---------------------------------------------------------------------------

void __fastcall Tfm::FormShow(TObject *Sender) {
	ReloadCategoryList();
}

// ---------------------------------------------------------------------------
void __fastcall Tfm::CeilClick(TObject *Sender) {
	int xCategoryID = ((TControl*)Sender)->Tag;

	TLocateOptions xLO;
	dm->quCategory->Locate(dm->quCategoryID->FieldName, xCategoryID, xLO);

	tc->GotoVisibleTab(tiProductList->Index);
}

// ---------------------------------------------------------------------------
void __fastcall Tfm::lvProductItemClick(TObject * const Sender,
	TListViewItem * const AItem)

{
	tc->GotoVisibleTab(tiProduct->Index);
}
// ---------------------------------------------------------------------------
