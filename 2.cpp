#include <iostream>
#include <string>

class Figure
{
protected:
    std::string name;

public:
    Figure(std::string name) : name(name) {}

    std::string get_name() const
    {
        return name;
    }

    virtual int get_sides_count() const = 0;

    virtual void print() const = 0;

    virtual ~Figure() = default;
};

class Triangle : public Figure
{
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(std::string name, int a, int b, int c, int A, int B, int C)
        : Figure(name), a(a), b(b), c(c), A(A), B(B), C(C) {
    }

    int get_sides_count() const override
    {
        return 3;
    }

    void print() const override
    {
        std::cout << get_name() << ":\n";
        std::cout << "Sides: a=" << a
            << " b=" << b
            << " c=" << c << '\n';

        std::cout << "Angles: A=" << A
            << " B=" << B
            << " C=" << C << "\n\n";
    }
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle("Right triangle", a, b, c, A, B, 90) {
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle("Isosceles triangle", a, b, a, A, B, A) {
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(int side)
        : Triangle("Equilateral triangle",
            side, side, side,
            60, 60, 60) {
    }
};

class Quadrangle : public Figure
{
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrangle(std::string name,
        int a, int b, int c, int d,
        int A, int B, int C, int D)
        : Figure(name),
        a(a), b(b), c(c), d(d),
        A(A), B(B), C(C), D(D) {
    }

    int get_sides_count() const override
    {
        return 4;
    }

    void print() const override
    {
        std::cout << get_name() << ":\n";
        std::cout << "Sides: a=" << a
            << " b=" << b
            << " c=" << c
            << " d=" << d << '\n';

        std::cout << "Angles: A=" << A
            << " B=" << B
            << " C=" << C
            << " D=" << D << "\n\n";
    }
};

class Rectangle : public Quadrangle
{
public:
    Rectangle(int a, int b)
        : Quadrangle("Rectangle",
            a, b, a, b,
            90, 90, 90, 90) {
    }
};

class Square : public Rectangle
{
public:
    Square(int side)
        : Rectangle(side, side)
    {
        name = "Square";
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrangle("Parallelogram",
            a, b, a, b,
            A, B, A, B) {
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(int side, int A, int B)
        : Parallelogram(side, side, A, B)
    {
        name = "Rhombus";
    }
};

void print_info(Figure* figure)
{
    figure->print();
}

int main()
{
    Triangle triangle("Triangle",
        10, 20, 30,
        50, 60, 70);

    RightTriangle rightTriangle(
        10, 20, 30,
        50, 60);

    IsoscelesTriangle isoscelesTriangle(
        10, 20,
        50, 60);

    EquilateralTriangle equilateralTriangle(30);

    Quadrangle quadrangle(
        "Quadrangle",
        10, 20, 30, 40,
        50, 60, 70, 80);

    Rectangle rectangle(10, 20);

    Square square(20);

    Parallelogram parallelogram(
        20, 30,
        30, 40);

    Rhombus rhombus(
        30,
        30, 40);

    print_info(&triangle);
    print_info(&rightTriangle);
    print_info(&isoscelesTriangle);
    print_info(&equilateralTriangle);
    print_info(&quadrangle);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return 0;
}