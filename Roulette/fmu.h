//---------------------------------------------------------------------------

#ifndef fmuH
#define fmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.ImgList.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <System.ImageList.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class Tfm : public TForm
{
__published:	// IDE-managed Components
	TImageList *ImageList1;
	TButton *buBlack;
	TToolBar *ToolBar1;
	TButton *buAbout;
	TTabControl *tc;
	TLabel *Label1;
	TLabel *Label2;
	TTabItem *TabItem1;
	TTabItem *TabItem2;
	TTimer *tRoulette;
	TGridPanelLayout *GridPanelLayout2;
	TGridPanelLayout *GridPanelLayout1;
	TGlyph *g9;
	TGlyph *g8;
	TGlyph *g7;
	TGlyph *g6;
	TGlyph *g5;
	TGlyph *g4;
	TGlyph *g3;
	TGlyph *g2;
	TGlyph *g1;
	TButton *buZero;
	TImage *Image1;
	TImage *Image11;
	TImage *Image14;
	TImage *Image24;
	TGridPanelLayout *GridPanelLayout3;
	TLabel *laCaptionHalf2;
	TButton *buRed;
	TImageList *ImageList2;
	TGlyph *gs1;
	TGlyph *gs2;
	TGlyph *gs3;
	TGlyph *gs4;
	TGlyph *gs5;
	TGlyph *gs6;
	TGlyph *gs7;
	TGlyph *gs8;
	TGlyph *gs9;
	TGlyph *gs10;
	TGlyph *gs11;
	TGlyph *gs12;
	TGlyph *gs13;
	TGlyph *gs14;
	TGlyph *gs15;
	TGlyph *gs16;
	TGlyph *gs17;
	TGlyph *gs18;
	TGlyph *gs19;
	TTimer *tSmile;
	TLabel *laBalance;
	TGridPanelLayout *GridPanelLayout4;
	TButton *bu500;
	TButton *buSettings;
	TLayout *Layout7;
	TButton *bu25;
	TButton *bu50;
	TButton *bu100;
	TLabel *laBet;
	TEdit *edBet;
	TLabel *laCaptionHalf1;
	TGlyph *Glyph1;
	TButton *bu200;
	TLabel *laMinus;
	TFloatAnimation *animMinusPosition;
	TFloatAnimation *animMinusOpasity;
	TLabel *laPlus;
	TFloatAnimation *animPlusPosition;
	TFloatAnimation *animPlusOpasity;
	TTimer *tLoading;
	TStyleBook *sbDark;
	TStyleBook *sbLight;
	TButton *buTheme;
	TButton *buPrevious;
	TGridPanelLayout *GridPanelLayout5;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TGridPanelLayout *GridPanelLayout6;
	TLabel *Label7;
	TLabel *Label9;
	TLabel *Label8;
	TLabel *Label10;
	TLabel *Label11;
	TGridPanelLayout *GridPanelLayout7;
	TLabel *laBlackChance;
	TTrackBar *tbBlackChance;
	TLabel *laRedChance;
	TGridPanelLayout *GridPanelLayout8;
	TLabel *laBRChance;
	TTrackBar *tbZeroChance;
	TLabel *laZeroChance;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall tRouletteTimer(TObject *Sender);
	void __fastcall tSmileTimer(TObject *Sender);
	void __fastcall buttonAllMouseEnter(TObject *Sender);
	void __fastcall buttonAllMouseLeave(TObject *Sender);
	void __fastcall buAboutClick(TObject *Sender);
	void __fastcall edBetChangeTracking(TObject *Sender);
	void __fastcall buttonsBetClick(TObject *Sender);
	void __fastcall buttonsStartSpinning(TObject *Sender);
	void __fastcall tLoadingTimer(TObject *Sender);
	void __fastcall buSettingsClick(TObject *Sender);
	void __fastcall buThemeClick(TObject *Sender);
	void __fastcall buPreviousClick(TObject *Sender);
	void __fastcall tbBlackChanceChange(TObject *Sender);
	void __fastcall tbZeroChanceChange(TObject *Sender);
private:	// User declarations
	TDateTime FTimeStart;
	int x1;
	int x2;
	int chosenColor;
	int isColor;
	void DetermineWinColor(int colorNum);
	int balance;
	void ChangeImg(int imgValue);
	int bet;
	void MakeStartButtonsEnabled(bool flag);
	bool isRouletteSpinning;
	void MakeBetButtonsEnabled(bool flag);
	int spinCounter;
	int zeroChance;
	int blackChance;
	int redChance;
	bool flagRed;
    bool flagBlack;
public:		// User declarations
	__fastcall Tfm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfm *fm;
//---------------------------------------------------------------------------
#endif
