#ifndef _CFGPARSER_VECTOR_HPP_
#define _CFGPARSER_VECTOR_HPP_


struct Vec2
{
	Vec2() : x(0.0f), y(0.0f)
	{
	}
	
	Vec2(const float value) : x(value), y(value)
	{
	}
	
	Vec2(const float value_x, const float value_y) : x(value_x), y(value_y)
	{
	}
	
	float x, y;
};


struct Vec3
{
	Vec3() : x(0.0f), y(0.0f), z(0.0f)
	{
	}
	
	Vec3(const float value) : x(value), y(value), z(value)
	{
	}
	
	Vec3(const float value_x, const float value_y, const float value_z) : x(value_x), y(value_y), z(value_z)
	{
	}
	
	float x, y, z;
};


struct Vec4
{
	Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
	{
	}
	
	Vec4(const float value) : x(value), y(value), z(value), w(value)
	{
	}
	
	Vec4(const float value_x, const float value_y, const float value_z, const float value_w) : x(value_x), y(value_y), z(value_z), w(value_w)
	{
	}
	
	float x, y, z, w;
};


struct Vec2i
{
	Vec2i() : x(0), y(0)
	{
	}
	
	Vec2i(const int value) : x(value), y(value)
	{
	}
	
	Vec2i(const int value_x, const int value_y) : x(value_x), y(value_y)
	{
	}
	
	int x, y;
};


struct Vec3i
{
	Vec3i() : x(0), y(0), z(0)
	{
	}
	
	Vec3i(const int value) : x(value), y(value), z(value)
	{
	}
	
	Vec3i(const int value_x, const int value_y, const int value_z) : x(value_x), y(value_y), z(value_z)
	{
	}
	
	int x, y, z;
};


struct Vec4i
{
	Vec4i() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
	{
	}
	
	Vec4i(const int value) : x(value), y(value), z(value), w(value)
	{
	}
	
	Vec4i(const int value_x, const int value_y, const int value_z, const int value_w) : x(value_x), y(value_y), z(value_z), w(value_w)
	{
	}
	
	int x, y, z, w;
};


struct Vec2u
{
	Vec2u() : x(0u), y(0u)
	{
	}
	
	Vec2u(const unsigned int value) : x(value), y(value)
	{
	}
	
	Vec2u(const unsigned int value_x, const unsigned int value_y) : x(value_x), y(value_y)
	{
	}
	
	unsigned int x, y;
};


struct Vec3u
{
	Vec3u() : x(0u), y(0u), z(0u)
	{
	}
	
	Vec3u(const unsigned int value) : x(value), y(value), z(value)
	{
	}
	
	Vec3u(const unsigned int value_x, const unsigned int value_y, const unsigned int value_z) : x(value_x), y(value_y), z(value_z)
	{
	}
	
	unsigned int x, y, z;
};


struct Vec4u
{
	Vec4u() : x(0u), y(0u), z(0u), w(0u)
	{
	}
	
	Vec4u(const unsigned int value) : x(value), y(value), z(value), w(value)
	{
	}
	
	Vec4u(const unsigned int value_x, const unsigned int value_y, const unsigned int value_z, const unsigned int value_w) : x(value_x), y(value_y), z(value_z), w(value_w)
	{
	}
	
	unsigned int x, y, z, w;
};

#endif