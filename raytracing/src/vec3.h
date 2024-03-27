#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

// Class to represent a 3D vector
class vec3 {
    public:

        // Data members storing the x, y, and z components of the vector
        double e[3];

        // Constructors
        vec3() {
            e[0] = 0;
            e[1] = 0;
            e[2] = 0;
        }
        vec3(double e0, double e1, double e2) {
            e[0] = e0;
            e[1] = e1;
            e[2] = e2;
        }

        // Accessors (getters)
        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        // Unary operator overload to negate the vector
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

        // Index operator overload to access the x, y, and z components
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        // Arithmetic operator overload to add two vectors
        vec3& operator+=(const vec3 &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        // Arithmetic operator overload to multiply two vectors
        vec3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        // Arithmetic operator overload to divide the vector by a scalar
        vec3& operator/=(double t) {
            return *this *= 1/t;
        }

        // Function to return the length of the vector
        double length() const {
            return std::sqrt(length_squared());
        }

        // Function to return the squared length of the vector
        double length_squared() const {
            return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
        }
};

// Alias for vec3
using point3 = vec3;

// ------ Vec3 utility functions ------

// Output operator overload to print the vector
inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
}

// Arithmetic operator overloads to add two vectors
inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// Arithmetic operator overloads to subtract two vectors
inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// Arithmetic operator overloads to multiply two vectors
inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// Arithmetic operator overloads to multiply a vector by a scalar
inline vec3 operator*(const vec3 &v, double t) {
    return v * t;
}

// Arithmetic operator overloads to divide a vector by a scalar
inline vec3 operator/(const vec3 &v, double t) {
    return v * (1/t);
}

// Calculate the dot product of two vectors
inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

// Calculate the cross product of two vectors
inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// Return a unit vector in the direction of the input vector
inline vec3 unit_vector(const vec3 &v) {
    return v / v.length();
}

#endif