#pragma once
#include"../header//UI//Interface/IUIController.h"
#include"../header/UI/UIElement/ImageView.h"
#include"../header/UI/UIElement/ButtonView.h"

namespace UI
{
	namespace LevelSelection
	{
		using namespace UIElement;

		class LevelSelectionUIController : public Interface::IUIController
		{
		private:

			const float button_width = 400.f;
			const float button_height = 140.f;

			const float level_one_button_y_position = 500.f;
			const float level_two_button_y_position = 700.f;
			const float menu_button_y_position = 900.f;

			const float background_alpha = 85.f;

			ImageView* background_image;

			ButtonView* level_one_button;
			ButtonView* level_two_button;
			ButtonView* menu_button;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeButtons();
			void registerButtonCallback();

			void singleLinkedListButtonCallback();
			void doubleLinkedListButtonCallback();
			void menuButtonCallback();

			void destory();

		public:

			LevelSelectionUIController();
			~LevelSelectionUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}