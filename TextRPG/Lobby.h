#pragma once
#include <cstdio>
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include "GameManager.h"
class Lobby
{
public:
	void ShowLobby();
private:
	void PrintGameTitle();
	void PrintMenu(int InSelect);
};

