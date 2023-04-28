#ifndef OPPONENT_H_INCLUDED
#define OPPONENT_H_INCLUDED
#include <string>
using namespace std;
class Opponent
{
    private:
		string name;
		int age;
	public:

		Opponent(string, int);
		~Opponent();

		void setValues(string name, int age);
        string getName();
        int getAge();
        void printInfo(string name, int age);

};


#endif // OPPONENT_H_INCLUDED
