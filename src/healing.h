#pragma once

#include "Object.h"

namespace licf {
	class Healing : public Objects {
        virtual double weight() = 0;

        virtual double volume() = 0;

	};
}