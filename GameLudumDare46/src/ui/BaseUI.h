#pragma once

#include "../physics/Vector2D.h"

class BaseUI
{
protected:

	Vector2D m_pos;

public:

	BaseUI();
	BaseUI(int x, int y);

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void dispose() = 0;
};
