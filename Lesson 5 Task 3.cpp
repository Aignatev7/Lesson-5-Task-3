#include <iostream>

class Figure // класс Фигура
{
protected:
    std::string figure_name;
    int number_of_sides;

public:
    Figure() {
        figure_name = "Фигура";
        number_of_sides = 0;
        int side_a = 0;
        int side_b = 0;
        int side_c = 0;
        int side_d = 0;
        int corner_A = 0;
        int corner_B = 0;
        int corner_C = 0;
        int corner_D = 0;
    }
    std::string get_figure_name() { return figure_name; }
    int get_number_of_sides() { return number_of_sides; }

    virtual bool check() {
        if (number_of_sides == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    std::string correct = (check() ? "Правильная" : "Неправильная");

    virtual void print_myself() {
        std::cout << get_figure_name() << ": \n" << correct << std::endl;
        std::cout << "Количество сторон: " << get_number_of_sides() << "\n"
            << std::endl;
    }
};

class Triangle : public Figure // класс Треугольник
{
protected:
    int side_a = 0;
    int side_b = 0;
    int side_c = 0;
    int corner_A = 0;
    int corner_B = 0;
    int corner_C = 0;

public:
    Triangle() {
        figure_name = "Треугольник";
        number_of_sides = 3;
        side_a = 10;
        side_b = 20;
        side_c = 30;
        corner_A = 50;
        corner_B = 60;
        corner_C = 70;
    }

    Triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B,
        int corner_C) {
        side_a = 0;
        side_b = 0;
        side_c = 0;
        corner_A = 0;
        corner_B = 0;
        corner_C = 0;
    }

    int get_side_a() { return side_a; }
    int get_side_b() { return side_b; }
    int get_side_c() { return side_c; }
    int get_corner_A() { return corner_A; }
    int get_corner_B() { return corner_B; }
    int get_corner_C() { return corner_C; }

    bool check() override {
        if ((number_of_sides == 3) && ((corner_A + corner_B + corner_C) == 180)) {
            return true;
        }
        else {
            return false;
        }
    }

    void print_myself() override {
        std::cout << get_figure_name() << ": \n"
            << correct << std::endl;
        std::cout << "Количество сторон: " << get_number_of_sides() << std::endl;
        std::cout << "Стороны: "
            << "a=" << get_side_a() << " b=" << get_side_b()
            << " c=" << get_side_c() << std::endl;
        std::cout << "Углы: "
            << "А=" << get_corner_A() << " B=" << get_corner_B()
            << " C=" << get_corner_C() << "\n"
            << std::endl;
    }
};

class RightTriangle : public Triangle // класс Прямоугольный треугольник
{
public:
    RightTriangle() {
        figure_name = "Прямоугольный треугольник";
        corner_C = 90;
    }

    RightTriangle(int side_a, int side_b, int side_c, int corner_A,
        int corner_B) {
        side_a = 0;
        side_b = 0;
        side_c = 0;
        corner_A = 0;
        corner_B = 0;
    }
    bool check() override {
        if (corner_C == 90) {
            return true;
        }
        else {
            return false;
        }
    }
};

class IsoscelesTriangle : public Triangle // класс Равнобедренный треугольник
{
public:
    IsoscelesTriangle() {
        figure_name = "Равнобедренный треугольник";
        side_a = side_c = 10;
        corner_A = corner_C = 50;
    }

    IsoscelesTriangle(int side_b, int side_c, int corner_B, int corner_C) {
        side_a = side_c = 0;
        side_b = 0;
        corner_A = corner_C = 0;
        corner_B = 0;
    }
    bool check() override {
        if ((side_a == side_c) && (corner_A == corner_C)) {
            return true;
        }
        else {
            return false;
        }
    }
};

class EquilateralTriangle : public Triangle // класс Равносторонний треугольник
{
public:
    EquilateralTriangle() {
        figure_name = "Равносторонний треугольник";
        side_a = side_b = side_c = 30;
        corner_A = corner_B = corner_C = 60;
    }

