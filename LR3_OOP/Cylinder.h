#pragma once
#include "Circle.h"
class Cylinder : public Circle
{
private:
	float h;
public:
	//конструктор по умолчанию для класса Сylinder
	Cylinder();

	//конструктор с параметрами для класса Сylinder
	Cylinder(float a, float b, float rad, float he);

	//Конструктор копирования ( т.е. копирует х и у )
	Cylinder(Cylinder& cylinder);

	//Вывод содержимого класса
	void Print();

	void Modify() override;

	//возврат имени типа
	const char* GetType() override;

	//Получение высоты 
	float GetH();

	//Установка высоты
	void SetH(float he);


	~Cylinder()override;
};

