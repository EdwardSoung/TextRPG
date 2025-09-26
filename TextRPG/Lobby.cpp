#include "Lobby.h"

void Lobby::ShowLobby()
{
	PrintGameTitle();
}

void Lobby::PrintGameTitle()
{
	std::string PlayerName = "";
	int SelectedMenu = 1;

	char InputKey = '0';

	while (true)
	{
		system("cls");
		printf(" #####    ###     #####  #     #   ###  \n");
		printf("#     #  #   #   #     # #     #  #   # \n");
		printf("#        #     # #       #     # #     #\n");
		printf("#  ###   ####### #       ####### #######\n");
		printf("#     #  #     # #       #     # #     #\n");
		printf("#     #  #     # #     # #     # #     #\n");
		printf(" #####   #     #  #####  #     # #     #\n");
		printf("\n");
		printf("      #     #  #####  ######  #       ###### \n");
		printf("      #     # #     # #     # #       #     #\n");
		printf("      #  #  # #     # #     # #       #     #\n");
		printf("      #  #  # #     # ######  #       #     #\n");
		printf("      #  #  # #     # #   #   #       #     #\n");
		printf("       # # #  #     # #    #  #       #     #\n");
		printf("        # #    #####  #     # ####### ###### \n");

		PrintMenu(SelectedMenu);

		printf("메뉴 선택[↑(w), ↓(s)] : ");

		std::string Line;
		std::getline(std::cin, Line);
		if (Line.empty()) {
			// 엔터만 눌림
			if (SelectedMenu == 1)
			{
				printf("캐릭터 이름을 입력하세요 : ");
				std::getline(std::cin, PlayerName);

				system("cls");
				break;
			}
			else
			{
				return;
			}
		}
		else
		{
			if ((Line[0] == 'w' || Line[0] == 'W') && SelectedMenu == 2)
			{
				SelectedMenu = 1;
			}
			else if (SelectedMenu == 1 && (Line[0] == 's' || Line[0] == 'S'))
			{
				SelectedMenu = 2;
			}
		}
	}
	GameManager::GetInstance().PlayNewGame(PlayerName);
}

void Lobby::PrintMenu(int InSelect)
{
	if (InSelect == 1)
	{
		printf("          ┌───────────────┐\n");
		printf("          │ 1. Start Game │\n");
		printf("          └───────────────┘\n");
		printf("            2. Exit Game\n");
		printf("\n");
	}
	else if(InSelect == 2)
	{
		printf("\n");
		printf("            1. Start Game\n");
		printf("          ┌───────────────┐\n");
		printf("          │ 2. Exit Game  │\n");
		printf("          └───────────────┘\n");
	}

}
