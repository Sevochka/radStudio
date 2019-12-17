//---------------------------------------------------------------------------

#ifndef toDoListUnitH
#define toDoListUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.ActnList.hpp>
#include <FMX.Gestures.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <System.Actions.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.ListView.Adapters.Base.hpp>
#include <FMX.ListView.Appearances.hpp>
#include <FMX.ListView.hpp>
#include <FMX.ListView.Types.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Objects3D.hpp>
#include <System.Math.Vectors.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Dialogs.hpp>
//---------------------------------------------------------------------------
class TTabbedwithNavigationForm : public TForm
{
__published:	// IDE-managed Components
	TTabControl *TabControl1;
	TTabItem *tiToDo;
	TTabControl *TabControl2;
	TTabItem *TabItem5;
	TToolBar *ToolBar1;
	TSpeedButton *btnNext;
	TTabItem *TabItem6;
	TToolBar *ToolBar2;
	TLabel *lblTitle2;
	TSpeedButton *btnBack;
	TTabItem *tiMenu;
	TToolBar *ToolBar3;
	TLabel *lblTitle3;
	TTabItem *tiNote;
	TToolBar *ToolBar4;
	TLabel *laNote;
	TTabItem *tiTheme;
	TToolBar *ToolBar5;
	TLabel *lblTitle5;
	TActionList *ActionList1;
	TNextTabAction *NextTabAction;
	TPreviousTabAction *PreviousTabAction;
	TGestureManager *GestureManager1;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TGridPanelLayout *GridPanelLayout1;
	TButton *Button2;
	TLabel *Label1;
	TButton *buSettings;
	TListView *ListView1;
	TLinkListControlToField *LinkListControlToField1;
	TEdit *edTitle;
	TEdit *edDesc;
	TButton *buAdd;
	TLabel *Label3;
	TModel3D *Model3D1;
	TButton *buDelete;
	TLinkPropertyToField *LinkPropertyToFieldText3;
	TOpenDialog *OpenDialog1;
	TStyleBook *sbLight;
	TLabel *Label2;
	TLayout *Layout1;
	TLayout *Layout2;
	TLabel *Label4;
	TLayout *Layout3;
	TButton *Button4;
	TGridPanelLayout *GridPanelLayout2;
	TButton *Button1;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TStyleBook *sbDark;
	TStyleBook *sbStupid;
	TStyleBook *sbPutin;
	TButton *buMenuGo;
	TLayout *Layout4;
	TEdit *Edit1;
	TLayout *Layout5;
	TLinkControlToField *LinkControlToField1;
	TLinkPropertyToField *LinkPropertyToFieldText;
	TButton *Button3;
	TButton *Button8;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall TabControl1Gesture(TObject *Sender, const TGestureEventInfo &EventInfo,
          bool &Handled);
	void __fastcall ListView1ItemClick(TObject * const Sender, TListViewItem * const AItem);
	void __fastcall buAddClick(TObject *Sender);
	void __fastcall buDeleteClick(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall buSettingsClick(TObject *Sender);
	void __fastcall buMenuGoClick(TObject *Sender);
	void __fastcall btnBackClick(TObject *Sender);
	void __fastcall Label3DblClick(TObject *Sender);
	void __fastcall Layout5Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TTabbedwithNavigationForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTabbedwithNavigationForm *TabbedwithNavigationForm;
//---------------------------------------------------------------------------
#endif
