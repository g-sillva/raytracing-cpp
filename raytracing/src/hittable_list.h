#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

class hittable_list : public hittable {
    public:
        std::vector<std::shared_ptr<hittable> > objects;

        hittable_list() {}
        hittable_list(std::shared_ptr<hittable> object) { add(object); }

        void clear() { objects.clear(); }

        void add(std::shared_ptr<hittable> object) {
            objects.push_back(object);
        }

        bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const override {
            hit_record temp_rec;
            bool hit_anything = false;
            double closest_hit_distance = ray_tmax;

            for (const std::shared_ptr<hittable>& object : objects) {
                if (!object->hit(r, ray_tmin, ray_tmax, temp_rec)) continue;
                hit_anything = true;
                closest_hit_distance = temp_rec.t;
                rec = temp_rec;
            }

            return hit_anything;
        }
};

#endif