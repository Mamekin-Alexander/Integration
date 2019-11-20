#include <iostream>
#include <iomanip>
const double inf = 6.0;
typedef double default_type;
const default_type correct = sqrt(4 * atan(1));


default_type rectangle_left(int n)
{
	default_type x, res=0;
	default_type dx = 2 * inf / n;
	x = -inf;
	for (int i = 1; i <= n; i++)
	{
		res = res + exp(-x * x)*dx;
		x = x + dx;
	}
	return res;
}
default_type rectangle_right(int n)
{
	default_type x, res = 0;
	default_type dx = 2 * inf / n;
	x = -inf+dx;
	for (int i = 1; i <= n; i++)
	{
		res = res + exp(-x * x)*dx;
		x = x + dx;
	}
	return res;
}
default_type rectangle_mid(int n)
{
	default_type x, res = 0;
	default_type dx = 2 * inf / n;
	x = -inf;
	for (int i = 1; i <= n; i++)
	{
		res = res + exp(-((x+dx/2) * (x+dx/2)))*dx;
		x = x + dx;
	}
	return res;
}
void L_M_R_rect()
{
	int split_number = 6;
	std::cout << "--------------------------------------------------------------------" << '\n';
	std::cout << "Left vs middle vs right rectangles" << '\n';
	std::cout << "Split number: " << split_number<<", Direction: from left to right, All default_types - double" << '\n';
	std::cout << "     Left rectangle   " << std::setprecision(14)<< rectangle_left(split_number);
	std::cout << "   Difference:" << std::setprecision(11)<< abs(rectangle_left(split_number) - correct) << '\n';
	std::cout << "     Middle rectangle " << std::setprecision(14) << rectangle_mid(split_number);
	std::cout << "   Difference:" << std::setprecision(11) << abs(rectangle_mid(split_number) - correct) << '\n';
	std::cout << "     Right rectangle  " << std::setprecision(14) << rectangle_right(split_number);
	std::cout << "   Difference:" << std::setprecision(11) << abs(rectangle_right(split_number) - correct) << '\n';
	std::cout << "     Real value:      " << std::setprecision(14) <<correct<<'\n';
	std::cout << '\n' << '\n';

	split_number = 7;
	std::cout << "Split number: " << split_number << ", Direction: from left to right, All default_types - double" << '\n';
	std::cout << "     Left rectangle   " << std::setprecision(14) << rectangle_left(split_number);
	std::cout << "   Difference:" << std::setprecision(11) << abs(rectangle_left(split_number) - correct) << '\n';
	std::cout << "     Middle rectangle " << std::setprecision(14) << rectangle_mid(split_number);
	std::cout << "   Difference:" << std::setprecision(11) << abs(rectangle_mid(split_number) - correct) << '\n';
	std::cout << "     Right rectangle  " << std::setprecision(14) << rectangle_right(split_number);
	std::cout << "   Difference:" << std::setprecision(11) << abs(rectangle_right(split_number) - correct) << '\n';
	std::cout << "     Real value:      " << std::setprecision(14) << correct << '\n';


	std::cout << "Function is symmetrical, so there is no difference between right and left rectangles." << '\n';
	std::cout << "If number of splits is even, middle rectangles are better, if not - right/left." << '\n';
	std::cout<<"The more splits we made - the more accurate result we get." << '\n';
	std::cout << "--------------------------------------------------------------------" << '\n';
	return;
}
template <typename T>
T trapeze(int n, T a)
{
	T dx = 2 * inf / n;
	T x = -inf;
	T res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = res + (exp(-x * x) + exp(-(x + dx)*(x + dx))) / 2 * dx;
		x = x + dx;
	}
	return res;
}
void trapeze_vs_rectangle()
{
	const int number_of_splits = 6;
	std::cout << "--------------------------------------------------------------------" << '\n';
	std::cout << "Trapeze vs rectangle" << '\n';
	std::cout << "Number of splits: " << number_of_splits << " Direction: from left to right "<<"All default types- double" << '\n';
	std::cout << "     Rectangle:   " << std::setprecision(14)<<rectangle_mid(number_of_splits);
	std::cout << "     Difference  " << std::setprecision(10) << abs(rectangle_mid(number_of_splits) - correct) << '\n';
	std::cout << "     Trapeze:     " << std::setprecision(14) << trapeze(number_of_splits, (default_type)5.0);
	std::cout << "     Difference  " << std::setprecision(10) << abs(trapeze(number_of_splits, (default_type)5.0) - correct) << '\n';
	std::cout << "     Real value:  " << std::setprecision(14) << correct << '\n';
	std::cout << "We can see, that rectangle is better here." << '\n';
	std::cout << "It's so, because first derivative takes values from -0.78 to 0.78, but the second from -2 to 0.89." << '\n';
	std::cout << "So in rectangle we have better aproximation, that is why the result is more accurate" << '\n';
	std::cout << "--------------------------------------------------------------------" << '\n';
	return;
}
default_type invert_trapeze(int n)
{
	default_type x = inf;
	default_type dx = 2 * inf / n;
	default_type res=0;
	for (int i = 1; i <= n; i++)
	{
		res = res + (exp(-(x - dx)*(x - dx)) + exp(-x * x)) / 2 * dx;
		x = x - dx;
	}
	return res;
}
void direction_of_integration()
{
	const int number_of_splits = 10;
	std::cout << "--------------------------------------------------------------------" << '\n';
	std::cout << "Direction of integration" << '\n';
	std::cout << "Number of splits: " << number_of_splits << " All default types- double" << " Used way of integraion - trapeze"<<'\n';
	std::cout << "     From left to right:   " << std::setprecision(14) << trapeze(number_of_splits, (default_type)5.0);
	std::cout << "     Difference  " << std::setprecision(10) << abs(trapeze(number_of_splits, (default_type)5.0) - correct) << '\n';
	std::cout << "     From right to left:   " << std::setprecision(14) << invert_trapeze(number_of_splits);
	std::cout << "     Difference  " << std::setprecision(10) << abs(invert_trapeze(number_of_splits) - correct) << '\n';
	std::cout << "     Real value:  " << std::setprecision(14) << correct << '\n';
	std::cout << "Function is symmetrical, so the result doesn't depend on direction of integration " << '\n';
	std::cout << "--------------------------------------------------------------------" << '\n';
	return;
}
void type_of_adder()
{
	const int number_of_splits = 110;
	std::cout << "--------------------------------------------------------------------" << '\n';
	std::cout << "Type of adder" << '\n';
	std::cout << "Number of splits: " << number_of_splits << " Direction: from left to right " << "Way of integration -trapeze" << '\n';
	std::cout << "     Float:      " << std::setprecision(8) << trapeze(number_of_splits,5.0f);
	std::cout << "           Difference  " << std::setprecision(8) << abs(trapeze(number_of_splits, 5.0f) - correct) << '\n';
	std::cout << "     Double:     " << std::setprecision(14) << trapeze(number_of_splits, (default_type)5.0);
	std::cout << "     Difference  " << std::setprecision(14) << abs(trapeze(number_of_splits, (default_type)5.0) - correct) << '\n';
	std::cout << "     Real value: " << std::setprecision(14) << correct << '\n';
	std::cout << "We can't get absolutly accurate value, becase we computer doesn't store data ablosolutly accurate." << '\n';
	std::cout << "The 'better' datatype we choose, the more accurate result we will get" << '\n';
	std::cout << "--------------------------------------------------------------------" << '\n';
	return;
}

int main()
{
	std::cout << "Infinity is set at " << inf << '\n';
	L_M_R_rect();
	trapeze_vs_rectangle();
	direction_of_integration();
	type_of_adder();
	return 0;
}