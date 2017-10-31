#pragma once
#include <glm/glm.hpp>

namespace SP3D
{
	//Axis-aligned bounding box (AABB)
	class AABB final
	{
	public:
		//Builds AABB that contain unit sphere
		//Same result as AABB({-0.5, -0.5, -0.5}, {0.5, 0.5, 0.5})
		AABB();

		AABB(const AABB& o);

		//Builds AABB that contain points a and b
		AABB(const glm::vec3& a, const glm::vec3& b);

		//Compares two AABBs
		bool operator ==(const AABB& o) const;

		//Includes point to AABB volume
		void extend(const glm::vec3& point);

		///TODO: Write a description.
		///My English sucks as usual
		void extend(const AABB& o);

		//Get AABB's min point
		glm::vec3 get_min() const;

		//Get AABB's max point
		glm::vec3 get_max() const;

		//Get AABB's center
		glm::vec3 get_center() const;

		//Get AABB's diagonal
		glm::vec3 get_diagonal() const;

		//Get AABB's diagonal length
		float get_diagonal_length() const;
	private:
		glm::vec3 m_min; //min point
		glm::vec3 m_max; //max point
	};
};