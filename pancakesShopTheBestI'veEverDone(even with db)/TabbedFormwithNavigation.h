//---------------------------------------------------------------------------

#ifndef TabbedFormwithNavigationH
#define TabbedFormwithNavigationH
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
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
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
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Edit.hpp>
#include <FMX.DateTimeCtrls.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
//---------------------------------------------------------------------------
class TTabbedwithNavigationForm : public TForm
{
__published:	// IDE-managed Components
	TTabControl *TabControl1;
	TTabItem *tbMenu;
	TTabControl *TabControl2;
	TTabItem *TabItem5;
	TToolBar *ToolBar1;
	TLabel *lblTitle1;
	TTabItem *tbFeedback;
	TToolBar *ToolBar3;
	TLabel *laFeedback;
	TTabItem *tbProducts;
	TToolBar *ToolBar4;
	TLabel *lblTitle4;
	TTabItem *tbItem;
	TToolBar *ToolBar5;
	TLabel *lblTitle5;
	TActionList *ActionList1;
	TNextTabAction *NextTabAction;
	TPreviousTabAction *PreviousTabAction;
	TGestureManager *GestureManager1;
	TImage *Image1;
	TButton *buPancakes;
	TGridPanelLayout *GridPanelLayout1;
	TStyleBook *sbDark;
	TButton *buQuiz;
	TButton *buBag;
	TButton *buFeedback;
	TButton *buDelivery;
	TButton *buTheme;
	TButton *buContacts;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TStyleBook *sbLight;
	TListView *lvProducts;
	TBindSourceDB *BindSourceDB2;
	TLinkListControlToField *LinkListControlToField2;
	TLabel *laPanChanged;
	TGridPanelLayout *GridPanelLayout2;
	TLabel *laGram;
	TLabel *laG;
	TLabel *laKcal;
	TImage *imAppear;
	TGridPanelLayout *GridPanelLayout3;
	TText *Text1;
	TLinkPropertyToField *LinkPropertyToFieldText;
	TLinkPropertyToField *LinkPropertyToFieldBitmap;
	TLinkPropertyToField *LinkPropertyToFieldText2;
	TLinkPropertyToField *LinkPropertyToFieldText3;
	TLabel *laK;
	TLabel *laPrice;
	TLabel *laP;
	TLinkPropertyToField *LinkPropertyToFieldText4;
	TLinkPropertyToField *LinkPropertyToFieldText5;
	TButton *buBagAdd;
	TButton *Button1;
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
	TTabItem *tbCart;
	TToolBar *ToolBar6;
	TLabel *Label1;
	TGridPanelLayout *GridPanelLayout4;
	TButton *Button2;
	TListView *ListView1;
	TLabel *Label2;
	TLinkPropertyToField *LinkPropertyToFieldText6;
	TTabItem *tbTerms;
	TButton *buBackFeedback;
	TButton *buBackProduct;
	TButton *buBackItem;
	TToolBar *ToolBar7;
	TLabel *Label7;
	TButton *buBackTerms;
	TMemo *Memo1;
	TTabItem *tbFeedbackList;
	TButton *buFeed;
	TToolBar *ToolBar8;
	TLabel *Label8;
	TButton *Button4;
	TListView *ListView2;
	TBindSourceDB *BindSourceDB3;
	TLinkListControlToField *LinkListControlToField1;
	TTabItem *tbQuiz;
	TToolBar *ToolBar9;
	TLabel *Label9;
	TButton *Button5;
	TTabItem *tbBuy;
	TToolBar *ToolBar10;
	TLabel *Label10;
	TButton *Button6;
	TScrollBox *ScrollBox2;
	TLabel *Label11;
	TEdit *edFIO2;
	TLabel *Label12;
	TEdit *edPhone2;
	TLabel *Label13;
	TEdit *edEmail;
	TMemo *edAddress;
	TLabel *Label15;
	TLabel *Label14;
	TDateEdit *edDate;
	TTimeEdit *edTime;
	TLabel *Label16;
	TLabel *Label17;
	TMemo *edNote;
	TButton *buBuy;
	TImageList *ImageList1;
	TGlyph *Glyph1;
	TGridPanelLayout *GridPanelLayout5;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TBindSourceDB *BindSourceDB4;
	TLinkFillControlToField *LinkFillControlToField1;
	TTabItem *tbContacts;
	TLabel *Label18;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall TabControl1Gesture(TObject *Sender, const TGestureEventInfo &EventInfo,
          bool &Handled);
	void __fastcall buPancakesClick(TObject *Sender);
	void __fastcall lvCategoryItemClick(TObject * const Sender, TListViewItem * const AItem);
	void __fastcall lvProductsItemClick(TObject * const Sender, TListViewItem * const AItem);
	void __fastcall buThemeClick(TObject *Sender);
	void __fastcall buSendFeedbackClick(TObject *Sender);
	void __fastcall buFeedbackClick(TObject *Sender);
	void __fastcall buBackFeedbackClick(TObject *Sender);
	void __fastcall buBackItemClick(TObject *Sender);
	void __fastcall buContactsClick(TObject *Sender);
	void __fastcall buFeedClick(TObject *Sender);
	void __fastcall buBagAddClick(TObject *Sender);
	void __fastcall buDeliveryClick(TObject *Sender);
	void __fastcall buBuyClick(TObject *Sender);
	void __fastcall ButtonAllClick(TObject *Sender);
	void __fastcall buQuizClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall buBagClick(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TTabbedwithNavigationForm(TComponent* Owner);
    int counter;
};
//---------------------------------------------------------------------------
extern PACKAGE TTabbedwithNavigationForm *TabbedwithNavigationForm;
//---------------------------------------------------------------------------
#endif
