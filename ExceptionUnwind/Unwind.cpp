#include <iostream>

using std::cout;

struct Base {
	Base() {
		cout << "Inside Base()\n";
		throw 1;
	}

private:
	int i_;
};

struct Member {
	Member(int i) : i_(i) {
		cout << "Inside Member()\n";
		throw 2;
	}

private:
	int i_;
};

struct Derived : Base {
	Derived(int) try : member_(55) { cout << "Inside try{}\n"; }
	catch (int) { cout << "Inside catch()\n"; }

private:
	Member member_;
};

int main() {
	Derived d(0);
	return 0;
}