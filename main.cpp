/* CSCI261 Final Project: finalProject
 *
 * Author: Espen Roth & Corbin Olds
 *
 * This program is a version of the well known game, PONG
 * but it includes a fundamental difference: up to 4 players can play at once
*/
#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"


int main() {





    ofAppGlutWindow window;
	  ofSetupOpenGL(&window, 600,600, OF_WINDOW);

	  ofRunApp(new testApp());

}
