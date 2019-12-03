//---------------------------------------------------------------------------

#ifndef fmuH
#define fmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
//---------------------------------------------------------------------------
class Tfm : public TForm
{
__published:	// IDE-managed Components
	TLayout *Layout1;
	TLabel *Label1;
	TButton *buAbout;
	TTabControl *tc;
	TTabItem *tMenu;
	TTabItem *TabItem2;
	TTabItem *TabItem3;
	TTabItem *TabItem4;
	TTabItem *tResult;
	TButton *buStart;
	TImage *Image1;
	TLabel *Label2;
	TButton *Button2;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TScrollBox *ScrollBox1;
	TScrollBox *ScrollBox2;
	TButton *Button1;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TLabel *Label3;
	TScrollBox *ScrollBox3;
	TButton *Button11;
	TButton *Button14;
	TButton *Button15;
	TLabel *Label4;
	TButton *buRestart;
	TMemo *me;
	TLabel *Ind;
	TProgressBar *pb;
	TTabItem *TabItem6;
	TScrollBox *ScrollBox4;
	TButton *Button3;
	TButton *Button7;
	TButton *Button12;
	TLabel *Label5;
	TTabItem *TabItem7;
	TScrollBox *ScrollBox5;
	TButton *Button13;
	TButton *Button16;
	TButton *Button17;
	TLabel *Label6;
	TLabel *laCorrect;
	TLabel *laWrong;
	TImage *imWrong;
	TImage *imCorrect;
	TTabItem *TabItem1;
	TScrollBox *ScrollBox6;
	TLabel *Label7;
	TGridPanelLayout *GridPanelLayout1;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TImage *Image5;
	TStyleBook *StyleBook1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall buStartClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall buRestartClick(TObject *Sender);
	void __fastcall tcChange(TObject *Sender);
private:	// User declarations
	int FCountCorrect;
    int FCountWrong;
public:		// User declarations
	__fastcall Tfm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfm *fm;
//---------------------------------------------------------------------------
#endif
