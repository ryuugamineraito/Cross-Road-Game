#include "CGame.h"
int randtime = 4;
void textcolor(int x)
{
	HANDLE color;
	color = GetStdHandle

	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void ClearScreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle

	(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void createTitle()
{
	textcolor(12);
	wcout << endl << endl << endl;
	wcout <<"\t"<< "        _________ __   __    ________ ________ ________     __   __    ________ ________     __" << endl;
	wcout << "\t" << "       / _______// /__/ /   / ____  // ______// ______/    / /__/ /   / ____  // ____  /    / /" << endl;
	wcout << "\t" << "      / /       / _____/   / /   / // /_____ / /_____     / _____/   / /   / // /___/ /____/ /" << endl;
	wcout << "\t" << "     / /       / /\\ \\     / /   / //_____  //_____  /    / /\\ \\     / /   / // ____  // __  /" << endl;
	wcout << "\t" << "    / /______ / /  \\ \\   / /___/ /______/ /______/ /    / /  \\ \\   / /___/ // /   / // /_/ /" << endl;
	wcout << "\t" << "   /________//_/    \\ \\ /_______//_______//_______/    /_/    \\ \\ /_______//_/   /_//_____/" << endl << endl << endl << endl;
	//menu
	
	
}

//above is for graphic
CGame::CGame()//need some arguement here for 
{
	lv = 0;
	CVehicle *tmp1;
	CAnimal *tmp2;
	int x;
	srand(time(NULL));
	chrono.toggle();
	cn = new CPeople;
	for (int i = 0; i < 20; i += 2)//10 element each class
	{
		x = std::rand() % 4+1;
		tmp1 = new CTruck(5 * x);
		vehicles.push_back(tmp1);
		x = std::rand() % 4+1;

		tmp1 = new CCar(6 * x);
		vehicles.push_back(tmp1);
		x = std::rand() %4+1;

		tmp2 = new CBird(6 * x);
		animals.push_back(tmp2);
		x = std::rand() %4+1;

		tmp2 = new CDinosaur(5 * x);
		animals.push_back(tmp2);
	}
}
CGame::~CGame()
{
	delete cn;
}
CPeople* CGame::getPeople()
{
	return cn;
}
vector<CVehicle*> CGame::getVehicle()
{
	return vehicles;
}
vector<CAnimal*> CGame::getAnimal()
{
	return animals;
}
void CGame::menu()
{
	bool b = true;
	while (b)
	{
		createTitle();
		textcolor(6);
		wcout << "                                            1. Load game (T)" << endl;
		wcout << "                                            2. New game (Y)" << endl;
		wcout << "                                            3. Setting game (S)" << endl;
		wchar_t choice;
		wcout << "                                                    Answer:"; wcin >> choice;
		wcin.ignore();
		if (toupper(choice) == 'T')
		{
			b = false;
			wcout.flush();
			system("cls");
			loadGame();
		}
		else if (choice == 'y')
		{
			b = false;
			wcout.flush();
			system("cls");
			//don't need to do any break and the thread will take care the rest
		}
		else
		{
			b = true;
			system("cls");
		}
	}

}
void CGame::startGame()// for menu :)) maybe :))
{
	menu();
}
void CGame::saveGame()
{

	wstring path;
	wcout << endl << endl << endl;
	wcout << "\t\tPlease enter the path you want to save: ";
	getline(wcin, path);
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		wcout << "The path you input is not exist." << endl;
		return;
	}
	fout << cn->getX() << endl;
	fout << cn->getY() << endl;
	if (cn->isDead())
		fout << 0 << endl;
	else
		fout << 1 << endl;
	fout << lv<<endl;
	for (int i = 0; i < 20; ++i)
	{
		fout << vehicles[i]->getX() << " " << vehicles[i]->getY() << " " << vehicles[i]->getType() << endl;
	}
	for (int i = 0; i < 20; ++i)
	{
		fout << animals[i]->getX() << " " << animals[i]->getY() << " " << animals[i]->getType() << endl;
	}
	if (CTLtruck.Color())
		fout << 1 << endl;
	else
		fout << 0 << endl;
	if (CTLcar.Color())
		fout << 1 << endl;
	else
		fout << 0 << endl;
	fout.close();
	system("cls");
}
void CGame::loadGame()
{
	textcolor(7);
	wstring path;
	wcout << endl << endl << endl;
	wcout << "\t\tPlease enter the path you want to load: ";
	getline(wcin, path);
	ifstream fin;
	fin.open(path);
	delete cn;
	int x, y, state,type;
	fin >> x >> y >> state;
	fin >> lv;
	cn = new CPeople(x, y, state);
	vehicles.resize(0);
	animals.resize(0);
	CVehicle *tmp1;
	CAnimal *tmp2;
	for (int i = 0; i < 20; ++i)
	{
		fin >> x >> y >> type;
		if (type == 1)
			tmp1 = new CTruck(x, y);
		else
			tmp1 = new CCar(x, y);
		vehicles.push_back(tmp1);
	}
	for (int i = 0; i < 20; ++i)
	{
		fin >> x >> y >> type;
		if (type == 1)
			tmp2 = new CDinosaur(x, y);
		else
			tmp2 = new CBird(x, y);
		animals.push_back(tmp2);
	}
	fin >> state;
	if (state == 1)
		CTLtruck.SetColor(true);
	else
		CTLtruck.SetColor(false);
	fin >> state;
	if (state == 1)
		CTLcar.SetColor(true);
	else
		CTLcar.SetColor(false);
	fin.close();
}
void CGame::exitGame(thread* t, bool& exitProgram)
{
	exitProgram = false;
	t->join();
}

void CGame::pauseGame(HANDLE pause)
{
	DWORD suspend_retval = SuspendThread(pause);
	chrono.pause();
}
void CGame::resumeGame(HANDLE resume)
{
	DWORD resume_retval = ResumeThread(resume);
	chrono.resume();
}
void CGame::resetGame(int cmd)
{
	if (cmd == 0)
	{
		delete cn;
		cn = new CPeople;
		lv = 0;
	}
	vehicles.resize(0);
	animals.resize(0);
	chrono.reset(true);
	CTLcar.SetColor(true);
	CTLtruck.SetColor(true);
	CVehicle *tmp1;
	CAnimal *tmp2;
	int x;
	cn = new CPeople;
	for (int i = 0; i < 20; i += 2)//10 element each class
	{
		x = std::rand() % 6+lv;
		tmp1 = new CTruck(6 * x);
		vehicles.push_back(tmp1);
		tmp1 = new CCar(6 * x);
		vehicles.push_back(tmp1);
		tmp2 = new CBird(6 * x);
		animals.push_back(tmp2);
		tmp2 = new CDinosaur(6 * x);
		animals.push_back(tmp2);
	}
	PlaySound(TEXT("Street SOUND EFFECTS - Street Ambience Hintergrundgeräusche Straße.wav"), NULL, SND_ASYNC);

}
void CGame::levelup(bool & is_running)
{
	if (lv <= 5)
	{
		++lv;
		cn->rePos();
		PlaySound(NULL, NULL, SND_ASYNC);
		PlaySound(TEXT("Audience Clapping - Sound Effect.wav"), NULL, SND_FILENAME);
		resetGame(1);
		

	}
	else
	{
		is_running = false;
		PlaySound(NULL, NULL, SND_ASYNC);
		PlaySound(TEXT("Audience Clapping - Sound Effect.wav"), NULL, SND_FILENAME);
		system("cls");
		wcout << "\n\n\n\t\t\tYou won." << endl;
	}
}
//place here tempolarily
void CGame::drawMap()
{
	for (int i = 0; i < 24; i++)
	{

		for (int j = 0; j < 70; j++)
		{

			if (i+1<=20&&(i+1) % 4 == 0)
			{
				map[i][j] = '_';
			}
			else
				map[i][j] = ' ';
		}
	}
	
	
}
void CGame::drawGame()
{
	GotoXY(0, 0);
		wcout<<"\n\n\n";
		for (int i = 0; i < 24; i++)
		{
			wcout <<"\t\t";
			for (int j = 0; j < 70; j++)
			{
				
				if (map[i][j]==9604 || map[i][j] == '_'||map[i][j]==708||map[i][j]==9600||map[i][j]== 9608)
				{
					textcolor(240);
					wcout << map[i][j];
					textcolor(7);
				}
				else if (i == 12 && j == 67)//traffic light of car
				{
					if (CTLcar.Color())
					{
						textcolor(160);
						wcout << map[i][j];
						textcolor(7);
					}
					else
					{
						textcolor(64);
						wcout << map[i][j];
						textcolor(7);
					}
				}
				else if (i == 16 && j == 2)//traffic light of truck
				{
					if (CTLtruck.Color())
					{
						textcolor(160);
						wcout << map[i][j];
						textcolor(7);
					}
					else
					{
						textcolor(64);
						wcout << map[i][j];
						textcolor(7);
					}
				}
				else
				{
					textcolor(250);
					wcout << map[i][j];
					textcolor(7);
				}
				
					
			}
			wcout << endl;
		}
}
void CGame::clearMap()
{
	for (int i = 0; i < 24; i++)
	{

		for (int j = 0; j < 70; j++)
	

			map[i][j] = ' ';
	}
}
void CGame::updatePosPeople(const char& key)
{
	cn->Up(key);
	cn->Down(key);
	cn->Left(key);
	cn->Right(key);
	drawPeople();
}
void CGame::drawPeople()
{
	int x = cn->getX();
	int y = cn->getY();
	map[x][y]=708; // Body,center
	map[x - 1][y] =9604; // Head
	
}
void CGame::updatePosVehicle()
{
	
		for (auto iter = vehicles.begin(); iter != vehicles.end(); ++iter)
		{
			if ((*iter)->getType() == 1&&CTLtruck.Color())
				(*iter)->Move(lv);
			else if((*iter)->getType() == 2 && CTLcar.Color())
				(*iter)->Move(lv);
			
			if ((*iter)->getType() == 1)
				drawTruck((*iter));
			else
				drawCar((*iter));
		}
		
		srand(time(NULL));
		m_time = chrono.getElapsedTime();
		 if (m_time.asSeconds() > randtime)
		 {
			 if (CTLcar.Color())
				 CTLcar.SetColor(false);
			 else 
				 CTLcar.SetColor(true);
			 if (CTLtruck.Color())
				 CTLtruck.SetColor(false);
			 else
				 CTLtruck.SetColor(true);
			 chrono.reset(true);
			 randtime = rand() % 6 ;
		}


}
void CGame::updatePosAnimal()
{
		for (auto iter = animals.begin(); iter != animals.end(); ++iter)
		{
			(*iter)->Move(lv);
			if ((*iter)->getType() == 1)
				drawDinosaur((*iter));
			else
				drawBird((*iter));
		}

}
void CGame::drawTruck(CVehicle* obj)
{
	int x = obj->getX();
	int y = obj->getY();
	map[x][y] = 9600; // center
	map[x][y + 1] = 9600;
	map[x][y - 1] = 9600;
	map[x - 1][y] = 9604;
	map[x - 1][y + 1] = 9604;
}
void CGame::drawCar(CVehicle* obj)
{
	int x = obj->getX();
	int y = obj->getY();
	map[x][y] = 9600; // center
	map[x][y - 1] = 9600;
	map[x][y + 1] = 9600;
	map[x][y + 2] = 9600;
	map[x - 1][y] = 9604;
	map[x - 1][y + 1] = 9604;
}
void CGame::drawBird(CAnimal*obj)
{
	int x = obj->getX();
	int y = obj->getY();
	map[x][y] = 9600; // head,center
	map[x - 1][y - 1] = 9604; // wing1
	map[x - 1][y + 1] = 9604;//wing2
}

void CGame::drawDinosaur(CAnimal*obj)
{
	int x = obj->getX();
	int y = obj->getY();
	map[x][y] = 9600; // center
	map[x][y - 1] = 9600;
	map[x - 1][y] = 9604;
	map[x - 1][y + 1] = 9608;
}
