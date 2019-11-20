#include <iostream>
#include <iomanip>
const double inf = 6.0;
typedef double type;
const type correct = sqrt(4 * atan(1));

type rectangle_left(int n)
{
	type x, res=0;
	type dx = 2 * inf / n;
	x = -inf;
	for (int i = 1; i <= n; i++)
	{
		res = res + exp(-x * x)*dx;
		x = x + dx;
	}
	return res;
}
type rectangle_right(int n)
{
	type x, res = 0;
	type dx = 2 * inf / n;
	x = -inf+dx;
	for (int i = 1; i <= n; i++)
	{
		res = res + exp(-x * x)*dx;
		x = x + dx;
	}
	return res;
}
type rectangle_mid(int n)
{
	type x, res = 0;
	type dx = 2 * inf / n;
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
	std::cout << "Split number: " << split_number<<", Way: from left to right, All types - double" << '\n';
	std::cout << "     Left rectangle   " << std::setprecision(14)<< rectangle_left(split_number);
	std::cout << "   Difference:" << std::setprecision(11)<< abs(rectangle_left(split_number) - correct) << '\n';
	std::cout << "     Middle rectangle " << std::setprecision(14) << rectangle_mid(split_number);
	std::cout << "   Difference:" << std::setprecision(11) << abs(rectangle_mid(split_number) - correct) << '\n';
	std::cout << "     Right rectangle  " << std::setprecision(14) << rectangle_right(split_number);
	std::cout << "   Difference:" << std::setprecision(11) << abs(rectangle_right(split_number) - correct) << '\n';
	std::cout << "     Real value       " << std::setprecision(14) <<correct<<'\n';
	std::cout << '\n' << '\n';

	split_number = 7;
	std::cout << "Split number: " << split_number << ", Way: from left to right, All types - double" << '\n';
	std::cout << "     Left rectangle   " << std::setprecision(14) << rectangle_left(split_number);
	std::cout << "   Difference:" << std::setprecision(11) << abs(rectangle_left(split_number) - correct) << '\n';
	std::cout << "     Middle rectangle " << std::setprecision(14) << rectangle_mid(split_number);
	std::cout << "   Difference:" << std::setprecision(11) << abs(rectangle_mid(split_number) - correct) << '\n';
	std::cout << "     Right rectangle  " << std::setprecision(14) << rectangle_right(split_number);
	std::cout << "   Difference:" << std::setprecision(11) << abs(rectangle_right(split_number) - correct) << '\n';
	std::cout << "     Real value       " << std::setprecision(14) << correct << '\n';


	std::cout << "Function is symmetrical, so there is no difference between right and left rectangles." << '\n';
	std::cout << "If number of splits is even, middle rectangles are better, if not - right/left." << '\n';
	std::cout<<"The more splits we made - the more accurate result we get." << '\n';
	std::cout << "--------------------------------------------------------------------" << '\n';
	std::cout << '\n' << '\n' << '\n';
	return;
}
void R_L_W()
{

}
type trapeze(int n)
{
	type dx = 2 * inf / n;
}
void trapeze_vs_rectangle()
{
	const int number_of_splits = 10;
	std::cout << "--------------------------------------------------------------------" << '\n';
	std::cout << "Trapeze_vs_rectangle" << '\n';
	std::cout << "Number_of_splits: " << number_of_splits << " Way: from left to right "<<"All types- double" << '\n';
	std::cout << "     Rectangle: " << std::setprecision(14)<<rectangle_mid(number_of_splits);
	std::cout << "     Difference  " << std::setprecision(10) << abs(rectangle_mid(number_of_splits) - correct) << '\n';
}

int main()
{
	std::cout << "Infinity is set at " << inf << '\n';
	L_M_R_rect();
}