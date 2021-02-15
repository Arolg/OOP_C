
#include <iostream>
#include <numeric>

class OrdinFract
{
public:
	OrdinFract();
	OrdinFract(int a);
	OrdinFract(int a, int b);
	OrdinFract(const OrdinFract& other);
	OrdinFract operator +(const OrdinFract& other);
	OrdinFract operator *(const OrdinFract& other);
	OrdinFract operator -(const OrdinFract& other);
	OrdinFract operator /(const OrdinFract& other);
	OrdinFract operator +(const int& other);
	OrdinFract operator *(const int& other);
	OrdinFract operator -(const int& other);
	OrdinFract operator /(const int& other);
	OrdinFract operator +=(const OrdinFract& other);
	OrdinFract operator -=(const OrdinFract& other);
	OrdinFract operator *=(const OrdinFract& other);
	OrdinFract operator /=(const OrdinFract& other);
	OrdinFract& operator =(const OrdinFract& other);
	operator double();
	
	int gcd(int a, int b) {
		auto x = a;
		auto y = b;
		while (a && b)
			if (a > b) a %= b;
			else b %= a;

		return (x * y) / (a + b);
	}
	int lcm(int a, int b) {
		return (a * b) / gcd(a, b);
	}
	friend std::ostream& operator <<(std::ostream& out, const OrdinFract& other);
	friend std::istream& operator >>(std::istream& in, OrdinFract& other);
	friend const OrdinFract operator-(const OrdinFract& other);

private:
	int a, b;
};

OrdinFract::OrdinFract() : a(0), b(1){}

OrdinFract::OrdinFract(int na) : a(na), b(1){}

OrdinFract::OrdinFract(int na, int nb) : a(na), b(nb){}

OrdinFract::OrdinFract(const OrdinFract& other) : a(other.a), b(other.b){}

OrdinFract OrdinFract::operator+(const OrdinFract& other)
{
	OrdinFract temp;
	int s = gcd(this->b, other.b);
	temp.a = this->a * s / this->b + other.a * s / other.b;
	temp.b = s;
	int l = lcm(temp.a, temp.b);
	temp.a = temp.a / l;
	temp.b = temp.b / l;
	if (temp.b < 1)
	{
		temp.b = -1 * temp.b;
		temp.a = -1 * temp.a;
	}
	return temp;
}

OrdinFract OrdinFract::operator*(const OrdinFract& other)
{
	OrdinFract temp;
	temp.a = this->a * other.a;
	temp.b = this->b * other.b;
	int l = lcm(temp.a, temp.b);
	temp.a = temp.a / l;
	temp.b = temp.b / l;
	if (temp.b < 1)
	{
		temp.b = -1 * temp.b;
		temp.a = -1 * temp.a;
	}
	return temp;

}

OrdinFract OrdinFract::operator-(const OrdinFract& other)
{
	OrdinFract temp;
	int s = gcd(this->b, other.b);
	temp.a = this->a * s / this->b - other.a * s / other.b;
	temp.b = s;
	int l = lcm(temp.a, temp.b);
	temp.a = temp.a / l;
	temp.b = temp.b / l;
	if (temp.b < 1)
	{
		temp.b = -1 * temp.b;
		temp.a = -1 * temp.a;
	}
	return temp;
}

OrdinFract OrdinFract::operator/(const OrdinFract& other)
{
	OrdinFract temp;
	temp.a = this->a * other.b;
	temp.b = this->b * other.a;
	int l = lcm(temp.a, temp.b);
	temp.a = temp.a / l;
	temp.b = temp.b / l;
	if (temp.b < 1)
	{
		temp.b = -1 * temp.b;
		temp.a = -1 * temp.a;
	}
	return temp;
}

OrdinFract OrdinFract::operator+(const int& other)
{
	OrdinFract temp;
	temp.a = this->a + other * this->b;
	temp.b = this->b;
	int l = lcm(temp.a, temp.b);
	temp.a = temp.a / l;
	temp.b = temp.b / l;
	if (temp.b < 1)
	{
		temp.b = -1 * temp.b;
		temp.a = -1 * temp.a;
	}
	return temp;
}

