#pragma once
#include <glm/glm.hpp>

struct Ray
{
	Ray(glm::vec3 origin, glm::vec3 direction) :
		origin(origin), direction(glm::normalize(direction))
	{}

	glm::vec3 origin;
	glm::vec3 direction;
};