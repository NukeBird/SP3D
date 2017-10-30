#include <gtest/gtest.h>
#include "../src/AABB.h"
#include <algorithm>

TEST(AABB, BuildFromTwoPoints) 
{
	glm::vec3 min(-1, -1, -1);
	glm::vec3 max( 1,  1,  1);

	SP3D::AABB aabb(min, max);

	EXPECT_EQ(aabb.get_min(), min);
	EXPECT_EQ(aabb.get_max(), max);
}

TEST(AABB, GetCenter)
{
	glm::vec3 a(-0.5, -0.5, -0.5);
	glm::vec3 b( 0.5,  0.5,  0.5);

	SP3D::AABB aabb(a, b);

	EXPECT_EQ(aabb.get_center(), glm::vec3(0.0, 0.0, 0.0));
}

TEST(AABB, GetDiagonalLengthByZeroSizedAABB)
{
	glm::vec3 zero(0.0, 0.0, 0.0);

	SP3D::AABB aabb(zero, zero);

	float diagonal_length = 0.0f;

	EXPECT_NO_THROW(diagonal_length = aabb.get_diagonal_length());
	EXPECT_EQ(diagonal_length, 0.0f);
}

TEST(AABB, GetDiagonal)
{
	SP3D::AABB aabb
	(
		glm::vec3(0.0, 0.0, 0.0),
		glm::vec3(6.0, 0.0, 0.0)
	);

	EXPECT_EQ(aabb.get_diagonal(), glm::vec3(6.0, 0.0, 0.0)); 

	glm::vec3 a(9.34, 0.43, 1);
	glm::vec3 b(5, 34, 25.6);

	aabb = SP3D::AABB(a, b);

	if (glm::min(a, b) == b)
		std::swap(a, b); //I'm too lazy :>
		
	EXPECT_EQ(aabb, SP3D::AABB(a, b));
	EXPECT_EQ(aabb.get_diagonal(), b - a);
}