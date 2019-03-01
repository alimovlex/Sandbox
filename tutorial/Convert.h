#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <vector>
#include <numeric>
#include <algorithm>
#include <exception>
#include <type_traits>
#include <new>
using namespace std;
namespace templ
{
	template<class point>
	class Point
	{
	public:

		Point() {}
		Point(point x, point y) : px(x), py(y)
		{
			cout << "Point object constructor." << endl;
		}

		void printPoint()
		{
			cout << " X " << px << " Y " << py << endl;
		}

	private:
		point px;
		point py;

	};

	template<class derPoint>
	class Point3D : Point<derPoint> {
	public:
		Point3D(derPoint x, derPoint y, derPoint z) : px(x), py(y), pz(z) {
			cout << "Point3D object constructor." << endl;
		}

		void printPoint() {
			cout << " X " << px << " Y " << py << " Z " << pz << endl;
		}

	private:
		derPoint px;
		derPoint py;
		derPoint pz;

	};

}

namespace convert
{
	class explicitConversion
	{

	public:

		explicit explicitConversion(float floatin) : convertValue{ floatin } {};

		void printValue(const explicitConversion expC);

		float convertValue;
	};

	void explicitConversion::printValue(const explicitConversion expC)
	{
		cout << "The value of convertValue is : " << expC.convertValue << endl;
	}

	class Conversion
	{

	public:

		Conversion(float floatin) : convertValue{ floatin } {};

		void printValue(const Conversion expC);

		float convertValue;
	};

	void Conversion::printValue(const Conversion expC)
	{
		cout << "The value of convertValue is : " << expC.convertValue << endl;
	}

	class myClass {

	public:
		operator int();

		explicit operator double();

	};

}

void transformer();
void conv();