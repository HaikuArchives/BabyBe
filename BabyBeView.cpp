/*
	
	BabyBeView.cpp
	
*/
/*
	Originally written by Ben Loftis.
	This source code is available freely for any use.
	If you use this source extensively in your project, I humbly
	    request that you credit me in your program.
*/

#include "BabyBeView.h"
#include <Message.h>
#include <stdlib.h>
#include <Region.h>
#include <game/GameSoundDefs.h>
#include <Alert.h>
#include <Resources.h>
#include <Roster.h>
#include <Application.h>
#include <ctype.h>

//Choose some colors that don't clash too much
const rgb_color GoodColors[NUM_COLORS] = {{255,255,255},
                                {255,0,0},
                                {0,0,255},
                                {255,120,255},
                                {255,24,255},
                                {0,0,125},
                                {125,32,125},
                                {255,0,125},
                                {125,0,255},
                                {50,250,50}};

int NumSounds;

//Constructor for the BView
BabyBeView::BabyBeView(BRect rect, const char *name)
	   	   : BView(rect, name, B_FOLLOW_ALL_SIDES, 0)
{
 	srand(5);

    SetViewColor(0,0,0);
    
    //Set the text font for the view
    BFont font;
    GetFont(&font);
    font.SetFlags(B_DISABLE_ANTIALIASING);
    font.SetFace(B_BOLD_FACE);
    SetFont(&font);
	
	//set the format of the raw data in the resource file
	gs_audio_format format;
	format.frame_rate = 22050;
	format.channel_count = 1;
	format.format = 0x11; //8bit unsigned ..can't get the defined constant to work here
	format.byte_order = 1;
	format.buffer_size = 0;
	
    //create a resource object from the executable file - easy way
	BResources *res = be_app->AppResources();
	
    //we need a string to store the resource names, even though we won't use them
    const char *Name;
    size_t Size;
    
	//load the sound data from the BResource and create BSimpleGameSound objects
	bool OK;
	NumSounds = 0;
	
	OK = true;
	while (OK)
	if (res->GetResourceInfo(B_RAW_TYPE, NumSounds, &Name, &Size) & (NumSounds < MAX_SOUNDS))
	{
	    const void *Data = res->LoadResource(B_RAW_TYPE, NumSounds, &Size);
		Sound[NumSounds] = new BSimpleGameSound(Data, Size, &format);
		NumSounds++;
	}
	else
	  OK = false;
	
	//check to see if the last sound object was initialized
	int result = Sound[NumSounds - 1]->InitCheck();
	if (result != B_OK)
	   (new BAlert("", "Problem starting sound device", "OK"))->Go();
	   
	ItemCount = 21;
	
}

//reset the view so it doesn't get too busy
void BabyBeView::ResetView()
{
	ItemCount = 0;
    SetHighColor(0,0,0);
	FillRegion(new BRegion(Bounds()));
    SetHighColor(255,255,255);
    BPoint point(10, 12);
    SetFontSize(12);
    DrawString ("Press Alt-Q (or Ctl-Q) to quit", point);
}

//if a key is pressed, draw the character at a random point, color, size
void BabyBeView::KeyDown(const char *bytes, int32 numBytes)
{

   if (ItemCount++ > 20)
     ResetView();
      
   SetFontSize(50 + rand() % 400);
 
   SetHighColor(GoodColors[rand() % NUM_COLORS]);
   
   BPoint point(rand() % Bounds().IntegerWidth(), rand() % Bounds().IntegerHeight());
   
   DrawChar(toupper(bytes[0]), point);

   //NOTE: modifier keys can result in negative values, which are bad
   Sound[abs(bytes[0] % NumSounds)]->StartPlaying();
}


//if the mouse is clicked, draw a random ellipse at that point
void BabyBeView::MouseDown(BPoint point)
{
   if (ItemCount++ > 20)
     ResetView();
      
   SetHighColor(GoodColors[rand() % NUM_COLORS]);
   
   FillEllipse(point, rand() % 400, rand() % 400);

   Sound[rand() % NumSounds]->StartPlaying();
}

BabyBeView::~BabyBeView(void)
{
   //clean up the global BSimpleGameSound objects 
   for (int i = 0; i < NumSounds; i++)
      delete(Sound[i]);
}