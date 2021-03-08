#include <iostream>

class Figure 
{
public:
    virtual void S() = 0;
    virtual void P() = 0;
    virtual int GetAngles() = 0;
    virtual int GetPerimetr() = 0;
    virtual int GetSquare() = 0;
protected:
    int a = 0;
    int b = 0;
    int s = 0;
    int p = 0;
    int angles = 0;
};

class Square : public Figure
{
public:
    Square() {}
    Square(int a);
    int GetAngles() override;
    int GetPerimetr() override;
    int GetSquare() override;
    void S() override;
    void P() override;
};

class Rect : public Square
{
public:
    Rect(){}
    Rect(int a, int b);
};

class Triangle : public Rect
{
public:
    Triangle(){}
    Triangle(int a, int b, int c);
    void S() override;
    void P() override;
private:
    int c = 0;
};

class Circle : public Triangle
{
public:
    Circle(){}
    Circle(int a) :r(a){}
    void S() override;
    void P() override;
private:
    int r;
};

class Ellipse : public Circle
{
public:
    Ellipse(){}
    Ellipse(int a, int b);
    void S() override;
    void P() override;

};


Square::Square(int a)
{
    this->a = a;
    this->b = a;
    this->angles = 4;
}

void Square::S()
{
    this->s = a * b;
}

void Square::P()
{
    this->p = (a + b) * 2;
}

int Square::GetAngles()
{
    return this->angles;
}

int Square::GetPerimetr()
{
    return this->p;
}

int Square::GetSquare()
{
    return this->s;
}

Rect::Rect(int a, int b)
{
    this->a = a;
    this->b = b;
}

Triangle::Triangle(int a, int b, int c)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->angles = 3;
}

void Triangle::S()
{
    auto pp = (a + b + c) / 2;
    this->s = std::sqrt(pp*(pp - a)*(pp - b)*(pp - c));
}

void Triangle::P()
{
    this->p = a + b + c;
}

void Circle::S()
{
    this->s = 3, 14 * r * r;
}

void Circle::P()
{
    this->p = 2 * 3, 14 * r;
}

Ellipse::Ellipse(int a, int b)
{
    this->a = a;
    this->b = b;
}

void Ellipse::S()
{
    this->s = 3, 14 * a * b;
}

void Ellipse::P()
{
    this->p = std::sqrt((a * a + b * b) / 2) * 2 * 3, 14;
}

void angles_amount(Figure* p) 
{
    std::cout << p->GetAngles() << std::endl;
}
void perimetr(Figure* p)
{
    std::cout << p->GetPerimetr() << std::endl;
}
void square(Figure* p)
{
    std::cout << p->GetSquare() << std::endl;
}
int main()
{

    Rect a(5, 4);
    a.S();


}