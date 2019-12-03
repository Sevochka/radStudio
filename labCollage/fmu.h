//---------------------------------------------------------------------------

#ifndef fmuH
#define fmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.ImgList.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Colors.hpp>
//---------------------------------------------------------------------------
class Tfm : public TForm
{
__published:	// IDE-managed Components
	TToolBar *tbDefault;
	TButton *buNewImage;
	TButton *buClear;
	TButton *buNewRect;
	TGlyph *Glyph1;
	TSelection *Selection1;
	TLayout *ly;
	TSelection *Selection2;
	TGlyph *Glyph2;
	TSelection *Selection3;
	TRectangle *Rectangle1;
	TToolBar *tbOptions;
	TButton *biBringToFront;
	TButton *buSendToBack;
	TTrackBar *trRotation;
	TButton *buDel;
	TToolBar *tbImage;
	TButton *buImagePrev;
	TButton *buImageNext;
	TButton *buImageSelect;
	TButton *buImageRND;
	TToolBar *tbRect;
	TComboColorBox *ComboColorBox;
	TTrackBar *trRectRadious;
	TToolBar *tbText;
	TComboColorBox *ComboColorText;
	TSelection *Selection5;
	TLabel *Label1;
	TTrackBar *trTextSize;
	TButton *buNewLabel;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SelectionAllMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall biBringToFrontClick(TObject *Sender);
	void __fastcall buSendToBackClick(TObject *Sender);
	void __fastcall trRotationChange(TObject *Sender);
	void __fastcall buDelClick(TObject *Sender);
	void __fastcall buImagePrevClick(TObject *Sender);
	void __fastcall buImageNextClick(TObject *Sender);
	void __fastcall buImageSelectClick(TObject *Sender);
	void __fastcall buImageRNDClick(TObject *Sender);
	void __fastcall ComboColorBoxChange(TObject *Sender);
	void __fastcall trRectRadiousChange(TObject *Sender);
	void __fastcall buNewImageClick(TObject *Sender);
	void __fastcall buNewRectClick(TObject *Sender);
	void __fastcall buClearClick(TObject *Sender);
	void __fastcall ComboColorTextChange(TObject *Sender);
	void __fastcall trTextSizeChange(TObject *Sender);
	void __fastcall buNewLabelClick(TObject *Sender);
private:	// User declarations
	TSelection *FSel;
    void SelectionAll(TObject *Sender);
public:		// User declarations
	__fastcall Tfm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfm *fm;
//---------------------------------------------------------------------------
#endif
