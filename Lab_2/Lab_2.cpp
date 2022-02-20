#include <iostream>
#include <string>

using namespace std;

void machine(int p[], int q[], int r[]) {

	int result_xnor = 0;
	int result_and = 0;
	int result_implication = 0;

	int result_xnor_implication = 0;
	int p_implication = 0;
	int q_implication = 0;

	cout << "p---q---r---(p~q)---(p^r)---(p~q)->(p^r)" << endl;

	for (int i = 0; i < 8; i++) {
		//-------(p~q)-------

		//XNOR(Equivalence)(⟷)(~)

		if (p[i] == q[i]) {
			result_xnor = 1;
		}
		else {
			result_xnor = 0;
		}

		//-------(p^r)-------

		//AND(Conjunction)(∧)

		if (p[i] == r[i] && p[i] == 1) {
			result_and = 1;
		}
		else {
			result_and = 0;
		}

		//-------(p~q)->(p^r)-------

		//NOTOR(Implication)(→)

		if (result_xnor == 0) {
			result_xnor_implication = 1;
		}
		else {
			result_xnor_implication = 0;
		}

		if (result_xnor_implication == result_and && result_xnor_implication == 0) {
			result_implication = 0;
		}
		else {
			result_implication = 1;
		}

		cout << "" << p[i] << " | " << q[i] << " | " << r[i] << " |   " << result_xnor << "   |   " << result_and << "   |      " << result_implication << endl;
	}
}

int main()
{
	int p[8] = { 0,0,0,0,1,1,1,1 };
	int q[8] = { 0,0,1,1,0,0,1,1 };
	int r[8] = { 0,1,0,1,0,1,0,1 };

	machine(p, q, r);

}
