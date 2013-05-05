#include "Scenary.h"
#include "Util.h"
#include "ProjectManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <QDir>

CProjectManager* CProjectManager::m_ProjectManager = 0;

CProjectManager::CProjectManager(void)
{
    activeFloor = 0;
}


CProjectManager::~CProjectManager(void)
{
}

CProjectManager* CProjectManager::getInstance()
{
    if(m_ProjectManager == NULL)
        m_ProjectManager = new CProjectManager();
    return m_ProjectManager;
}

bool CProjectManager::SaveMap(string fileName)
{
    CScenary * scenary = CScenary::getInstance();
    vector< vector<ModelInfo> > walls = scenary->getWalls();
    vector< vector<ModelInfo> > objects = scenary->getObjects();
    ofstream file;
    file.open(fileName.c_str());
    int totalFloors = walls.size();

    file << "# HouseDesigner project" << endl;
    file << "## Basic Info" << endl;
    file << "### Total floors" << endl;
    file << totalFloors << endl;
    file << "### Workspace dimension (X Z)" << endl;
    file << scenary->getGridMaxX() << " " << scenary->getGridMaxZ()<< endl;

    for(int currentFloor = 0; currentFloor < totalFloors; ++currentFloor)
    {
        file << "## Floor " << currentFloor << endl;
        file << "### Walls" << endl;
        for(int index = 0; index < walls[currentFloor].size(); ++index)
            file << getInfoFromObject(currentFloor, walls[currentFloor][index]) << endl;
        file << "### Objects" << endl;
        for(int index = 0; index < objects[currentFloor].size(); ++index)
            file << getInfoFromObject(currentFloor, objects[currentFloor][index]) << endl;
    }
    file.close();

    return false;
}

bool CProjectManager::LoadMap(string fileName)
{
    // Implementation of the read file function, need to read all the ModelInfo to the m_Info
    return false;
}

std::string CProjectManager::getInfoFromObject(int currentFloor, ModelInfo object)
{
    stringstream info;
    info << currentFloor << " ";
    info << object.position.x << " ";
    info << object.position.y << " ";
    info << object.position.z << " ";

    info << object.rotation.x << " ";
    info << object.rotation.y << " ";
    info << object.rotation.z << " ";

    info << object.scale.x << " ";
    info << object.scale.y << " ";
    info << object.scale.z << " ";

    int currentPathLength = QDir::currentPath().size();
    info << object.modelName.substr(currentPathLength) << " ";

    std::string texture = object.textureName.base;
    if(!texture.empty())
        texture = texture.substr(currentPathLength);
    info << texture << " ";

    info << object.type;

    return info.str();
}
