#pragma once


namespace GSM
{
	class BaseLevel;

	class GameStateManager
	{
		//Singleton = Only 1 object
		// 
		// Prevent others creating me
	private:
		GameStateManager();

		//Remove the compiler defined Copy Constructor and Asignment operator
		GameStateManager(const GameStateManager& other) = delete;

		const GameStateManager& operator= (const GameStateManager& other) = delete;

		// Prevent others destroying me
		~GameStateManager();

		// Pointer to the exisiting Singleton can be accesed without an obj and from me only
		static GameStateManager* ptr;
		
		
		// Functions that anyone can access to :
	public:
		//		GetSingleton
		static GameStateManager* GetGSMPtr();
		//		DeleteSingleton
		static void DeleteGSM();
		
		///////////////////////////////
		// 
	private:
		//Have a level
		BaseLevel* previousLevel;
		BaseLevel* currentLevel;

	public:
		//Functions to call Init, Update, Exit
		void Init();
		void Update();
		void Exit();
		//Function to change level
		void ChangeLevel(BaseLevel* newLvl);
		
		bool ShouldExit();
		//Functions to quit...
		//Functions to restart...
		//...
	};
}