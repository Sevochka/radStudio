//---------------------------------------------------------------------------

#ifndef fmuH
#define fmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Ani.hpp>
//---------------------------------------------------------------------------
class Tfm : public TForm
{
__published:	// IDE-managed Components
	TGridPanelLayout *GridPanelLayout2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TLayout *Layout1;
	TImage *Image1;
	TImage *Image2;
	TLayout *Layout2;
	TLabel *Label1;
	TImage *Image3;
	TFloatAnimation *FloatAnimation1;
	void __fastcall ButtonAllMouseEnter(TObject *Sender);
	void __fastcall ButtonAllMouseLeave(TObject *Sender);
	void __fastcall ImageAllMouseEnter(TObject *Sender);
	void __fastcall ImageAllMouseLeave(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tfm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfm *fm;
//---------------------------------------------------------------------------
#endif
