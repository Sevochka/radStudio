//---------------------------------------------------------------------------

#ifndef fmuH
#define fmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
#include "uUtils.h"
//---------------------------------------------------------------------------
class Tfm : public TForm
{
__published:	// IDE-managed Components
	TTabControl *tc;
	TTabItem *tiMenu;
	TTabItem *tiLevel;
	TTabItem *tiOptions;
	TTabItem *tiAbout;
	TTabItem *tiPlay;
	TToolBar *ToolBar1;
	TGridPanelLayout *GridPanelLayout1;
	TButton *buAnswer1;
	TButton *buAnswer2;
	TButton *buAnswer3;
	TButton *buAnswer4;
	TButton *buAnswer5;
	TButton *buAnswer6;
	TLabel *laQuestion;
	TButton *buReset;
	TLabel *laTime;
	TLayout *Layout1;
	TGridPanelLayout *GridPanelLayout2;
	TRectangle *Rectangle1;
	TRectangle *Rectangle2;
	TRectangle *Rectangle3;
	TRectangle *Rectangle4;
	TRectangle *Rectangle5;
	TRectangle *Rectangle6;
	TRectangle *Rectangle7;
	TRectangle *Rectangle8;
	TRectangle *Rectangle9;
	TRectangle *Rectangle10;
	TRectangle *Rectangle11;
	TRectangle *Rectangle12;
	TRectangle *Rectangle13;
	TRectangle *Rectangle14;
	TRectangle *Rectangle15;
	TRectangle *Rectangle16;
	TRectangle *Rectangle17;
	TRectangle *Rectangle18;
	TRectangle *Rectangle19;
	TRectangle *Rectangle20;
	TRectangle *Rectangle21;
	TRectangle *Rectangle22;
	TRectangle *Rectangle23;
	TRectangle *Rectangle24;
	TRectangle *Rectangle25;
	TTimer *tmPlay;
	TTabItem *tiLose;
	TLabel *Label1;
	TButton *buGoToPlay;
	TLabel *laCorrect;
	TLayout *Layout2;
	TLabel *laIncorrect;
	TGridPanelLayout *GridPanelLayout3;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TImage *Image1;
	TGridPanelLayout *GridPanelLayout4;
	TButton *Button5;
	TGridPanelLayout *GridPanelLayout7;
	TTrackBar *tbBlackChance;
	TLabel *laDif;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall tmPlayTimer(TObject *Sender);
	void __fastcall buAnswerAllClick(TObject *Sender);
	void __fastcall buResetClick(TObject *Sender);
	void __fastcall buGoToPlayClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall tbBlackChanceChange(TObject *Sender);
private:	// User declarations
	int FCountCorrect;
	int FCountWrong;
	int FNumberCorrect;
	double FTimeValue;
	TList *FListBox;
	TList *FListAnswer;
	void DoReset();
	void DoContinue();
	void DoAnswer(int aValue);
	void DoFinish();
public:		// User declarations
	__fastcall Tfm(TComponent* Owner);
};

const int cMaxBox = 25;
const int cMaxAnswer = 6;
const int cMinPossible = 4;
const int cMaxPossible = 14;
//---------------------------------------------------------------------------
extern PACKAGE Tfm *fm;
//---------------------------------------------------------------------------
#endif
