// ---------------------------------------------------------------------------

#ifndef dmuH
#define dmuH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
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

// ---------------------------------------------------------------------------
class Tdm : public TDataModule {
__published: // IDE-managed Components
	TFDConnection *FDConnection1;
	TFDGUIxWaitCursor *FDGUIxWaitCursor1;
	TFDPhysFBDriverLink *FDPhysFBDriverLink1;
	TFDStoredProc *spFeedbackIns;
	TFDQuery *quCategory;
	TIntegerField *quCategoryID;
	TWideStringField *quCategoryNAME;
	TBlobField *quCategoryIMAGE;
	TFDQuery *quProduct;
	TIntegerField *quProductID;
	TIntegerField *quProductCATEGORY_ID;
	TWideStringField *quProductNAME;
	TFloatField *quProductPRICE;
	TWideStringField *quProductNOTE;
	TBlobField *quProductIMAGE;

private: // User declarations

public: // User declarations
	__fastcall Tdm(TComponent* Owner);
	void FeedbackIns(UnicodeString aFIO, UnicodeString aPhone,
		UnicodeString aEmail, UnicodeString aNote);
};
// ---------------------------------------------------------------------------
extern PACKAGE Tdm *dm;
// ---------------------------------------------------------------------------
#endif
