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

		real operator[](unsigned i) const
		{
			if (i == 0) return x;
			if (i == 1) return y;
			return z;
		}

		real& operator[](unsigned i)
		{
			if (i == 0) return x;
			if (i == 1) return y;
			return z;
		}

		void operator+=(const Vector3& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
		}

        Vector3 operator+(const Vector3 & v) const
        {
            return Vector3(x + v.x, y + v.y, z + v.z);
        }
        void operator-=(const Vector3& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
        }

        Vector3 operator-(const Vector3& v) const
        {
            return Vector3(x - v.x, y - v.y, z - v.z);
        }

        void operator*=(const real value)
        {
            x *= value;
            y *= value;
            z *= value;
        }


        Vector3 operator*(const real value) const
        {
            return Vector3(x * value, y * value, z * value);
        }


        Vector3 componentProduct(const Vector3& vector) const
        {
            return Vector3(x * vector.x, y * vector.y, z * vector.z);
        }


        void componentProductUpdate(const Vector3& vector)
        {
            x *= vector.x;
            y *= vector.y;
            z *= vector.z;
        }

        Vector3 vectorProduct(const Vector3& vector) const
        {
            return Vector3(y * vector.z - z * vector.y,
                z * vector.x - x * vector.z,
                x * vector.y - y * vector.x);
        }


        void operator %=(const Vector3& vector)
        {
            *this = vectorProduct(vector);
        }

        Vector3 operator%(const Vector3& vector) const
        {
            return Vector3(y * vector.z - z * vector.y,
                z * vector.x - x * vector.z,
                x * vector.y - y * vector.x);
        }

        real scalarProduct(const Vector3& vector) const
        {
            return x * vector.x + y * vector.y + z * vector.z;
        }

        real operator *(const Vector3& vector) const
        {
            return x * vector.x + y * vector.y + z * vector.z;
        }

        void addScaledVector(const Vector3& vector, real scale)
        {
            x += vector.x * scale;
            y += vector.y * scale;
            z += vector.z * scale;
        }

        real magnitude() const
        {
            return sqrt(x * x + y * y + z * z);
        }


        real squareMagnitude() const
        {
            return x * x + y * y + z * z;
        }

        void trim(real size)
        {
            if (squareMagnitude() > size * size)
            {
                normalize();
                x *= size;
                y *= size;
                z *= size;
            }
        }

        void normalize()
        {
            real l = magnitude();
            if (l > 0)
            {
                (*this) *= ((real)1) / l;
            }
        }

        Vector3 unit() const
        {
            Vector3 result = *this;
            result.normalize();
            return result;
        }


        bool operator==(const Vector3& other) const
        {
            return x == other.x &&
                y == other.y &&
                z == other.z;
        }

        bool operator!=(const Vector3& other) const
        {
            return !(*this == other);
        }

        bool operator<(const Vector3& other) const
        {
            return x < other.x&& y < other.y&& z < other.z;
        }


        bool operator>(const Vector3& other) const
        {
            return x > other.x && y > other.y && z > other.z;
        }
        bool operator<=(const Vector3& other) const
        {
            return x <= other.x && y <= other.y && z <= other.z;
        }

        bool operator>=(const Vector3& other) const
        {
            return x >= other.x && y >= other.y && z >= other.z;
        }

        /** Zero all the components of the vector. */
        void clear()
        {
            x = y = z = 0;
        }
		//debugging
		void Display()
		{
			std::cout << "\n"<<x << "i" << " + " << y << "j" << " + " << z << "k";
		}

        void makeOrthonormalBasis(Vector3* a, Vector3* b, Vector3* c)
        {
            a->normalize();
            *c = (*a) % (*b);
            //potential floating point issues
            if (c->squareMagnitude() == 0.0)
            {
                //temporary console output messages, better solution soon
                std::cout << "no cross product between two parallel vectors";

            }
            c->normalize();
            (*b) = (*c) % (*a);
        }

	private :
		real padding; 





		
	};
}
