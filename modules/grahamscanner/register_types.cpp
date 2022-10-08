#include "register_types.h"

#include "core/class_db.h"
#include "grahamscanner.hpp"

void register_grahamscanner_types(){
    ClassDB::register_class<GrahamScanner>();
}

void unregister_grahamscanner_types(){}
