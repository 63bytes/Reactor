#include <iostream>
#include <cmath>
#include <thread>
using namespace std;

class REACTOR
{
private:
	const static int AMBIENT_TEMP = 20;

	double disipation;
	static double CALC_DISIPATION(double ob1, double ob2, double disipationFactor)
	{
		double disipation = ob1 * disipationFactor;
		if (ob2 < ob1)
		{
			ob2 += disipation;
		}
		if (ob2 > ob1)
		{
			ob2 = ob1;
		}
		return ob2;
	}

	class PLASMA_INJECTOR
	{
	private:
		const double FUEL_INPUT_SCALE_FACTOR = 0.01;
		const double TEMP_SCALE_FACTOR = 0.015;
		const int PLASMA_TEMP = 538;
	    double PLASMA_OUTPUT_DENSITY = 0;
		double DISIPATED = 0;
	public:
		int temp = 0;
		int fuelInput = 0;
		
		double plasmaOutput()
		{
			PLASMA_OUTPUT_DENSITY = (fuelInput * FUEL_INPUT_SCALE_FACTOR) * (temp * TEMP_SCALE_FACTOR);
			DISIPATED = CALC_DISIPATION(PLASMA_TEMP, (temp), 0.07);
			temp = DISIPATED;
			return PLASMA_OUTPUT_DENSITY;
		}
	};
	class FUSION_CORE
	{
	private:
		//
	public:
		double temp = AMBIENT_TEMP;
		double plasmaDensity = 0;
		double plasmaTemp = 0;
		int pv1, pv2, pv3, pv4 = 0; // plasma vents
		double calcPlasmaDensity()
		{
			plasmaDensity += pi1.plasmaOutput();
		}
	};
public:
	static PLASMA_INJECTOR pi1, pi2, pi3, pi4;
};


int main()
{
	REACTOR reac;
	reac.pi1.fuelInput = 100;
//	cout << reac.pi1.PLASMA_OUTPUT() << endl;
	while (true)
	{
		cout << "Plasma output:" << round(reac.pi1.plasmaOutput()*10)/10 << "   Temp:" << reac.pi1.temp << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
}