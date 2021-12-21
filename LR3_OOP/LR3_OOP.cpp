#include <iostream>
#include "pch.h"
#include "Point.h"
#include "Circle.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Cylinder.h"
#include "Scope.h"
#include "LinkedList.h"

using namespace std;

//установить цвет консоли
void setClr(int clr)
{
	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleHandle, (WORD)(0 | clr)); //Задаем  цвет текста
}

//вывод списка на экран
void PrintList(LinkedList<Point>* linkedList)
{
	cout << "\nТекущее состояние списка:" << endl;
	//выведем на экран каждый элемент списка и его поля
	cout << "Длинна :  " << linkedList->GetLength() << endl;

	//номер отрисовываемого элемента
	int i = 1;

	Node<Point>* init = linkedList->GetCurrent();

	linkedList->MoveFirst();

	for (int i = 1; i <= linkedList->GetLength(); i++)
	{

		if (linkedList->GetCurrent() == init)
			setClr(10);

		cout << "[" << i << "] : " << linkedList->GetValue()->GetType() << endl;

		linkedList->MoveNext();

		setClr(15);
	}

	linkedList->SetCurrent(init);

	setClr(15);
}



int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(0));

	LinkedList<Point> linkedList;
	Point* newObj;
	PrintList(&linkedList);


	for (int i = 0; i < 10; i++)
	{
		cout << "_________________________________________________________________" << endl;
		//узнаем тип объекта и добавляем его в список
		int objType = rand() % 4 + 1;

		switch (objType)
		{
		case 1:
			newObj = new Point();
			break;
		case 2:
			newObj = new Circle();
			break;
		case 3:
			newObj = new Cylinder();
			break;
		case 4:
			newObj = new Scope();
			break;
		default:
			newObj = new Point();
			break;
		}

		int code;
		if (linkedList.GetLength() == 0)
			code = 1;
		else code = rand() % 2 + 1;
		switch (code)
		{
		case 1:
			linkedList.AddAfter(newObj);
			cout << "Элемент " << linkedList.GetValue()->GetType() << " добавлен после текущего просматриваемого" << endl;
			PrintList(&linkedList);
			break;
		case 2:

			if (linkedList.GetLength() != 0)
				linkedList.AddBefore(newObj);
			cout << "Элемент " << linkedList.GetValue()->GetType() << "  добавлен до текущего просматриваемого" << endl;
			PrintList(&linkedList);
			break;
		}

		code = rand() % 4 + 1;
		switch (code)
		{
		case 1:
			cout << "Элемент " << linkedList.GetValue()->GetType() << " удален" << endl;
			linkedList.Delete();
			PrintList(&linkedList);
			break;
		case 2:
			cout << "вызван метод хранилища MoveNext()" << endl;
			linkedList.MoveNext();
			PrintList(&linkedList);
			break;
		case 3:
			cout << "вызван метод хранилища MovePrev();" << endl;
			linkedList.MovePrev();
			PrintList(&linkedList);
			break;
		case 4:
			if (linkedList.GetLength() != 0)
			{
				cout << "координата x до сдвига: " << linkedList.GetCurrent()->GetValue()->GetX() << endl;
				linkedList.GetCurrent()->GetValue()->Move(1, 1);
				cout << "координата x и y сдвинулись на (1, 1)" << endl;
				cout << "координата x после сдвига: " << linkedList.GetCurrent()->GetValue()->GetX() << endl;
			}
			break;
		}
	}
	cout << "_________________________________________________________________" << endl;
}