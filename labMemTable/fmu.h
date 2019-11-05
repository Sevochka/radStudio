//---------------------------------------------------------------------------

#ifndef fmuH
#define fmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.Grid.hpp>
#include <FireDAC.Stan.StorageBin.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <Fmx.Bind.Grid.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Types.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Data.Bind.Controls.hpp>
#include <Fmx.Bind.Navigator.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.StdCtrls.hpp>
#include <FireDAC.Stan.StorageJSON.hpp>
#include <System.IOUtils.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TFDMemTable *ta;
	TStringField *taFIO;
	TStringField *taTel;
	TIntegerField *taAge;
	TCurrencyField *taMoney;
	TGrid *Grid1;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TLinkGridToDataSource *LinkGridToDataSourceBindSourceDB1;
	TBindNavigator *BindNavigator1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TLinkControlToField *LinkControlToField1;
	TLinkControlToField *LinkControlToField2;
	TLinkControlToField *LinkControlToField3;
	TLinkControlToField *LinkControlToField4;
	TButton *buSave;
	TButton *buCancel;
	TEdit *edFilter;
	TButton *buFilterOn;
	TButton *Cancel;
	TEdit *edFileName;
	TButton *buSaveToFile;
	TButton *buLoadFromFile;
	TFDStanStorageJSONLink *FDStanStorageJSONLink1;
	TButton *buAddAge1;
	TButton *buAddAge100;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TButton *buLocate;
	TButton *buLookup;
	TEdit *edL;
	TButton *getSum;
	void __fastcall buSaveClick(TObject *Sender);
	void __fastcall buCancelClick(TObject *Sender);
	void __fastcall buFilterOnClick(TObject *Sender);
	void __fastcall CancelClick(TObject *Sender);
	void __fastcall buSaveToFileClick(TObject *Sender);
	void __fastcall buLoadFromFileClick(TObject *Sender);
	void __fastcall buAddAge1Click(TObject *Sender);
	void __fastcall buAddAge100Click(TObject *Sender);
	void __fastcall CheckBox1Change(TObject *Sender);
	void __fastcall CheckBox2Change(TObject *Sender);
	void __fastcall buLocateClick(TObject *Sender);
	void __fastcall buLookupClick(TObject *Sender);
	void __fastcall getSumClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
