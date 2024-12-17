#include <iostream>
#include <cmath>
#include <thread>
using namespace std;

class REACTOR
{
private:
	//CONFIG
	const double AMBIENT_TEMP = 23;
	const double AMBIENT_TEMP_MIN = 21;
	const double AMBIENT_TEMP_MAX = 25;
	//DATA
	double ambientTemp = AMBIENT_TEMP;
	//ITEMS
	class PLASMA_INJECTOR
	{
	private:
		const double PLASMA_TEMP = 645;
		const double PLASMA_TEMP_RANGE = 14;

	public:
		//
	};
public:
	void setAmbient(double num)
	{
		ambientTemp = num;
	}

};


int main()
{
	
}