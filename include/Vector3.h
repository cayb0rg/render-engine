#ifndef INCLUDE_Vector3_H
#define INCLUDE_Vector3_H

class Vector3 {
    public: 
        // Constructor
        // Uses Member Initializer List
        Vector3(float x = 0, float y = 0, float z = 0): x(x), y(y), z(z) {};
        // Placing & after Vector3 is a type reference so we can use the '.' instead of '->'
        Vector3(const Vector3& vect): x(vect.x), y(vect.y), z(vect.z) {};
        // Operator overloading
        Vector3& operator=(const Vector3& vect);
        // '~' represents the destructor
        virtual ~Vector3();

        // Placing "const" after means the "this" pointer is const
        float length() const;

        static Vector3& add (
            const Vector3& left, 
            const Vector3& right, 
            Vector3& result
        );
        static Vector3& mul (
            const Vector3& left, 
            const Vector3& right, 
            Vector3& result
        );
        static Vector3& sub (
            const Vector3& left, 
            const Vector3& right, 
            Vector3& result
        );

        // Linear interpolation
        // Float 't' is in the range [0, 1] and
        // used to find a point some fraction of 
        // the way along a line between a & b
        static Vector3& lerp(const Vector3& a, const Vector3& b, float t, Vector3& result);

		Vector3& operator%=(const Vector3& right);
		Vector3& operator+=(const Vector3& right);
		Vector3& operator-=(const Vector3& right);
		Vector3 operator+(const Vector3& right);
		Vector3 operator-(const Vector3& right);
		Vector3 operator%(const Vector3& right);
		float operator*(const Vector3& b);

        // Returns the dot product between three vectors
        static float dot(
            const Vector3& left, 
            const Vector3& right
        );
        // Returns the distance between two vectors
        static float dist(
            const Vector3& left, 
            const Vector3& right
        );
        // Returns the angle between two vectors
        static float angle(
            const Vector3& left, 
            const Vector3& right
        );
        // Returns the vector that is perpendicular to two vectors
        // The magnitude (length) of the cross product equals the area of a parallelogram with vectors a and b for sides
        // Cross product is zero in length when vectors 'left' and 'right' are in the same or opposite directions
        // Maximum length when vectors are 90 degrees to each other
        static Vector3& cross(
            const Vector3& left, 
            const Vector3& right,
            Vector3& result
        );

        // Normalizes (gets a vector of length 1)
        Vector3 getNormalized(
            const Vector3& v
        );

        // Scales down this vector by 's'
        Vector3& scale(float s);
        // Normalizes this vector
        Vector3& normalize();

		void print() const;

        float x, y, z;
};

#endif