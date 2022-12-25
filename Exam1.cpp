
#include <iostream>
#include <conio.h>
#include <locale>
#include <stdlib.h>
#include <algorithm>
#include <windows.h>

using namespace std;

void game3x3selfmade()
{
	srand(time(NULL));
	int count{}; //Количество перестановок
	int const cow = 3;//Размер строк
	int const row = 3;// Размер столбцов
	int mass[cow][row]{ 0,1,2,3,4,5,6,7,8 };// Основной массив
	int chooise2{};
	int const sizezero = 2;
	int zeroelem[sizezero]{};
	int* decision{};
	decision = &mass[0][0];// Указатель на нулевой элемент массива
	int number = 9;
	cout << "1)Ручное выставление элементов " << endl;
	cout << "2)Случайная генерация элементов массива " << endl;
	cin >> chooise2;
	int count2{};//Счетчик правильных элементов
	bool solution = true;
	switch (chooise2)
	{
	case 1:
		cout << "Ввидите желаемые порядок элементов от 0 до 8 без повторов" << endl;
		for (int i = 0; i < number; i++)
		{
			cin >> decision[i];
			cout << "Ввидите следующий элемент" << endl;
		}
		break;
	case 2:
		random_shuffle(begin(mass), end(mass));//Алгоритм перетасовки элементов массива
		break;
	}
	int start = clock();// Отсчет времени нашего решения
	while( solution == true)//Основной цикл решения
	{
		system("cls");// Отчистка строки от предыдущего массива
		for (int i = 0; i < cow; i++)// Цикл нахождения нулевого элемента
		{
			for (int j = 0; j < row; j++)
			{
				if (mass[i][j] == 0)
				{
					zeroelem[0] = i;
					zeroelem[1] = j;
				}
			}
		}
		for (int i = 0; i < cow; i++)// Цикл вывода игрового поля
		{
			cout << endl;
			cout << "\t___________________________________" << endl;
			for (int j = 0; j < row; j++)
			{
				cout << "\t|" << mass[i][j] << "|\t";
			}
			cout << endl;
			cout << "\t-----------------------------------";
			
		}
		cout << endl;
		char movement = _getch();
		switch (movement)// Свитч на движения нашего 0
		{
		case 72://Движение вверх
			if (zeroelem[0] - 1 < 0)
			{
				cout << "Ты не можешь туда сходить" << endl;
				system("pause");
				cin.get();
				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0] - 1][zeroelem[1]];
				mass[zeroelem[0] - 1][zeroelem[1]] = 0;
				count++;
				break;
			}
		case 80://Движение вниз
			if (zeroelem[0] + 1 > 2)
			{
				cout << "Ты не можешь туда сходить" << endl;
				system("pause");
				cin.get();
				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0] + 1][zeroelem[1]];
				mass[zeroelem[0] + 1][zeroelem[1]] = 0;
				count++;
				break;
			}
		case 75:// Движение влево
			if (zeroelem[1] - 1 < 0)
			{
				cout << "Ты не можешь туда сходить" << endl;
				system("pause");
				cin.get();
				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0]][zeroelem[1] - 1];
				mass[zeroelem[0]][zeroelem[1] - 1] = 0;
				count++;
				break;
			}
		case 77:// Движение вправо
			if (zeroelem[1] + 1 > 2)
			{
				cout << "Ты не можешь туда сходить" << endl;
				system("pause");
				cin.get();
				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0]][zeroelem[1] + 1];
				mass[zeroelem[0]][zeroelem[1] + 1] = 0;
				count++;
				break;
			}
		}
		for (int i = 0; i < number; i++)
		{
			if (decision[i] >= decision[i + 1])
			{
				
				count2++;
				if (count2 >= number)
				{
					solution = false;
				}
			}
		}
		count2 = 0;
	
	}
	int end = clock();
	int result = (end - start) / CLOCKS_PER_SEC;//Вычесление времени решения
	cout << "Поздравляем вы решили верно" << endl;
	cout << "Время потраченное на решение " << result << " секунд" << endl;
	cout << "Количество перестановок " << count << endl;
}