OrdinFract OrdinFract::operator*(const int& other)
{
	OrdinFract temp;
	temp.a = this->a * other;
	temp.b = this->b;
	int l = lcm(temp.a, temp.b);
	temp.a = temp.a / l;
	temp.b = temp.b / l;
	if (temp.b < 1)
	{
		temp.b = -1 * temp.b;
		temp.a = -1 * temp.a;
	}
	return temp;
}

OrdinFract OrdinFract::operator-(const int& other)
{
	OrdinFract temp;
	temp.a = this->a - other * this->b;
	temp.b = this->b;
	int l = lcm(temp.a, temp.b);
	temp.a = temp.a / l;
	temp.b = temp.b / l;
	if (temp.b < 1)
	{
		temp.b = -1 * temp.b;
		temp.a = -1 * temp.a;
	}
	return temp;
}

OrdinFract OrdinFract::operator/(const int& other)
{
	OrdinFract temp;
	temp.a = this->a;
	temp.b = this->b * other;
	int l = lcm(temp.a, temp.b);
	temp.a = temp.a / l;
	temp.b = temp.b / l;
	if (temp.b < 1)
	{
		temp.b = -1 * temp.b;
		temp.a = -1 * temp.a;
	}
	return temp;
}

OrdinFract OrdinFract::operator+=(const OrdinFract& other)
{
	int s = gcd(this->b, other.b);
	this->a = this->a * s / this->b + other.a * s / other.b;
	this->b = s;
	int l = lcm(this->a, this->b);
	this->a = this->a / l;
	this->b = this->b / l;
	if (this->b < 1)
	{
		this->b = -1 * this->b;
		this->a = -1 * this->a;
	}
	
	return *this;
}

OrdinFract OrdinFract::operator-=(const OrdinFract& other)
{
	int s = gcd(this->b, other.b);
	this->a = this->a * s / this->b - other.a * s / other.b;
	this->b = s;
	int l = lcm(this->a, this->b);
	this->a = this->a / l;
	this->b = this->b / l;
	if (this->b < 1)
	{
		this->b = -1 * this->b;
		this->a = -1 * this->a;
	}

	return *this;
}

OrdinFract OrdinFract::operator*=(const OrdinFract& other)
{
	this->a = this->a * other.a;
	this->b = this->b * other.b;
	int l = lcm(this->a, this->b);
	this->a = this->a / l;
	this->b = this->b / l;
	if (this->b < 1)
	{
		this->b = -1 * this->b;
		this->a = -1 * this->a;
	}

	return *this;
}

OrdinFract OrdinFract::operator/=(const OrdinFract& other)
{
	this->a = this->a  * other.b;
	this->b = this->b * other.a;
	int l = lcm(this->a, this->b);
	this->a = this->a / l;
	this->b = this->b / l;
	if (this->b < 1)
	{
		this->b = -1 * this->b;
		this->a = -1 * this->a;
	}

	return *this;
}

OrdinFract& OrdinFract::operator=(const OrdinFract& other)
{
	this->a = other.a;
	this->b = other.b;
	std::cerr << this << std::endl;
	return *this;
}

OrdinFract::operator double()
{
	return static_cast<double>(this->a / this->b);
}

std::ostream& operator<<(std::ostream& out, const OrdinFract& other)
{
	out << other.a << '/' << other.b;
	return out;
}

std::istream& operator>>(std::istream& in, OrdinFract& other)
{
	in >> other.a;
	in >> other.b;
	return in;
}

const OrdinFract operator-(const OrdinFract& other)
{
	OrdinFract temp;
	temp.a = -1 * other.a;
	temp.b = other.b;
	return temp;
}



int main()
{

	OrdinFract a;
	OrdinFract b;
	std::cin >> a >> b;
	a += b;
	OrdinFract c = a + b;
	std::cout << a;

}

