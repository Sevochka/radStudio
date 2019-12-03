//---------------------------------------------------------------------------

#ifndef fmuH
#define fmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.ImgList.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <System.ImageList.hpp>
//---------------------------------------------------------------------------
class TTag : public TForm
{
__published:	// IDE-managed Components
	TTabControl *tc;
	TTabItem *tiPlay;
	TGridPanelLayout *GridPanelLayout1;
	TImageList *ImageList;
	TLayout *Layout1;
	TLayout *Layout2;
	TLayout *Layout4;
	TLayout *Layout3;
	TLayout *Layout5;
	TLayout *Layout6;
	TLayout *Layout7;
	TLayout *Layout8;
	TLayout *Layout9;
	TGlyph *Glyph1;
	TGlyph *Glyph2;
	TGlyph *Glyph3;
	TGlyph *Glyph4;
	TGlyph *Glyph5;
	TGlyph *Glyph6;
	TGlyph *Glyph7;
	TGlyph *Glyph8;
	TGlyph *Glyph9;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Layout1Click(TObject *Sender);
private:	// User declarations
	TGlyph *m[9];
public:		// User declarations
	__fastcall TTag(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTag *Tag;
//---------------------------------------------------------------------------
#endif
