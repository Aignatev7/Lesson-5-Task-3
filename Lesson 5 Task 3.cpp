#include <iostream>

class Figure // ����� ������
{
protected:
    std::string figure_name;
    int number_of_sides;

public:
    Figure() {
        figure_name = "������";
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

    std::string correct = (check() ? "����������" : "������������");

    virtual void print_myself() {
        std::cout << get_figure_name() << ": \n" << correct << std::endl;
        std::cout << "���������� ������: " << get_number_of_sides() << "\n"
            << std::endl;
    }
};

class Triangle : public Figure // ����� �����������
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
        figure_name = "�����������";
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
        std::cout << "���������� ������: " << get_number_of_sides() << std::endl;
        std::cout << "�������: "
            << "a=" << get_side_a() << " b=" << get_side_b()
            << " c=" << get_side_c() << std::endl;
        std::cout << "����: "
            << "�=" << get_corner_A() << " B=" << get_corner_B()
            << " C=" << get_corner_C() << "\n"
            << std::endl;
    }
};

class RightTriangle : public Triangle // ����� ������������� �����������
{
public:
    RightTriangle() {
        figure_name = "������������� �����������";
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

class IsoscelesTriangle : public Triangle // ����� �������������� �����������
{
public:
    IsoscelesTriangle() {
        figure_name = "�������������� �����������";
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

class EquilateralTriangle : public Triangle // ����� �������������� �����������
{
public:
    EquilateralTriangle() {
        figure_name = "�������������� �����������";
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

class Quadrangle : public Figure // ����� ��������������
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
        figure_name = "��������������";
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
        std::cout << "���������� ������: " << get_number_of_sides() << std::endl;
        std::cout << "�������: "
            << "a=" << get_side_a() << " b=" << get_side_b()
            << " c=" << get_side_c() << " d=" << get_side_d() << std::endl;
        std::cout << "����: "
            << "�=" << get_corner_A() << " B=" << get_corner_B()
            << " C=" << get_corner_C() << " D=" << get_corner_D() << "\n"
            << std::endl;
    }
};

class Rectangle : public Quadrangle // ����� �������������
{
public:
    Rectangle() {
        figure_name = "�������������";
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

class Square : public Rectangle // ����� �������
{
public:
    Square() {
        figure_name = "�������";
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

class Parallelogram : public Rectangle // ����� ��������������
{
public:
    Parallelogram() {
        figure_name = "��������������";
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

class Rhomb : public Parallelogram // ����� ����
{
public:
    Rhomb() {
        figure_name = "����";
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
������ 3. ������.������
� ���� ������� �� �������� � ���� �������� ������� ������ ����������������.

������ ���� ������ ������ ����� ������� ������ :

�������� ���������� � ����;
��������� ������������ ����� ������.
���� ������ :

������(���������� ������ ����� 0);
�����������(������� � ���� ������������, ���������� ������ ����� 3, ����� ����� ����� 180);
������������� �����������(���� C ������ ����� 90);
�������������� �����������(������� a � c �����, ���� A � C �����);
�������������� �����������(��� ������� �����, ��� ���� ����� 60);
��������������(������� � ���� ������������, ���������� ������ ����� 4, ����� ����� ����� 360);
�������������(������� a, c � b, d ������� �����, ��� ���� ����� 90);
�������(��� ������� �����, ��� ���� ����� 90);
��������������(������� a, c � b, d ������� �����, ���� A, C � B, D ������� �����);
����(��� ������� �����, ���� A, C � B, D ������� �����).
�� ������ ����� ����������� ��������� ������ ������� ���������� � ���� �� �������, � ����� ������, �������� �� ������ ����������, �� ���� ����������� �� �������, ��������� � ������ ����.

���������� � ������ �������� � ���� :

�������� ������;
���������� ������;
����� � ������, ���� ����;
�������� � �����, ���� ����;
�������� �� ������ ����������.
������: �������������� � ����������� ������, ����������� ���������� �������.��������������� �� ������ : �������� �� ������ ���������� ������ ������ � �������� �� ����� ���������� � �������.

���������� ������ ������ �� ������� � �������� ������������ ������ � ������� ����������� ������� � ���������������.����������� ����� ������� ������ ������.

���� ������ � �������� � ������������ �������� ������� ����������, �� ���� � ������� ��������� �� ������� �����.

������ ������ ���������
�������
������ :
����������
���������� ������ : 0

����������� :
����������
���������� ������ : 3
������� : a = 10 b = 20 c = 30
���� : A = 50 B = 60 C = 70

������������� ����������� :
������������
���������� ������ : 3
������� : a = 10 b = 20 c = 30
���� : A = 50 B = 60 C = 90

������������� ����������� :
����������
���������� ������ : 3
������� : a = 10 b = 20 c = 30
���� : A = 50 B = 40 C = 90

�������������� ����������� :
������������
���������� ������ : 3
������� : a = 10 b = 20 c = 10
���� : A = 50 B = 60 C = 50

�������������� ����������� :
����������
���������� ������ : 3
������� : a = 30 b = 30 c = 30
���� : A = 60 B = 60 C = 60

�������������� :
������������
���������� ������ : 4
������� : a = 10 b = 20 c = 30 d = 40
���� : A = 50 B = 60 C = 70 D = 80

������������� :
����������
���������� ������ : 4
������� : a = 10 b = 20 c = 10 d = 20
���� : A = 90 B = 90 C = 90 D = 90

������� :
����������
���������� ������ : 4
������� : a = 20 b = 20 c = 20 d = 20
���� : A = 90 B = 90 C = 90 D = 90

�������������� :
������������
���������� ������ : 4
������� : a = 20 b = 30 c = 20 d = 30
���� : A = 30 B = 40 C = 30 D = 40

���� :
������������
���������� ������ : 4
������� : a = 30 b = 30 c = 30 d = 30
���� : A = 30 B = 40 C = 30 D = 40
*/