void game4x4selfmade()
{
	srand(time(NULL));
	int count{}; //Количество перестановок
	int seconds = time(NULL);
	int const cow = 4;//Размер строк
	int const row = 4;// Размер столбцов
	int mass[cow][row]{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};// Основной массив
	int const sizezero = 2;
	int zeroelem[sizezero]{};
	int* decision{};
	decision = &mass[0][0];// Указатель на нулевой элемент массива
	int number = 16;
	int chooise2{};
	int count2{};
	bool solution = true;
	cout << "1)Ручное выставление элементов " << endl;
	cout << "2)Случайная генерация элементов массива " << endl;
	cin >> chooise2;
	switch (chooise2)
	{
	case 1:
		cout << "Ввидите желаемые порядок элементов от 0 до 15 без повторов" << endl;
		for (int i = 0; i < number; i++)
		{
			cin >> decision[i];
			cout << "Ввидите следующий элемент" << endl;
		}
		break;
		break;
	case 2:
		random_shuffle(begin(mass), end(mass));//Алгоритм перетасовки элементов массива
		break;
	}
	int start = clock();// Отсчет времени нашего решения
	while (solution == true)//Основной цикл решения
	{
		system("cls");// Отчистка строки от предыдущего массива
		for (int i = 0; i < cow; i++)// Цикл нахождения нулевого элемента
		{
			for (int j = 0; j < row; j++)
			{
				if (mass[i][j] == 0)
				{
					zeroelem[0] = i;
					zeroelem[1] = j;
				}
			}
		}
		for (int i = 0; i < cow; i++)// Цикл вывода игрового поля
		{
			cout << endl;
			cout << "\t____________________________________________________" << endl;
			for (int j = 0; j < row; j++)
			{

				cout << "\t|" << mass[i][j] << "|\t";
			}
			cout << endl;
			cout << "\t----------------------------------------------------";

		}
		cout << endl;
		char movement = _getch();
		switch (movement)// Свитч на движения нашего 0
		{
		case 72://Движение вверх
			if (zeroelem[0] - 1 < 0)
			{
				cout << "Ты не можешь туда сходить" << endl;
				system("pause");
				cin.get();
				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0] - 1][zeroelem[1]];
				mass[zeroelem[0] - 1][zeroelem[1]] = 0;
				count++;
				break;
			}
		case 80://Движение вниз
			if (zeroelem[0] + 1 > 3)
			{
				cout << "Ты не можешь туда сходить" << endl;
				system("pause");
				cin.get();
				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0] + 1][zeroelem[1]];
				mass[zeroelem[0] + 1][zeroelem[1]] = 0;
				count++;
				break;
			}
		case 75:// Движение влево
			if (zeroelem[1] - 1 < 0)
			{
				cout << "Ты не можешь туда сходить" << endl;
				system("pause");
				cin.get();
				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0]][zeroelem[1] - 1];
				mass[zeroelem[0]][zeroelem[1] - 1] = 0;
				count++;
				break;
			}
		case 77:// Движение вправо
			if (zeroelem[1] + 1 > 3)
			{
				cout << "Ты не можешь туда сходить" << endl;
				system("pause");
				cin.get();
				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0]][zeroelem[1] + 1];
				mass[zeroelem[0]][zeroelem[1] + 1] = 0;
				count++;
				break;
			}
		}
		for (int i = 0; i < number; i++)
		{
			if (decision[i] >= decision[i + 1])
			{
				count2++;
				if (count2 >= number)
				{
					solution = false;
				}
			}
		}
		count2 = 0;
	
	}
	int end = clock();
	int result = (end - start) / CLOCKS_PER_SEC;//Вычесление времени решения
	cout << "Поздравляем вы решили верно" << endl;
	cout << "Время потраченное на решение " << result<< " секунд" << endl;
	cout << "Количество перестановок " << count << endl;
}
void game3x3auto()
{
	srand(time(NULL));
	int count{}; //Количество перестановок
	int const cow = 3;//Размер строк
	int const row = 3;// Размер столбцов
	int mass[cow][row]{ 0,1,2,3,4,5,6,7,8 };// Основной массив
	int chooise2{};
	int const sizezero = 2;
	int zeroelem[sizezero]{};
	int* decision{};
	decision = &mass[0][0];// Указатель на нулевой элемент массива
	int number = 9;
	cout << "1)Ручное выставление элементов " << endl;
	cout << "2)Случайная генерация элементов массива " << endl;
	cin >> chooise2;
	int count2{};//Счетчик правильных элементов
	bool solution = true;
	switch (chooise2)
	{
	case 1:
		cout << "Ввидите желаемые порядок элементов от 0 до 8 без повторов" << endl;
		for (int i = 0; i < number; i++)
		{
			cin >> decision[i];
			cout << "Ввидите следующий элемент" << endl;
		}
		break;
	case 2:
		random_shuffle(begin(mass), end(mass));//Алгоритм перетасовки элементов массива
		break;
	}
	int start = clock();// Отсчет времени нашего решения
	while (solution == true)//Основной цикл решения
	{
		system("cls");// Отчистка строки от предыдущего массива
		for (int i = 0; i < cow; i++)// Цикл нахождения нулевого элемента
		{
			for (int j = 0; j < row; j++)
			{
				if (mass[i][j] == 0)
				{
					zeroelem[0] = i;
					zeroelem[1] = j;
				}
			}
		}
		for (int i = 0; i < cow; i++)// Цикл вывода игрового поля
		{
			cout << endl;
			cout << "\t___________________________________" << endl;
			for (int j = 0; j < row; j++)
			{

				cout << "\t|" << mass[i][j] << "|\t";
			}
			cout << endl;
			cout << "\t-----------------------------------";

		}
		int autochooose{};
		autochooose = 1 + rand() % (4 - 1 + 1);
		switch (autochooose)// Свитч на движения нашего 0
		{
		case 1://Движение вверх
			if (zeroelem[0] - 1 < 0)
			{
				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0] - 1][zeroelem[1]];
				mass[zeroelem[0] - 1][zeroelem[1]] = 0;
				count++;
				break;
			}
		case 2://Движение вниз
			if (zeroelem[0] + 1 > 3)
			{
			
				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0] + 1][zeroelem[1]];
				mass[zeroelem[0] + 1][zeroelem[1]] = 0;
				count++;
				break;
			}
		case 3:// Движение влево
			if (zeroelem[1] - 1 < 0)
			{
				
				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0]][zeroelem[1] - 1];
				mass[zeroelem[0]][zeroelem[1] - 1] = 0;
				count++;
				break;
			}
		case 4:// Движение вправо
			if (zeroelem[1] + 1 > 3)
			{
				
				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0]][zeroelem[1] + 1];
				mass[zeroelem[0]][zeroelem[1] + 1] = 0;
				count++;
				break;
			}
		}
		cout << endl;
		for (int i = 0; i < number; i++)
		{
			if (decision[i] >= decision[i + 1])
			{
				count2++;
				if (count2 >= number)
				{
					solution = false;
				}
			}
		}
		count2 = 0;
		Sleep(1000);
	
	}
	int end = clock();
	int result = (end - start) / CLOCKS_PER_SEC;//Вычесление времени решения
	cout << "Поздравляем вы решили верно" << endl;
	cout << "Время потраченное на решение " << result << " секунд" << endl;
	cout << "Количество перестановок " << count << endl;
}
void game4x4auto()
{
	srand(time(NULL));
	int count{}; //Количество перестановок
	int const cow = 4;//Размер строк
	int const row = 4;// Размер столбцов
	int mass[cow][row]{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };// Основной массив
	int chooise2{};
	int const sizezero = 2;
	int zeroelem[sizezero]{};
	int* decision{};
	decision = &mass[0][0];// Указатель на нулевой элемент массива
	int number = 16;
	cout << "1)Ручное выставление элементов " << endl;
	cout << "2)Случайная генерация элементов массива " << endl;
	cin >> chooise2;
	int count2{};//Счетчик правильных элементов
	bool solution = true;
	switch (chooise2)
	{
	case 1:
		cout << "Ввидите желаемые порядок элементов от 0 до 8 без повторов" << endl;
		for (int i = 0; i < number; i++)
		{
			cin >> decision[i];
			cout << "Ввидите следующий элемент" << endl;
		}
		break;
	case 2:
		random_shuffle(begin(mass), end(mass));//Алгоритм перетасовки элементов массива
		break;
	}
	int start = clock();// Отсчет времени нашего решения
	while (solution == true)//Основной цикл решения
	{
		system("cls");// Отчистка строки от предыдущего массива
		for (int i = 0; i < cow; i++)// Цикл нахождения нулевого элемента
		{
			for (int j = 0; j < row; j++)
			{
				if (mass[i][j] == 0)
				{
					zeroelem[0] = i;
					zeroelem[1] = j;
				}
			}
		}
		for (int i = 0; i < cow; i++)// Цикл вывода игрового поля
		{
			cout << endl;
			cout << "\t____________________________________________________" << endl;
			for (int j = 0; j < row; j++)
			{

				cout << "\t|" << mass[i][j] << "|\t";
			}
			cout << endl;
			cout << "\t----------------------------------------------------";

		}
		int autochooose{};
		autochooose = 1 + rand() % (4 - 1 + 1);
		switch (autochooose)// Свитч на движения нашего 0
		{
		case 1://Движение вверх
			if (zeroelem[0] - 1 < 0)
			{
				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0] - 1][zeroelem[1]];
				mass[zeroelem[0] - 1][zeroelem[1]] = 0;
				count++;
				break;
			}
		case 2://Движение вниз
			if (zeroelem[0] + 1 > 3)
			{

				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0] + 1][zeroelem[1]];
				mass[zeroelem[0] + 1][zeroelem[1]] = 0;
				count++;
				break;
			}
		case 3:// Движение влево
			if (zeroelem[1] - 1 < 0)
			{

				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0]][zeroelem[1] - 1];
				mass[zeroelem[0]][zeroelem[1] - 1] = 0;
				count++;
				break;
			}
		case 4:// Движение вправо
			if (zeroelem[1] + 1 > 3)
			{

				break;
			}
			else
			{
				mass[zeroelem[0]][zeroelem[1]] = mass[zeroelem[0]][zeroelem[1] + 1];
				mass[zeroelem[0]][zeroelem[1] + 1] = 0;
				count++;
				break;
			}
		}
		cout << endl;
		for (int i = 0; i < number; i++)
		{
			if (decision[i] >= decision[i + 1])
			{
				count2++;
				if (count2 >= number)
				{
					solution = false;
				}
			}
		}
		count2 = 0;
		Sleep(1000);
		
	}
	int end = clock();
	int result = (end - start) / CLOCKS_PER_SEC;//Вычесление времени решения
	cout << "Поздравляем вы решили верно" << endl;
	cout << "Время потраченное на решение " << result << " секунд" << endl;
	cout << "Количество перестановок " << count << endl;
}

