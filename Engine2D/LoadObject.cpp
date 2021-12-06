#include "LoadObject.h"

LoadObject::LoadObject() : path(""){}
LoadObject::LoadObject(std::string path) : path(std::move(path)) {}