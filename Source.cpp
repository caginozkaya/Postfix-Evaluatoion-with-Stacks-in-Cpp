#include<iostream>
#include<cctype>
#include<stack>
#include <cmath>
#include <string>
using namespace std;


double eval(double op2, double op1, char operate) {
	//int isOdd = (int) pow(op1, -1) % 2;
	switch (operate) {
	case '*': return op2 * op1;
	case '/': return op2 / op1;
	case '+': return op2 + op1;
	case '-': return op2 - op1;
	case '^':/*if(op2 < 0 && isOdd == 1)
			 return -pow(-op2, op1);
			 else*/
		return pow(op2, op1);
	default: return 0;

	}
}



double evalPostfix(string postfix, int size) {
	stack<double> s;
	string digits;
	int i = 0, j = 0;
	char space[] = " ", minus[] = "@";
	double val,neg;
	bool t = false;
	


	while (i < size) {

		j = i;
		//
		if (isdigit(postfix[i])) {
			while ((postfix[j] != space[0]) && (j != size)) {

				digits.push_back(postfix[j]);
				j++;

			}

			s.push(stoi(digits));
			digits.clear();
			i = j + 1;

			



		}

		//
		else if (postfix[i] == minus[0]) {

			s.top() = s.top()*-1;
			i = j + 2;
		}


		else  {
		
			double op1 = s.top();
			s.pop();
			double op2 = s.top();
			s.pop();

			

			val = eval(op2, op1, postfix[i]);



			s.push(val);
			i = i + 2;
			t = true;
		}

	




	}

	

	val = s.top();

	return val;

}


int main() {

	string postfix;

	while (true) {
		cout << "Enter the postfix expression :";
		getline(cin, postfix);

		int size = postfix.size();
		double val = evalPostfix(postfix, size);

		cout << "Expression evaluates to " << val;
		cout << endl;
		
	}
	system("pause");
	return 0;


}