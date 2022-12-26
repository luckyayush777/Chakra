#include "particle.h"
#include<assert.h>
#include<math.h>
namespace Chakra {
	void Particle::Integrate(real duration)
	{
		if (inverseMass <= 0.0f)
			return;
		assert(duration > 0.0);
		position.addScaledVector(velocity, duration);
		Vector3	resultingAcc = acceleration;
		velocity.addScaledVector(resultingAcc, duration);
		velocity *= std::pow(damping, duration);
		ClearAccumulator();
	}

	void Particle::AddForce(const Vector3& force)
	{
		forceAccumulated += force;
	}


	//the zeroing each simulation step
	void Particle::ClearAccumulator()
	{
		forceAccumulated.clear();
	}
}
