//---------------------------------------------------------------------------

#pragma hdrstop

#include "uUtils.h"
//---------------------------------------------------------------------------
 int* RandomArrayUnique(int aMax, int aCount)
{
	int *xResult = new int[aCount];
	TList__1<int> *xTemp = new TList__1<int>;
	xTemp->Capacity = aCount;
	try {
	   for (int i = 0; i < aCount; i++) {
		int x = Random(aMax);

	   while (xTemp->IndexOf(x) != -1){
		x++;
		if (x >= aMax) {
			x = 0;
		}
		xTemp->Add(x);
		xResult[i] = x;
		}
	   }
	}
	__finally {
		delete xTemp;
	}
	return xResult;
}

#pragma package(smart_init)


