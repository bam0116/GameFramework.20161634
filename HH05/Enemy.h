#pragma once
#include <iostream>
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	void init();
	void update();
};