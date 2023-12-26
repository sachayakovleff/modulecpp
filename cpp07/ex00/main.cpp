#include "whatever.hpp"

int main(void)
{
	//int a = 2;
	//int b = 3;
	//::swap(a, b);
	//std::cout << "a = " << a << ", b = " << b << std::endl;
	//std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	//std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	//std::string c = "chaine1";
	//std::string d = "chaine2";
	//::swap(c, d);
	//std::cout << "c = " << c << ", d = " << d << std::endl;
	//std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	//std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	//return 0;
	int i = max(1, 2);
	std::cout << i << std::endl;
	float f = min(1.0f, 2.0f);
	std::cout << f << std::endl;
	std::string s1 = "message1";
	std::string s2 = "message2";
	swap(s1, s2);
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}
