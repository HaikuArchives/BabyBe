/*
	
	BabyBeWindow.h
	
*/
/*
	Originally written by Ben Loftis.
	This source code is available freely for any use.
	If you use this source extensively in your project, I humbly
	    request that you credit me in your program.
*/

#ifndef BABY_BE_WINDOW_H
#define BABY_BE_WINDOW_H

#include <Window.h>

// BabyBeWindow class
class BabyBeWindow : public BWindow  
{
public:
				BabyBeWindow(BRect frame);
virtual	bool	QuitRequested();
};

#endif
