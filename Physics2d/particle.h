#pragma once
#include"Chakra/core.h"
#include"Chakra/precision.h"
namespace Chakra {
	class Particle {
	protected:
		Vector3 velocity;
		Vector3 position;
		Vector3 acceleration;
		Vector3 forceAccumulated; //this is cumulative at each iteration so has to be zeroed every iteration step

		real damping;
		real inverseMass;

		void Integrate(real duration);
		void AddForce(const Vector3& force);
		void ClearAccumulator();
	};
}