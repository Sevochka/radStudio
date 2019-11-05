//---------------------------------------------------------------------------

#ifndef fmuH
#define fmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListView.Adapters.Base.hpp>
#include <FMX.ListView.Appearances.hpp>
#include <FMX.ListView.hpp>
#include <FMX.ListView.Types.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
//---------------------------------------------------------------------------
class Tfm : public TForm
{
__published:	// IDE-managed Components
	TTabControl *tc;
	TToolBar *ToolBar1;
	TLabel *laTitle;
	TButton *buAbout;
	TTabItem *tList;
	TTabItem *tilItem;
	TListView *ListView2;
	TButton *buAdd;
	TLayout *Layout1;
	TMemo *meDetail;
	TLabel *Label1;
	TEdit *edCaption;
	TLabel *Label2;
	TTrackBar *tbPriority;
	TLabel *Label3;
	TLayout *Layout2;
	TButton *buSave;
	TButton *buDelete;
	TButton *buCancel;
	TToolBar *ToolBar2;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TLinkListControlToField *LinkListControlToField1;
	TLinkControlToField *LinkControlToField1;
	TLinkControlToField *LinkControlToField2;
	TLinkControlToField *LinkControlToField3;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall buAddClick(TObject *Sender);
	void __fastcall buSaveClick(TObject *Sender);
	void __fastcall ListView2ItemClick(TObject * const Sender, TListViewItem * const AItem);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall buCancelClick(TObject *Sender);
	void __fastcall buDeleteClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall Tfm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfm *fm;
//---------------------------------------------------------------------------
#endif
