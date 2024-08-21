// ---------------------------------------------------------------------------
// includes

#include <crtdbg.h> // To check for memory leaks
#include "AEEngine.h"
#include "GameStateManager.hpp"
#include "MainMenu.hpp"
#include "GoalLevel.hpp"
#include "ResourceManager.h"
#include <string>
#include "Registry.h"
#include "BaseRTTI.h"


// ---------------------------------------------------------------------------
// main

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// solve memory leaks
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(548);
	// Initialization of your own variables go here

	// Using custom window procedure
	AESysInit(hInstance, nCmdShow, 1600, 900, 1, 60, true, NULL);

	// Changing the window title
	AESysSetWindowTitle("Alpha Engine Program");

	GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
	

	// Test RTTI

	Registry* RTTIptr = Registry::GetPtr();

	//Find  the function, call the function and store that BaseRTTI*
	BaseRTTI* p = RTTIptr->FindAndCreate("TransformComp");

	//p->Load("AAA"); // return nullptr
	//delete p;

	//Test for each comp
	//Test INVALID name on the find

	//reset the system module;

	AEGfxSetBackgroundColor(0, 0, 0);

	// reset the system modules
	AESysReset();

	gsm->ChangeLevel(new Levels::MainLevel);
	// Game Loop
	while (gsm->ShouldExit() == false)
	{
		// Informing the system about the loop's start
		AESysFrameStart();

		// Your own update logic goes here
		gsm->Update();


		// Your own rendering logic goes here


		// Informing the system about the loop's end
		AESysFrameEnd();

		// check if forcing the application to quit
		if (AEInputCheckTriggered(AEVK_ESCAPE) || 0 == AESysDoesWindowExist())
			gsm->ChangeLevel(new Levels::GoalLevel);
	}

	// free the system
	gsm->DeleteGSM();
	//GameManager::Delete();
	RTTIptr->Delete();
	AESysExit();
}