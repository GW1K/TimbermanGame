#include "LoadObject.h"

LoadObject::LoadObject() : path("") {  }
LoadObject::LoadObject(std::string path) : path(std::move(path)) { }

void LoadObject::load(std::string path)
{
}
