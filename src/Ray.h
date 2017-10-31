#pragma once
#include <glm/glm.hpp>

namespace SP3D
{

	class AABB;

	struct Ray
	{
		Ray(glm::vec3 origin, glm::vec3 direction) :
			origin(origin), direction(glm::normalize(direction))
		{}

		//Checks intersection between Ray and AABB
		bool intersect(const AABB& aabb) const;

		glm::vec3 origin;
		glm::vec3 direction;
	};
};