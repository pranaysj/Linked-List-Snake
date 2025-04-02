#pragma once
#include "../header/Graphics/GraphicService.h"
#include "../header/Event/EventService.h"
#include "../header/UI/UIService.h"
#include "../header/Sound/SoundService.h"
#include "../header/Time/TimeService.h"
#include "../header/Level/LevelService.h"
#include "../header/Player/PlayerService.h"
#include "../header/Element/ElementService.h"
#include "../header/Food/FoodService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Event::EventService* event_service;
        Graphics::GraphicService* graphic_service;
        Sound::SoundService* sound_service;
        UI::UIService* ui_service;
        Time::TimeService* time_service;
        Level::LevelService* level_service;
        Player::PlayerService* player_service;
        Element::ElementService* element_service;
        Food::FoodService* food_service;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Event::EventService* getEventService();
        Graphics::GraphicService* getGraphicService();
        Sound::SoundService* getSoundService();
        UI::UIService* getUIService();
        Time::TimeService* getTimeService();
        Level::LevelService* getLevelService();
        Player::PlayerService* getPlayerService();
        Element::ElementService* getElementService();
        Food::FoodService* getFoodService();

        void deleteServiceLocator();
    };
}