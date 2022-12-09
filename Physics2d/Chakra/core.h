#pragma once
#include<iostream>
namespace Chakra {
	class Vector3 {
	public :
		typedef float real;
		real x;
		real y;
		real z;

		Vector3() : x(0), y(0), z(0) { }
		Vector3(const real xValue, const real yValue, const real zValue)
		{
			x = xValue;
			y = yValue;
			z = zValue;
		}

		void InvertSign()
		{
			x = -x;
			y = -y;
			z = -z;
		}

		real Magnitude()
		{
			return sqrt(x * x + y * y + z * z);
		}

		real MagnitudeSquared()
		{
			return Magnitude() * Magnitude();
		}



	private :
		real padding; 





		
	};
}