    EquilateralTriangle(int side_c, int corner_C) {
        side_a = side_b = side_c = 0;
        corner_A = corner_B = corner_C = 0;
    }
    bool check() override {
        if ((side_a == side_b == side_c) &&
            (corner_A == corner_B == corner_C == 90)) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Quadrangle : public Figure // класс Четырёхугольник
{
protected:
    int side_a = 0;
    int side_b = 0;
    int side_c = 0;
    int side_d = 0;
    int corner_A = 0;
    int corner_B = 0;
    int corner_C = 0;
    int corner_D = 0;

public:
    Quadrangle() {
        figure_name = "Четырёхугольник";
        number_of_sides = 4;
        side_a = 10;
        side_b = 20;
        side_c = 30;
        side_d = 40;
        corner_A = 50;
        corner_B = 60;
        corner_C = 70;
        corner_D = 80;
    }

    Quadrangle(int side_a, int side_b, int side_c, int side_d, int corner_A,
        int corner_B, int corner_C, int corner_D) {
        side_a = 0;
        side_b = 0;
        side_c = 0;
        side_d = 0;
        corner_A = 0;
        corner_B = 0;
        corner_C = 0;
        corner_D = 0;
    }

    int get_side_a() { return side_a; }
    int get_side_b() { return side_b; }
    int get_side_c() { return side_c; }
    int get_side_d() { return side_d; }
    int get_corner_A() { return corner_A; }
    int get_corner_B() { return corner_B; }
    int get_corner_C() { return corner_C; }
    int get_corner_D() { return corner_D; }

    bool check() override {
        if ((number_of_sides == 4) &&
            ((corner_A + corner_B + corner_C + corner_D) == 360)) {
            return true;
        }
        else {
            return false;
        }
    }

    void print_myself() override {
        std::cout << get_figure_name() << ": \n" << correct << std::endl;
        std::cout << "Количество сторон: " << get_number_of_sides() << std::endl;
        std::cout << "Стороны: "
            << "a=" << get_side_a() << " b=" << get_side_b()
            << " c=" << get_side_c() << " d=" << get_side_d() << std::endl;
        std::cout << "Углы: "
            << "А=" << get_corner_A() << " B=" << get_corner_B()
            << " C=" << get_corner_C() << " D=" << get_corner_D() << "\n"
            << std::endl;
    }
};

class Rectangle : public Quadrangle // класс Прямоугольник
{
public:
    Rectangle() {
        figure_name = "Прямоугольник";
        side_a = side_c = 10;
        side_b = side_d = 20;
        corner_A = corner_B = corner_C = corner_D = 90;
    }

    Rectangle(int side_c, int side_d, int corner_D) {
        side_a = side_c = 0;
        side_b = side_d = 0;
        corner_A = corner_B = corner_C = corner_D = 0;
    }

    bool check() override {
        if (((side_a == side_c) && (side_b == side_d)) &&
            (corner_A == corner_B == corner_C == corner_D == 90)) {
            return true;
        }
    }
};

class Square : public Rectangle // класс Квадрат
{
public:
    Square() {
        figure_name = "Квадрат";
        side_a = side_b = side_c = side_d = 20;
        corner_A = corner_B = corner_C = corner_D = 90;
    }

    Square(int side_d, int corner_D) {
        side_a = side_b = side_c = side_d = 0;
        corner_A = corner_B = corner_C = corner_D = 0;
    }

    bool check() override {
        if ((side_a == side_b == side_c == side_d) &&
            (corner_A == corner_B == corner_C == corner_D == 90)) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Parallelogram : public Rectangle // класс Параллелограмм
{
public:
    Parallelogram() {
        figure_name = "Параллелограмм";
        side_a = side_c = 20;
        side_b = side_d = 30;
        corner_A = corner_C = 30;
        corner_B = corner_D = 40;
    }

    Parallelogram(int side_c, int side_d, int corner_C, int corner_D) {
        side_a = side_c = 0;
        side_b = side_d = 0;
        corner_A = corner_C = 0;
        corner_B = corner_D = 0;
    }

    bool check() override {
        if (((side_a == side_c) && (side_b == side_d)) &&
            ((corner_A == corner_C) && (corner_B == corner_D))) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Rhomb : public Parallelogram // класс Ромб
{
public:
    Rhomb() {
        figure_name = "Ромб";
        side_a = side_b = side_c = side_d = 30;
        corner_A = corner_C = 30;
        corner_B = corner_D = 40;
    }

    Rhomb(int side_d, int corner_C, int corner_D) {
        side_a = side_b = side_c = side_d = 30;
        corner_A = corner_C = 30;
        corner_B = corner_D = 40;
    }

    bool check() override {
        if ((side_a == side_b == side_c == side_d) &&
            ((corner_A == corner_C) && (corner_B == corner_D))) {
            return true;
        }
        else {
            return false;
        }
    }
};

void print_info(Figure* f) { f->print_myself(); }

int main() {
    setlocale(LC_ALL, "Russian");
    Figure fig;
    print_info(&fig);
    Triangle tri;
    print_info(&tri);
    RightTriangle rig_tri;
    print_info(&rig_tri);
    IsoscelesTriangle isos_tri;
    print_info(&isos_tri);
    EquilateralTriangle eq_tri;
    print_info(&eq_tri);
    Quadrangle quad;
    print_info(&quad);
    Rectangle rect;
    print_info(&rect);
    Square square;
    print_info(&square);
    Parallelogram paral;
    print_info(&paral);
    Rhomb rhomb;
    print_info(&rhomb);
}



/*
Задача 3. Фигуры.Методы
В этом задании вы добавите в вашу иерархию классов больше функциональности.

Теперь ваши фигуры должны уметь немного больше :

выводить информацию о себе;
проверять правильность своих данных.
Ваши фигуры :

фигура(количество сторон равно 0);
треугольник(стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
прямоугольный треугольник(угол C всегда равен 90);
равнобедренный треугольник(стороны a и c равны, углы A и C равны);
равносторонний треугольник(все стороны равны, все углы равны 60);
четырёхугольник(стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
прямоугольник(стороны a, c и b, d попарно равны, все углы равны 90);
квадрат(все стороны равны, все углы равны 90);
параллелограмм(стороны a, c и b, d попарно равны, углы A, C и B, D попарно равны);
ромб(все стороны равны, углы A, C и B, D попарно равны).
Вы должны иметь возможность попросить фигуру вывести информацию о себе на консоль, а также узнать, является ли фигура правильной, то есть выполняются ли условия, указанные в списке выше.

Информация о фигуре включает в себя :

название фигуры;
количество сторон;
длины её сторон, если есть;
величины её углов, если есть;
является ли фигура правильной.
Задача: спроектировать и реализовать классы, описывающие предметную область.Продемонструйте их работу : создайте по одному экземпляру каждой фигуры и выведите на экран информацию о фигурах.

Реализуйте методы вывода на консоль и проверки правильности фигуры с помощью виртуальных функций и переопределений.Используйте вызов базовой версии метода.

Ваша задача — работать с экземплярами дочерних классов полиморфно, то есть с помощью указателя на базовый класс.

Пример работы программы
Консоль
Фигура :
Правильная
Количество сторон : 0

Треугольник :
Правильная
Количество сторон : 3
Стороны : a = 10 b = 20 c = 30
Углы : A = 50 B = 60 C = 70

Прямоугольный треугольник :
Неправильная
Количество сторон : 3
Стороны : a = 10 b = 20 c = 30
Углы : A = 50 B = 60 C = 90

Прямоугольный треугольник :
Правильная
Количество сторон : 3
Стороны : a = 10 b = 20 c = 30
Углы : A = 50 B = 40 C = 90

Равнобедренный треугольник :
Неправильная
Количество сторон : 3
Стороны : a = 10 b = 20 c = 10
Углы : A = 50 B = 60 C = 50

Равносторонний треугольник :
Правильная
Количество сторон : 3
Стороны : a = 30 b = 30 c = 30
Углы : A = 60 B = 60 C = 60

Четырёхугольник :
Неправильная
Количество сторон : 4
Стороны : a = 10 b = 20 c = 30 d = 40
Углы : A = 50 B = 60 C = 70 D = 80

Прямоугольник :
Правильная
Количество сторон : 4
Стороны : a = 10 b = 20 c = 10 d = 20
Углы : A = 90 B = 90 C = 90 D = 90

Квадрат :
Правильная
Количество сторон : 4
Стороны : a = 20 b = 20 c = 20 d = 20
Углы : A = 90 B = 90 C = 90 D = 90

Параллелограмм :
Неправильная
Количество сторон : 4
Стороны : a = 20 b = 30 c = 20 d = 30
Углы : A = 30 B = 40 C = 30 D = 40

Ромб :
Неправильная
Количество сторон : 4
Стороны : a = 30 b = 30 c = 30 d = 30
Углы : A = 30 B = 40 C = 30 D = 40
*/