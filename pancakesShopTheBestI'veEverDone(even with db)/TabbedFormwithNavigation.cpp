//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "TabbedFormwithNavigation.h"
#include "dmu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

TTabbedwithNavigationForm *TabbedwithNavigationForm;
//---------------------------------------------------------------------------
__fastcall TTabbedwithNavigationForm::TTabbedwithNavigationForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTabbedwithNavigationForm::FormCreate(TObject *Sender)
{
	// This defines the default active tab at runtime
	TabControl1->ActiveTab = tbMenu;
	TabControl1->TabPosition = TTabPosition::None;
    TabControl2->TabPosition = TTabPosition::None;
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::FormKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if(Key == vkHardwareBack) {
		if(TabControl1->ActiveTab == tbMenu) {
			TabControl2->Previous(TTabTransition::Slide, TTabTransitionDirection::Normal);
			Key = 0;
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TTabbedwithNavigationForm::TabControl1Gesture(TObject *Sender, const TGestureEventInfo &EventInfo,
		  bool &Handled)
{
	switch (EventInfo.GestureID) {
		case sgiLeft :
			if(TabControl1->ActiveTab != TabControl1->Tabs[TabControl1->TabCount-1]) {
				TabControl1->ActiveTab = TabControl1->Tabs[TabControl1->TabIndex+1];
				Handled = true;
			}
			break;
		case sgiRight :
			if(TabControl1->ActiveTab != TabControl1->Tabs[0]) {
				TabControl1->ActiveTab = TabControl1->Tabs[TabControl1->TabIndex-1];
				Handled = true;
			}
			break;
	default:
		;
	}
}
//---------------------------------------------------------------------------


void __fastcall TTabbedwithNavigationForm::buPancakesClick(TObject *Sender)
{
	TabControl1->GotoVisibleTab(tbProducts->Index);
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::lvCategoryItemClick(TObject * const Sender,
		  TListViewItem * const AItem)
{
	TabControl1->GotoVisibleTab(tbProducts->Index);
}
//---------------------------------------------------------------------------


void __fastcall TTabbedwithNavigationForm::lvProductsItemClick(TObject * const Sender,
		  TListViewItem * const AItem)
{
	TabControl1->GotoVisibleTab(tbItem->Index);
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::buThemeClick(TObject *Sender)
{
	if (TabbedwithNavigationForm->StyleBook == sbLight) {
		  TabbedwithNavigationForm->StyleBook = sbDark;
		  buTheme->Text = "Theme: Dark";
	}
	else{
		 TabbedwithNavigationForm->StyleBook = sbLight;
		 buTheme->Text = "Theme: Light";
	}

}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::buSendFeedbackClick(TObject *Sender)
{
	dm->FeedbackIns(
	edFeedbackFIO->Text
	,edFeedbackPhone->Text
	,edFeedbackEmail->Text
	,meFeedbackNote->Text
	);
	ShowMessage("Feedback was sent!");
	TabControl1->GotoVisibleTab(tbMenu->Index);
	dm->quFeedback->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::buFeedbackClick(TObject *Sender)
{
	TabControl1->GotoVisibleTab(tbFeedbackList->Index);
}
//---------------------------------------------------------------------------


void __fastcall TTabbedwithNavigationForm::buBackFeedbackClick(TObject *Sender)
{
	TabControl1->GotoVisibleTab(tbMenu->Index);
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::buBackItemClick(TObject *Sender)
{
	  TabControl1->GotoVisibleTab(tbProducts->Index);
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::buContactsClick(TObject *Sender)
{
    ShowMessage("Kochnev Seva 171-333 gmail: sevkaplay@gmail.com");
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::buFeedClick(TObject *Sender)
{
	 TabControl1->GotoVisibleTab(tbFeedback->Index);
     dm->quFeedback->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::buBagAddClick(TObject *Sender)
{
	  dm->AddToCart(
	(Label2->Text).ToInt()
	,(laPrice->Text).ToDouble()
	,1
	,laPanChanged->Text
	);
	ShowMessage("Добавлено в корзину");
	TabControl1->GotoVisibleTab(tbMenu->Index);
    dm->quOrder->Refresh();
}
//---------------------------------------------------------------------------


void __fastcall TTabbedwithNavigationForm::buDeliveryClick(TObject *Sender)
{
	TabControl1->GotoVisibleTab(tbTerms->Index);
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::buBuyClick(TObject *Sender)
{
	 dm->BuyIns(
	edFIO2->Text
	,edPhone2->Text
	,edEmail->Text
	,edAddress->Text
	,edNote->Text
	);
	ShowMessage("Ждите доставку. Отправленно!");
	TabControl1->GotoVisibleTab(tbMenu->Index);
	dm->quOrder->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::ButtonAllClick(TObject *Sender)
{
	if (((TButton*)Sender)->Tag == 3) {
        if (counter == 3) {
			TabControl1->GotoVisibleTab(tbMenu->Index);
			ShowMessage("WIN. You discount is 10%");
			return;
		}
		else{
			TabControl1->GotoVisibleTab(tbMenu->Index);
			ShowMessage("LOSE.");
			return;
        }
	}
	if (((TButton*)Sender)->Tag == Glyph1->ImageIndex) {
		counter++;
	}
	Glyph1->ImageIndex = Glyph1->ImageIndex+1;

}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::buQuizClick(TObject *Sender)
{
	 TabControl1->GotoVisibleTab(tbQuiz->Index);
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::Button2Click(TObject *Sender)
{
	TabControl1->GotoVisibleTab(tbBuy->Index);
}
//---------------------------------------------------------------------------


void __fastcall TTabbedwithNavigationForm::buBagClick(TObject *Sender)
{
	 TabControl1->GotoVisibleTab(tbCart->Index);
}
//---------------------------------------------------------------------------

