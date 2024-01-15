#ifndef INCLUDE_VECTOR2_H
#define INCLUDE_VECTOR2_H

class Vector2 {
    public: 
        // Constructor
        // Uses Member Initializer List
        Vector2(float x = 0, float y = 0): x(x), y(y) {};
        // Placing & after Vector2 is a type reference so we can use the '.' instead of '->'
        Vector2(const Vector2& vect): x(vect.x), y(vect.y) {};
        // Operator overloading
        Vector2& operator=(const Vector2& vect);
        // '~' represents the destructor
        // 'virtual' means the inherited class can choose whether to implement it or not
        virtual ~Vector2();

        // Placing "const" after means the "this" pointer is const
        float length() const;

        static Vector2& add (
            const Vector2& left, 
            const Vector2& right, 
            Vector2& result
        );
        static Vector2& mul (
            const Vector2& left, 
            const Vector2& right, 
            Vector2& result
        );
        static Vector2& sub (
            const Vector2& left, 
            const Vector2& right, 
            Vector2& result
        );

        static Vector2& lerp(const Vector2& a, const Vector2& b, float t, Vector2& result);

		Vector2& operator+=(const Vector2& right);
		Vector2& operator-=(const Vector2& right);
		Vector2 operator+(const Vector2& right);
		Vector2 operator-(const Vector2& right);
		float operator*(const Vector2& b);

        // Returns the dot product between two vectors
        static float dot(
            const Vector2& left, 
            const Vector2& right
        );
        // Returns the distance between two vectors
        static float dist(
            const Vector2& left, 
            const Vector2& right
        );
        // Returns the angle between two vectors
        static float angle(
            const Vector2& left, 
            const Vector2& right
        );

        // Normalizes (gets a vector of length 1)
        static Vector2 getNormalized(
            const Vector2& v
        );

        // Scales down this vector by 's'
        Vector2& scale(float s);
        // Normalizes this vector
        Vector2& normalize();

		void print() const;

		float x, y;
};

#endif