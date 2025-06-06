#include "../header/UI/UIService.h"
#include "../header/Main/GameService.h"
#include "../header/UI/UIElement/TextView.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace SplashScreen;
	using namespace Instructions;
	using namespace Credits;
	using namespace UIElement;
	using namespace LevelSelection;
	using namespace Interface;
	using namespace GameplayUI;
	using namespace LinkedListUI;

	UIService::UIService()
	{
		splash_screen_controller = nullptr;
		main_menu_controller = nullptr;
		instructions_screen_ui_controller = nullptr;
		level_selection_ui_controller = nullptr;
		credits_screen_ui_controller = nullptr;
		gameplay_ui_controller = nullptr;
		linkedList_selection_ui_controller = nullptr;

		createControllers();
	}

	void UIService::createControllers()
	{
		splash_screen_controller = new SplashScreenUIController();
		main_menu_controller = new MainMenuUIController();
		instructions_screen_ui_controller = new InstructionsScreenUIController();
		credits_screen_ui_controller = new CreditsScreenUIController();
		level_selection_ui_controller = new LevelSelectionUIController();
		gameplay_ui_controller = new GameplayUIController();
		linkedList_selection_ui_controller = new LinkedListSelectionUIController();

	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->update();
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->render();
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->show();
	}

	void UIService::initializeControllers()
	{
		splash_screen_controller->initialize();
		main_menu_controller->initialize();
		instructions_screen_ui_controller->initialize();
		credits_screen_ui_controller->initialize();
		level_selection_ui_controller->initialize();
		gameplay_ui_controller->initialize();
		linkedList_selection_ui_controller->initialize();
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splash_screen_controller;

		case GameState::MAIN_MENU:
			return main_menu_controller;

		case GameState::LEVEL_SELECTION:
			return level_selection_ui_controller;

		case GameState::INSTRUCTIONS:
			return instructions_screen_ui_controller;

		case GameState::CREDITS:
			return credits_screen_ui_controller;

		case GameState::GAMEPLAY:
			return gameplay_ui_controller;

		case GameState::LINKED_LIST_SELECTION:
			return linkedList_selection_ui_controller;

		default:
			return nullptr;
		}
	}

	void UIService::destroy()
	{
		delete(splash_screen_controller);
		delete(main_menu_controller);
		delete(instructions_screen_ui_controller);
		delete(credits_screen_ui_controller);
		delete(level_selection_ui_controller);
		delete(gameplay_ui_controller);
		delete(linkedList_selection_ui_controller);
	}
}