//---------------------------------------------------------------------------

#ifndef dmuH
#define dmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.FB.hpp>
#include <FireDAC.Phys.FBDef.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.IBBase.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
//---------------------------------------------------------------------------
class Tdm : public TForm
{
__published:	// IDE-managed Components
	TFDConnection *FDConnection1;
	TFDQuery *quCategory;
	TFDQuery *quProducts;
	TFDStoredProc *spFeedbackIns;
	TFDGUIxWaitCursor *FDGUIxWaitCursor1;
	TFDPhysFBDriverLink *FDPhysFBDriverLink1;
	TIntegerField *quCategoryID;
	TWideStringField *quCategoryNAME;
	TIntegerField *quProductsID;
	TIntegerField *quProductsCATEGORY_ID;
	TWideStringField *quProductsNAME;
	TBlobField *quProductsIMAGE;
	TIntegerField *quProductsGRAM;
	TIntegerField *quProductsKCAL;
	TFloatField *quProductsPRICE;
	TWideStringField *quProductsNOTE;
	TFDQuery *quFeedback;
	TWideStringField *quFeedbackFIO;
	TWideStringField *quFeedbackPHONE;
	TWideStringField *quFeedbackEMAIL;
	TWideStringField *quFeedbackNOTE;
	TFDStoredProc *spAddToCart;
	TFDStoredProc *spBuy;
	TFDQuery *quOrder;
	TIntegerField *quOrderID;
	TIntegerField *quOrderORDER_ID;
	TIntegerField *quOrderPRODUCT_ID;
	TFloatField *quOrderPRODUCT_PRICE;
	TIntegerField *quOrderQUANTITY;
	TWideStringField *quOrderNAME;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FDConnection1AfterConnect(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tdm(TComponent* Owner);
    void FeedbackIns(UnicodeString aFIO, UnicodeString aPhone,
		UnicodeString aEmail, UnicodeString aNote);
	void BuyIns(UnicodeString aFIO, UnicodeString aPhone,
		UnicodeString aEmail, UnicodeString aAddress, UnicodeString aNote);
	void AddToCart(int aId, double aPrice, int aQu, UnicodeString aName);
};
//---------------------------------------------------------------------------
extern PACKAGE Tdm *dm;
//---------------------------------------------------------------------------
#endif
