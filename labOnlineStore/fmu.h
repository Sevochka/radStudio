// ---------------------------------------------------------------------------

#ifndef fmuH
#define fmuH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
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
#include <FMX.Objects.hpp>

// ---------------------------------------------------------------------------
class Tfm : public TForm {
__published: // IDE-managed Components
	TToolBar *tbMenu;
	TGridPanelLayout *GridPanelLayout1;
	TLayout *lyMenu;
	TTabControl *tc;
	TTabItem *tiMenu;
	TTabItem *tiCategory;
	TTabItem *tiFeedback;
	TGridLayout *glCategory;
	TToolBar *tbCategory;
	TLabel *Label1;
	TLabel *Label2;
	TButton *buBack;
	TButton *buStore;
	TButton *buBasket;
	TButton *buFeedback;
	TButton *buAbout;
	TToolBar *ToolBar1;
	TScrollBox *ScrollBox1;
	TLabel *Label3;
	TEdit *edFeedbackFIO;
	TLabel *Label4;
	TEdit *edFeedbackPhone;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *edFeedbackEmail;
	TMemo *meFeedbackNote;
	TButton *buSendFeedback;
	TLabel *Label7;
	TButton *Button4;
	TScrollBox *ScrollBox2;
	TTabItem *tiProductList;
	TLayout *Layout1;
	TListView *lvProduct;
	TButton *Button1;
	TLabel *Label8;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TLinkListControlToField *LinkListControlToField1;
	TTabItem *tiProduct;
	TLayout *Layout2;
	TGridPanelLayout *GridPanelLayout2;
	TButton *addProduct;
	TButton *Button2;
	TImage *Image1;
	TText *Text1;
	TLabel *Label9;
	TLabel *Label10;
	TLinkPropertyToField *LinkPropertyToFieldBitmap;
	TLinkPropertyToField *LinkPropertyToFieldText;
	TLinkPropertyToField *LinkPropertyToFieldText2;
	TButton *Button3;
	TLabel *Label11;

	void __fastcall buFeedbackClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall buBackAllClick(TObject *Sender);
	void __fastcall buStoreClick(TObject *Sender);
	void __fastcall buSendFeedbackClick(TObject *Sender);
	void __fastcall glCategoryResize(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall CeilClick(TObject *Sender);
	void __fastcall lvProductItemClick(TObject * const Sender, TListViewItem * const AItem);


private: // User declarations
	void ReloadCategoryList();

public: // User declarations
	__fastcall Tfm(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE Tfm *fm;
// ---------------------------------------------------------------------------
#endif
