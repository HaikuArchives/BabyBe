/*
	
	BabyBe.h

*/
/*
	Originally written by Ben Loftis.
	This source code is available freely for any use.
	If you use this source extensively in your project, I humbly
	    request that you credit me in your program.
*/

#ifndef BABY_BE_H
#define BABY_BE_H

#include <Application.h>

//DropApplication class
class BabyBeApplication : public BApplication 
{
public:
				BabyBeApplication();
private:
	BWindow		*myWindow;
    void        AboutRequested(void);
};

#endif //BABY_BE_H
