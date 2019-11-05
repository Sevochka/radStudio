//---------------------------------------------------------------------------

#ifndef fmuH
#define fmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class Tfm : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar1;
	TButton *buRestart;
	TButton *buAbout;
	TGridPanelLayout *GridPanelLayout1;
	TRectangle *Rectangle1;
	TBrushObject *Brush1;
	TBrushObject *Brush2;
	TLabel *laCorrect;
	TRectangle *Rectangle2;
	TLabel *laWrong;
	TGridPanelLayout *GridPanelLayout2;
	TButton *buYes;
	TButton *buNo;
	TLabel *laCode;
	TLabel *laQuestion;
	TGridPanelLayout *GridPanelLayout3;
	TButton *buEasy;
	TButton *buNormal;
	TButton *buHard;
	TButton *buChallenging;
	void __fastcall buYesClick(TObject *Sender);
	void __fastcall buNoClick(TObject *Sender);
	void __fastcall buRestartClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall buAboutClick(TObject *Sender);
	void __fastcall buEasyClick(TObject *Sender);
	void __fastcall buNormalClick(TObject *Sender);
	void __fastcall buHardClick(TObject *Sender);
	void __fastcall buChallengingClick(TObject *Sender);
private:	// User declarations
	int FCountCorrect;
	int FCountWrong;
	bool FAnswerCorrect;
	void DoReset();
	void DoContinue();
	void DoAnswer(bool aValue);
    int RandomValue;
public:		// User declarations
	__fastcall Tfm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfm *fm;
//---------------------------------------------------------------------------
#endif
