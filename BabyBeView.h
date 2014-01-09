/*
	
	BabyBe.h
	
*/
/*
	Originally written by Ben Loftis.
	This source code is available freely for any use.
	If you use this source extensively in your project, I humbly
	    request that you credit me in your program.
*/

#ifndef BABY_BE_VIEW_H
#define BABY_BE_VIEW_H

#include <View.h>
#include <SimpleGameSound.h>

static const int   NUM_COLORS = 10;  
static const int   MAX_SOUNDS = 100;  

class BabyBeView : public BView 
{
public:
				   BabyBeView(BRect frame, const char *name); 
				   ~BabyBeView(void);
private:
void               KeyDown(const char *bytes, int32 numBytes);
void 	           MouseDown(BPoint point);
void               ResetView();
int                ItemCount;

BSimpleGameSound   *Sound[MAX_SOUNDS];

};

#endif //BABY_BE_VIEW_H
