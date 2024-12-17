#include <iostream>
#include <cmath>
#include <random>
using namespace std;

double randint(double min, double max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

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
		const double PLASMA_DENSITY = 3;//   3 grams/m3
		const double PLASMA_DENSTIY_RANGE = 0.1;
		double plasmaTemp = PLASMA_TEMP;
		double plasmaDensity = PLASMA_DENSITY;
	public:
		void setPlasmaTemp()
		{
			plasmaTemp = randint(PLASMA_TEMP - PLASMA_TEMP_RANGE, PLASMA_TEMP + PLASMA_TEMP_RANGE);
		}
		void setPlasmaDensity()
		{
			plasmaDensity = randint(PLASMA_DENSITY - PLASMA_DENSTIY_RANGE * 10, PLASMA_DENSITY + PLASMA_DENSTIY_RANGE * 10) / 10;
		}
	};
public:
	void setAmbient(double num)
	{
		ambientTemp = num;
	}

};

int main()
{
	REACTOR PCR_0;
}