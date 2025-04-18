#pragma once
#include "../header/UI/MainMenu/MainMenuUIController.h"
#include "../header/UI/SplashScreen/SplashScreenUIController.h"
#include "../header/UI/Instructions/InstructionsScreenUIController.h"
#include "../header/UI/Credits/CreditsScreenUIController.h"
#include "../header/UI/LevelSelection/LevelSelectionUIController.h"
#include "../header/UI/Interface/IUIController.h"
#include "../header/UI/GameplayUI/GameplayUIController.h"
#include "../header/UI/LinkedListUI/LinkedListSelectionUIController.h"

namespace UI
{
	class UIService
	{
	private:
		SplashScreen::SplashScreenUIController* splash_screen_controller;
		MainMenu::MainMenuUIController* main_menu_controller;
		Instructions::InstructionsScreenUIController* instructions_screen_ui_controller;
		LevelSelection::LevelSelectionUIController* level_selection_ui_controller;
		Credits::CreditsScreenUIController* credits_screen_ui_controller;
		GameplayUI::GameplayUIController* gameplay_ui_controller;
		LinkedListUI::LinkedListSelectionUIController* linkedList_selection_ui_controller;

		void createControllers();
		void initializeControllers();
		Interface::IUIController* getCurrentUIController();
		void destroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showScreen();
	};
}