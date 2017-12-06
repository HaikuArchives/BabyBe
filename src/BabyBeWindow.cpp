/*

	BabyBeWindow.cpp
	
*/
/*
	Originally written by Ben Loftis.
	This source code is available freely for any use.
	If you use this source extensively in your project, I humbly
	    request that you credit me in your program.
*/

#include <Application.h>
#include "BabyBeWindow.h"
#include "BabyBeView.h"

BabyBeWindow::BabyBeWindow(BRect frame)
				: BWindow(frame, "BabyBe v2.2", B_BORDERED_WINDOW, B_NOT_MOVABLE)
{
	BabyBeView *myView = new BabyBeView( Bounds(), NULL );
	
	// add view to window
	AddChild(myView);
    myView->MakeFocus(true);
}

bool BabyBeWindow::QuitRequested()
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return(true);
}