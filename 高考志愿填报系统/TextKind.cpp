#include <iostream>
#include <graphics.h>
#include < conio.h >
#include "UI.h"
using namespace std;
void TextKind(LOGFONT& title, LOGFONT& word, LOGFONT& acc) {
	
	gettextstyle(&title);
	title.lfHeight = 40;
	_tcscpy(title.lfFaceName, "¡• È");
	title.lfQuality = ANTIALIASED_QUALITY;
	gettextstyle(&word);
	word.lfHeight = 10;
	gettextstyle(&acc);
	acc.lfHeight = 30;
	acc.lfQuality = ANTIALIASED_QUALITY;
	_tcscpy(acc.lfFaceName, "¡• È");
	gettextstyle(&word);
	word.lfHeight = 10;
}
void ShowScoreKind(LOGFONT& sc) {
	gettextstyle(&sc);
	
}
//void 