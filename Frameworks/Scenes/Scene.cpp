#include "Scene.h"

const std::string& Scene::GatName() const {
    return this->m_name;
}

const std::string& Scene::GetDescription() const {
    return this->m_description;
}

Scene::Scene(const char*& _name, const char*& _description) : 
    m_name(_name), 
    m_description(_description) {
}

Scene::Scene(const std::string& _name, const std::string& _description) :
    m_name(_name),
    m_description(_description) {
}