int main()
{
	int chooise{};
	int chooise2{};
	setlocale(LC_ALL, "RUS");
	bool flag = true;
	while (flag == true)
	{
		cout << "\t\t\t\t\t\t    Пятнашки" << endl;
		cout << "1) Поле 4x4" << endl;
		cout << "2) Поле 3x3" << endl;
		cout << "3) Выход" << endl;
		cin >> chooise;
		switch (chooise)
		{
		case 1:
			system("cls");
			cout << "1) Автоматическая сборка" << endl;
			cout << "2) Ручная сборка" << endl;
			cout << "3) Вернуться назад " << endl;
			cin >> chooise2;
			switch (chooise2)
			{
			case 1:
				system("cls");
				game4x4auto();
				flag = false;
				break;
			case 2:
				system("cls");
				game4x4selfmade();
				flag = false;
				break;
			case 3:
				break;
			}
			break;
		case 2:
			system("cls");
			cout << "1) Автоматическая сборка" << endl;
			cout << "2) Ручная сборка" << endl;
			cout << "3) Вернуться назад " << endl;
			cin >> chooise2;
			switch (chooise2)
			{
			case 1:
				system("cls");
				game3x3auto();
				flag = false;
				break;
			case 2:
				system("cls");
				game3x3selfmade();
				flag = false;
				break;
			}
			break;
		case 3:
			flag = false;
			exit;
			break;
		default:
			cout << "Ваш ввод не верный,попробуйте еще раз " << endl;
			break;
		}
	}
}

