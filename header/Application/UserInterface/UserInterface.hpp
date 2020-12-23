#pragma once

#include "Application/UserInterface/PageManager.hpp"

#include <TGUI/TGUI.hpp>

#include <memory>

class UserInterface
{
public:
	UserInterface(tgui::Group::Ptr container);

	~UserInterface();
private:
	tgui::Group::Ptr container;
	PageManager* pageManager;
};