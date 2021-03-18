#include "GraphCreationDonePresenter.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

void GraphCreationDonePresenter::present(const string& fileName) {
	cout << endl;
	cout << "===============================================================" << endl;
	cout << "      Graph created [" << fileName << "]" << endl;
	cout << "===============================================================" << endl;
}
