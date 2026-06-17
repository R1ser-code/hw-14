#include <iostream>
#include <string>

class Figure
{
protected:
    std::string name;
    int sides_count;

public:
    Figure() : name("Figure"), sides_count(0) {}

    virtual bool check() const
    {
        return sides_count == 0;
    }

    virtual void print_info() const
    {
        std::cout << name << ":\n";
        std::cout << (check() ? "Correct" : "Incorrect") << std::endl;
        std::cout << "Sides count: " << sides_count << "\n\n";
    }

    virtual ~Figure() = default;
};

class Triangle : public Figure
{
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(std::string name,
        int a, int b, int c,
        int A, int B, int C)
        : a(a), b(b), c(c), A(A), B(B), C(C)
    {
        this->name = name;
        sides_count = 3;
    }

    bool check() const override
    {
        return sides_count == 3 &&
            (A + B + C == 180);
    }

    void print_info() const override
    {
        std::cout << name << ":\n";
        std::cout << (check() ? "Correct" : "Incorrect") << std::endl;
        std::cout << "Sides count: " << sides_count << std::endl;

        std::cout << "Sides: a=" << a
            << " b=" << b
            << " c=" << c << std::endl;

        std::cout << "Angles: A=" << A
            << " B=" << B
            << " C=" << C << "\n\n";
    }
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(int a, int b, int c,
        int A, int B, int C)
        : Triangle("Right triangle",
            a, b, c, A, B, C) {
    }

    bool check() const override
    {
        return Triangle::check() &&
            C == 90;
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int a, int b, int c,
        int A, int B, int C)
        : Triangle("Isosceles triangle",
            a, b, c, A, B, C) {
    }

    bool check() const override
    {
        return Triangle::check() &&
            a == c &&
            A == C;
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(int a, int b, int c,
        int A, int B, int C)
        : Triangle("Equilateral triangle",
            a, b, c, A, B, C) {
    }

    bool check() const override
    {
        return Triangle::check() &&
            a == b &&
            b == c &&
            A == 60 &&
            B == 60 &&
            C == 60;
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
        : a(a), b(b), c(c), d(d),
        A(A), B(B), C(C), D(D)
    {
        this->name = name;
        sides_count = 4;
    }

    bool check() const override
    {
        return sides_count == 4 &&
            (A + B + C + D == 360);
    }

    void print_info() const override
    {
        std::cout << name << ":\n";
        std::cout << (check() ? "Correct" : "Incorrect") << std::endl;
        std::cout << "Sides count: " << sides_count << std::endl;

        std::cout << "Sides: a=" << a
            << " b=" << b
            << " c=" << c
            << " d=" << d << std::endl;

        std::cout << "Angles: A=" << A
            << " B=" << B
            << " C=" << C
            << " D=" << D << "\n\n";
    }
};

class Rectangle : public Quadrangle
{
public:
    Rectangle(int a, int b, int c, int d,
        int A, int B, int C, int D)
        : Quadrangle("Rectangle",
            a, b, c, d,
            A, B, C, D) {
    }

    bool check() const override
    {
        return Quadrangle::check() &&
            a == c &&
            b == d &&
            A == 90 &&
            B == 90 &&
            C == 90 &&
            D == 90;
    }
};

class Square : public Quadrangle
{
public:
    Square(int a, int b, int c, int d,
        int A, int B, int C, int D)
        : Quadrangle("Square",
            a, b, c, d,
            A, B, C, D) {
    }

    bool check() const override
    {
        return Quadrangle::check() &&
            a == b &&
            b == c &&
            c == d &&
            A == 90 &&
            B == 90 &&
            C == 90 &&
            D == 90;
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a, int b, int c, int d,
        int A, int B, int C, int D)
        : Quadrangle("Parallelogram",
            a, b, c, d,
            A, B, C, D) {
    }

    bool check() const override
    {
        return Quadrangle::check() &&
            a == c &&
            b == d &&
            A == C &&
            B == D;
    }
};

class Rhombus : public Quadrangle
{
public:
    Rhombus(int a, int b, int c, int d,
        int A, int B, int C, int D)
        : Quadrangle("Rhombus",
            a, b, c, d,
            A, B, C, D) {
    }

    bool check() const override
    {
        return Quadrangle::check() &&
            a == b &&
            b == c &&
            c == d &&
            A == C &&
            B == D;
    }
};

void print_info(Figure* figure)
{
    figure->print_info();
}

int main()
{
    Figure figure;

    Triangle triangle(
        "Triangle",
        10, 20, 30,
        50, 60, 70);

    RightTriangle right_triangle1(
        10, 20, 30,
        50, 60, 90);

    RightTriangle right_triangle2(
        10, 20, 30,
        50, 40, 90);

    IsoscelesTriangle isosceles_triangle(
        10, 20, 10,
        50, 60, 50);

    EquilateralTriangle equilateral_triangle(
        30, 30, 30,
        60, 60, 60);

    Quadrangle quadrangle(
        "Quadrangle",
        10, 20, 30, 40,
        50, 60, 70, 80);

    Rectangle rectangle(
        10, 20, 10, 20,
        90, 90, 90, 90);

    Square square(
        20, 20, 20, 20,
        90, 90, 90, 90);

    Parallelogram parallelogram(
        20, 30, 20, 30,
        30, 40, 30, 40);

    Rhombus rhombus(
        30, 30, 30, 30,
        30, 40, 30, 40);

    print_info(&figure);
    print_info(&triangle);
    print_info(&right_triangle1);
    print_info(&right_triangle2);
    print_info(&isosceles_triangle);
    print_info(&equilateral_triangle);
    print_info(&quadrangle);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return 0;
}