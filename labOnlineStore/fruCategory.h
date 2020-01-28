//---------------------------------------------------------------------------

#ifndef fruCategoryH
#define fruCategoryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TfrCategory : public TFrame
{
__published:	// IDE-managed Components
	TLabel *la;
	TImage *im;
private:	// User declarations
public:		// User declarations
	__fastcall TfrCategory(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrCategory *frCategory;
//---------------------------------------------------------------------------
#endif
