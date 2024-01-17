#include<iostream>
#include<string>

// Модуль 8. Занятие 63. Введение в ООП
// Принципы ООП:
// 1. Инкапсуляция; - модификаторы доступа
// 2. Наследование;
// 3. Полиморфизм;	- конструкторы...
// (4. Абстрактность).

// Создание объекта класса:

class Person {
protected:		// 
	std::string name;
	int age;
public:
	Person() {	// Это конструктор по умолчанию, это функция void
		name = "noname";
		age = 18;
	}
	// Параметрический конструктор (потому что он содержит какие-нибудь параметры):
	Person(std::string name, int age) {
		this->name = name;		// this - это указатель, находящийся внутри объекта и указывает на этот же объект (делается для яповышения абстракности)
		this->age = age;		// означает: мой возраст (первый age) соответствует второму age
	}
	// Конструктор копирования:
	Person(const Person& other) {
		this->name = other.name;	// this - здесь можно не писать
		this->age = other.age;		// this - здесь можно не писать
	}
	// Дeструктор:
	~Person() {
		std::cout << name << " destroy\n";
	}
	// Свойство класса: который обеспечивают доступ к полям класса
	void setName(std::string name) {
		this->name = name;
	}
	std::string getName() {		// Геттер ничего не принимают
		return name;
	}
	void introduce() {		// метод ...
		std::cout << "My name is " << name << std::endl;
	}
};
// Модификаторы доступа:
// 1. private
// 2. protected
// 3. public

// Свойства:
// 1. Геттеры (get)
// 2. Сеттеры (set)

// 
class Student : public Person {	// : класс Student наследует у Person ...
private:
	std::string group;
	int grades_number;	// кол-во оценок
	int* grades;		// его оценки
public:
	// конструктор по умолчанию
	Student() : Person() {
		group = "undefinded";
		grades = nullptr;
		grades_number = 0;
	}
	// Параметрич. конструктор
	Student(std::string name, int age, std::string group, int grades[], int grades_number) : Person(name, age) {
		this->group = group;
		this->grades = new int[grades_number] {};
		for (int i = 0; i < grades_number; i++)
			this->grades[i] = grades[i];
		this->grades_number = grades_number;
	}
	~Student() {	// диструктор применяется в основном для освобождения динамической памяти
		delete[] grades;
	}
	void printGrades() {
		for (int i = 0; i < grades_number; i++)
			std::cout << grades[i] << ' ';
		std::cout << std::endl;
	}	
};


int main() {
	setlocale(LC_ALL, "RU");
	int n;
	
	Person p1("Bob", 25);
	//p1.name = "Bob";	// будет ошибка

	// создадим локальный объект:
	if (true) {
		Person tmp("Mike", 50);
		tmp.introduce();
	}

	p1.introduce();
	// Создадим второй объект и скопируем из p1 в p2
	Person p2(p1);
	// Создадим новое имя для p2:
	p2.setName("Tom");
	p2.introduce();

	std::cout << "Имя объекта: " << p2.getName() << std::endl;
	

	// Работа с классом-наследником:
	int grades[3]{ 10, 12, 9 };
	Student s1("Rodion", 20, "БВ322", grades, 3);
	s1.introduce();
	s1.printGrades();


	return 0;
}