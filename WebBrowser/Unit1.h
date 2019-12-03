//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.WebBrowser.hpp>
//---------------------------------------------------------------------------
class Tfm : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar1;
	TEdit *edURL;
	TButton *buGo;
	TToolBar *ToolBar2;
	TButton *buForward;
	TButton *buBack;
	TButton *buStop;
	TButton *buAbout;
	TButton *buReload;
	TWebBrowser *wb;
	void __fastcall buGoClick(TObject *Sender);
	void __fastcall buBackClick(TObject *Sender);
	void __fastcall buForwardClick(TObject *Sender);
	void __fastcall buReloadClick(TObject *Sender);
	void __fastcall buStopClick(TObject *Sender);
	void __fastcall buAboutClick(TObject *Sender);
	void __fastcall edURLKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall wbDidFinishLoad(TObject *ASender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tfm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfm *fm;
//---------------------------------------------------------------------------
#endif
