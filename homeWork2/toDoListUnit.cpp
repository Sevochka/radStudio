//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "toDoListUnit.h"
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
	TabControl1->ActiveTab = tiMenu;
	TabControl2->ActiveTab = TabItem5;
	TabControl1->TabPosition = TTabPosition::None;
	TabControl2->TabPosition = TTabPosition::None;
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::FormKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if(Key == vkHardwareBack) {
		if(TabControl1->ActiveTab == tiMenu && TabControl2->ActiveTab == TabItem5) {
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

void __fastcall TTabbedwithNavigationForm::ListView1ItemClick(TObject * const Sender,
		  TListViewItem * const AItem)
{
	TabControl1->GotoVisibleTab(tiNote->Index);
	note = laNote->Text;
}
//---------------------------------------------------------------------------



void __fastcall TTabbedwithNavigationForm::buAddClick(TObject *Sender)
{
	if((edTitle->Text != "") && (edDesc->Text != ""))
	{
		//dm->addToDo->ParamByName("NewTitle")->Value = edTitle->Text;
		//dm->addToDo->ParamByName("NewDesc")->Value = edDesc->Text;
		//dm->addToDo->ExecSQL();
		dm->addNoteToDo(edTitle->Text, edDesc->Text);
		TabControl2->GotoVisibleTab(TabItem5->Index);
		edDesc->Text = "";
		edTitle->Text = "";
		dm->toDo->Close();
		dm->toDo->Open();
	}
}
//---------------------------------------------------------------------------


void __fastcall TTabbedwithNavigationForm::buDeleteClick(TObject *Sender)
{
		dm->delToDo->ParamByName("NewTitle")->Value = laNote->Text;
		dm->delToDo->ExecSQL();
		TabControl1->GotoVisibleTab(tiToDo->Index);
        dm->toDo->Close();
		dm->toDo->Open();
}
//---------------------------------------------------------------------------




void __fastcall TTabbedwithNavigationForm::goBackClick(TObject *Sender)
{
	TabControl1->GotoVisibleTab(tiToDo->Index);
    dm->toDo->Close();
	dm->toDo->Open();


}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::Button2Click(TObject *Sender)
{
	dm->toDo->Close();
	dm->toDo->Open();
	TabControl1->GotoVisibleTab(tiToDo->Index);
}
//---------------------------------------------------------------------------


void __fastcall TTabbedwithNavigationForm::Button7Click(TObject *Sender)
{
	TabbedwithNavigationForm->StyleBook = sbLight;
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::Button1Click(TObject *Sender)
{
	TabbedwithNavigationForm->StyleBook = sbDark;
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::Button5Click(TObject *Sender)
{
	 TabbedwithNavigationForm->StyleBook = sbStupid;
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::Button6Click(TObject *Sender)
{
	TabbedwithNavigationForm->StyleBook = sbPutin;
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::buSettingsClick(TObject *Sender)
{
	TabControl1->GotoVisibleTab(tiTheme->Index);
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::buMenuGoClick(TObject *Sender)
{
   TabControl1->GotoVisibleTab(tiMenu->Index);
}
//---------------------------------------------------------------------------


void __fastcall TTabbedwithNavigationForm::btnBackClick(TObject *Sender)
{
    TabControl1->GotoVisibleTab(TabItem5->Index);
	dm->toDo->Close();
	dm->toDo->Open();

}
//---------------------------------------------------------------------------



void __fastcall TTabbedwithNavigationForm::Layout5Click(TObject *Sender)
{
	edTi->Visible = false;
	edDi->Visible = false;
	laDi->Visible = true;
	laNote->Visible = true;

	goBack->Enabled = true;
    dm->editNote->ParamByName("NewTitle")->Value = edTi->Text;
	dm->editNote->ParamByName("NewDesc")->Value = edDi->Text;
	dm->editNote->ParamByName("Title")->Value = note;
	dm->editNote->ExecSQL();
}
//---------------------------------------------------------------------------



void __fastcall TTabbedwithNavigationForm::laNoteDblClick(TObject *Sender)
{
	edTi->Visible = true;
	laNote->Visible = false;
	goBack->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::laDiDblClick(TObject *Sender)
{
    laDi->Visible = false;
	edDi->Visible = true;
	goBack->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TTabbedwithNavigationForm::Button8Click(TObject *Sender)
{
	TabControl2->GotoVisibleTab(TabItem5->Index);
}
//---------------------------------------------------------------------------

