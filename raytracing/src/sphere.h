#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
    public:
        sphere (const point3& center, double radius) : center(center), radius(fmax(0,radius)) {}

        bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const override {
            vec3 oc = center - r.origin(); // Vector from array origin to sphere center

            double a = r.direction().length_squared();
            double h = dot(r.direction(), oc);
            double c = oc.length_squared() - radius*radius;

            double discriminant = h*h - a*c;

            if (discriminant < 0) {
                return false;
            }

            double sqrtd = sqrt(discriminant);
            double root = (h - sqrtd) / a;

            if (root <= ray_tmin || root > ray_tmax) {
                root = (h + sqrtd) / a;
                if (root <= ray_tmin || root > ray_tmax) {
                    return false;
                }
            }

            rec.t = root;
            rec.p = r.at(root);
            rec.normal = (rec.p - center) / radius;
            
            return true;
        }

    private:
        point3 center;
        double radius;
};

#endif