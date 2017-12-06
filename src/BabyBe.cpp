/*
	
	BabyBe.cpp
	
*/
/*
	Originally written by Ben Loftis.
	This source code is available freely for any use.
	If you use this source extensively in your project, I humbly
	    request that you credit me in your program.
*/


#include "BabyBeWindow.h"
#include "BabyBe.h"
#include <Entry.h>
#include <Window.h>
#include <Screen.h>
#include <View.h>
#include <Alert.h>

int main(int, char**)
{	
	// Create an application instance
	BabyBeApplication myApplication;
	
	// Run the application looper
	myApplication.Run();
	
	return(0);
}

// KeyApplication constructor
BabyBeApplication::BabyBeApplication()
		  		  : BApplication("application/x-vnd.Be-BTL.BabyBe")
{
	BScreen	*screen = new BScreen();
	myWindow = new BabyBeWindow(screen->Frame());
	delete(screen);
	myWindow->Show();
}

void BabyBeApplication::AboutRequested(void)
{
	(new BAlert("", "BabyBe v2.2 by Ben Loftis", "Cool"))->Go();
}
