#ifndef HITTABLE_H
#define HITTABLE_H

class hit_record {
    public:
        point3 p;           // The point on the surface of the object where the ray intersects
        vec3 normal;        // Normalized vector pointing away from the surface where the ray intersects
        double t;           // The distance from the ray source to the surface of the object
        bool front_face;    // Indicates whether the ray is inside (true) or outside (false) the object

        void set_face_normal(const ray& r, const vec3& outward_normal) {
            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        }
};

class hittable {
    public:
        virtual ~hittable() = default;

        virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif
