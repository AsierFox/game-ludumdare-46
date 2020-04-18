#pragma once

#include "../../ui/BaseUI.h"

class BatteryLifeUI : public BaseUI
{
public:

	virtual void update() override;
	virtual void draw() override;
	virtual void dispose() override;
};
