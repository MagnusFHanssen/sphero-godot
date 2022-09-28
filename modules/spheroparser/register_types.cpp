#include "register_types.h"

#include "core/class_db.h"
#include "spheroparser.hpp"

void register_spheroparser_types(){
    ClassDB::register_class<SpheroParser>();
}

void unregister_spheroparser_types(){}
