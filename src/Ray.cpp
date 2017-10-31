#include "Ray.h"
#include "AABB.h"

namespace SP3D
{
	bool Ray::intersect(const AABB& aabb) const
	{
		return aabb.intersect(*this);
	}
};