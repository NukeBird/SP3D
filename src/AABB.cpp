#include "AABB.h"

namespace SP3D
{
	AABB::AABB()
	{
		m_min = { -0.5, -0.5, -0.5 };
		m_max = {  0.5,  0.5,  0.5 };
	}

	AABB::AABB(const AABB& o)
	{
		m_min = o.m_min;
		m_max = o.m_max;
	}

	AABB::AABB(const glm::vec3& a, const glm::vec3& b)
	{
		m_min = glm::min(a, b);
		m_max = glm::max(a, b);
	}

	bool AABB::operator==(const AABB& o) const
	{
		return (m_min == o.m_min) && (m_max == o.m_max);
	}

	void AABB::extend(const glm::vec3& point)
	{
		m_min = glm::min(m_min, point);
		m_max = glm::max(m_max, point);
	}

	void AABB::extend(const AABB& o)
	{
		extend(o.m_min);
		extend(o.m_max);
	}

	void AABB::translate(const glm::vec3& v)
	{
		m_min += v;
		m_max += v;
	}

	bool AABB::intersect(const AABB& o) const
	{
		if ((m_max.x < o.m_min.x) || (m_min.x > o.m_max.x) ||
			(m_max.y < o.m_min.y) || (m_min.y > o.m_max.y) ||
			(m_max.z < o.m_min.z) || (m_min.z > o.m_max.z))
		{
			return false;
		}

		return true;
	}

	bool AABB::intersect(const Ray& r) const
	{
		glm::vec3 dirfrac(1.0f / r.direction);

		glm::vec3 m_max;

		float t1 = (m_min.x - r.origin.x)*dirfrac.x;
		float t2 = (m_max.x - r.origin.x)*dirfrac.x;
		float t3 = (m_min.y - r.origin.y)*dirfrac.y;
		float t4 = (m_max.y - r.origin.y)*dirfrac.y;
		float t5 = (m_min.z - r.origin.z)*dirfrac.z;
		float t6 = (m_max.z - r.origin.z)*dirfrac.z;

		using namespace glm;

		float t_min = max(max(min(t1, t2), min(t3, t4)), min(t5, t6));
		float t_max = min(min(max(t1, t2), max(t3, t4)), max(t5, t6));

		// if tmax < 0, ray (line) is intersecting AABB, but the whole AABB is behind us
		if (t_max < 0)
			return false;

		// if tmin > tmax, ray doesn't intersect AABB
		if (t_min > t_max)
			return false;

		return true;
	}

	glm::vec3 AABB::get_min() const
	{
		return m_min;
	}

	glm::vec3 AABB::get_max() const
	{
		return m_max;
	}

	glm::vec3 AABB::get_diagonal() const
	{
		return m_max - m_min;
	}

	float AABB::get_diagonal_length() const
	{
		return glm::length(get_diagonal());
	}

	glm::vec3 AABB::get_center() const
	{
		return (m_min + m_max) / 2.0f;
	}
};