#include "StateParser.hpp"
#include "Game.hpp"
#include "GameObjectFactory.hpp"

bool StateParser::parseState(const char * stateFile, std::string stateID, std::vector<GameObject*>* pObjects, std::vector<std::string> *pTextureIDs) {
	// create XML document
	TiXmlDocument xmlDoc;

	// load the state file
	if (!xmlDoc.LoadFile(stateFile)) {
		std::cerr << xmlDoc.ErrorDesc() << "\n";
		return false;
	}

	// get root element
	TiXmlElement* pRoot = xmlDoc.RootElement();

	// pre declare the states root node
	TiXmlElement* pStateRoot = 0;

	// get this state root node and assign it to pStateRoot
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == stateID) {
			pStateRoot = e;
		}

	}

	// pre declare the texture root node
	TiXmlElement* pTextureRoot = 0;

	// get the root of the texture elements
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("TEXTURES")) {
			pTextureRoot = e;
		}
	}

	// parse the textures 
	parseTextures(pTextureRoot, pTextureIDs);

	// pre declare the object root node
	TiXmlElement* pObjectRoot = 0;

	// get the root node and assign it to pObjectRoot
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("OBJECTS")) {
			pObjectRoot = e;
		}
	}

	// parse the objects
	parseObjects(pObjectRoot, pObjects);

	return true;
}


void StateParser::parseTextures(TiXmlElement* pStateRoot, std::vector<std::string> *pTextureIDs) {
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		std::string filenameAttribute = e->Attribute("filename");
		std::string idAttribute = e->Attribute("ID");
		pTextureIDs->push_back(idAttribute);

		TheTextureManager::Instance()->load(filenameAttribute, idAttribute, TheGame::Instance()->getRenderer());
	}
}

void StateParser::parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*> *pObjects) {
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		int x, y, width, height, numFrames, callbackID, animSpeed;
		std::string textureID;

		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);
		e->Attribute("numFrames", &numFrames);
		e->Attribute("callbackID", &callbackID);
		e->Attribute("animSpeed", &animSpeed);

		textureID = e->Attribute("textureID");

		GameObject* pGameObject = TheGameObjectFactory::Instance()->create(e->Attribute("type"));

		pGameObject->load(new LoadParams(x, y, width, height, textureID, numFrames, callbackID, animSpeed));
		pObjects->push_back(pGameObject);

	}
}