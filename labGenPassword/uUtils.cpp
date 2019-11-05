//---------------------------------------------------------------------------

#pragma hdrstop

#include "uUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

UnicodeString RandomStr(int aLenght, bool aLower, bool aUpper, bool aNumbr, bool aSpecl) {
	const char *c1 = "abcdefghijklmnopqrstuvwxyz";
	const char *c2 = "0123456789";
	const char *c3 = "[]{}<>,.;:-+#";

	UnicodeString x = ""; // list of symbols
	UnicodeString xResult = "";
	//Creating list of symbols with the params of functions
	if (aLower) x += c1;
	if (aUpper) x += UpperCase(c1);
	if (aNumbr) x += c2;
	if (aSpecl) x += c3;

	//If x is empty then we turn on lower case symbols
	if (x.IsEmpty()) x = c1;

	while (xResult.Length() < aLenght) {
		xResult += x.SubString(Random(x.Length() + 1), 1);
	}
	return xResult;

}