#include "TiledMapManager.h"

TiledMapManager* TiledMapManager::s_instance = nullptr;

TiledMapManager::TiledMapManager()
{
}

TiledMapManager* TiledMapManager::getInstance()
{
	if (nullptr == TiledMapManager::s_instance)
	{
		TiledMapManager::s_instance = new TiledMapManager;
	}
	return TiledMapManager::s_instance;
}

TiledMap* TiledMapManager::load(std::string mapId, std::string resourcesDirPath, std::string filename, float scale)
{
	if (this->isMapAlreadyLoaded(mapId))
	{
		spdlog::debug("[TiledMapManager::load] The map with id '{0}' is already created!", mapId);
		return this->getMap(mapId);
	}

	std::ifstream mapFile(resourcesDirPath + filename);
	nlohmann::json mapJson = nlohmann::json::parse(mapFile);

	int mapTileSize = mapJson["tilewidth"];
	int mapTileCols = mapJson["width"];
	int mapTileRows = mapJson["height"];

	std::vector<Tileset> mapTilesets;

	for (unsigned int i = 0; i < mapJson["tilesets"].size(); i++)
	{
		nlohmann::json tilesetJson = mapJson["tilesets"][i];
		Tileset tileset;

		int tileCount = tilesetJson["tilecount"];
		tileset.m_firstId = tilesetJson["firstgid"];
		tileset.m_lastId  = tileset.m_firstId + (tileCount - 1);
		tileset.m_name    = tilesetJson["name"].get<std::string>();
		tileset.m_tileSize = mapTileSize;
		tileset.m_totalTileSize = mapTileSize * scale;
		tileset.m_totalCols = tilesetJson["columns"];
		tileset.m_totalRows = tileCount / tileset.m_totalCols;
		tileset.m_resourcePath = resourcesDirPath + tilesetJson["image"].get<std::string>();

		mapTilesets.push_back(tileset);
	}

	std::vector<TileLayer*> mapTileLayers;
	std::vector<TiledObject> mapObjects;
	std::vector<MapSpawnPoint> mapSpawns;

	for (unsigned int i = 0; i < mapJson["layers"].size(); i++)
	{
		nlohmann::json layerJson = mapJson["layers"][i];

		if (std::string("tilelayer").compare(layerJson["type"].get<std::string>()) == 0)
		{
			std::vector<std::vector<int> > tileMapIds;
			std::vector<int> rowIds;

			for (unsigned int j = 0; j < layerJson["data"].size(); j++)
			{
				rowIds.push_back(layerJson["data"][j]);

				if ((j + 1) % mapTileCols == 0)
				{
					tileMapIds.push_back(rowIds);
					rowIds.clear();
				}
			}

			mapTileLayers.push_back(new TileLayer(tileMapIds, mapTilesets, scale));
			
			tileMapIds.clear();
		}

		else if (std::string("objectgroup").compare(layerJson["type"].get<std::string>()) == 0)
		{

			for (unsigned int j = 0; j < layerJson["objects"].size(); j++)
			{
				nlohmann::json objectJson = layerJson["objects"][j];

				if (!objectJson["point"].is_null() && objectJson["point"].get<bool>())
				{
					// Create map spawn point
					MapSpawnPoint spawnPoint;

					spawnPoint.point = Point(objectJson["x"] * scale, objectJson["y"] * scale);

					if (!objectJson["properties"].is_null())
					{
						for (int i = 0; i < objectJson["properties"].size(); i++)
						{
							nlohmann::json propertyJson = objectJson["properties"][i];
							MapSpawnProperty spawnProperty;

							spawnProperty.type = propertyJson["name"].get<std::string>();
							spawnProperty.value = propertyJson["value"].get<std::string>();

							spawnPoint.properties.push_back(spawnProperty);
						}
					}
					else
					{
						spdlog::critical("[TiledMapManager::load] No properties in a map point!");
					}

					mapSpawns.push_back(spawnPoint);
				}
				else
				{
					// Is rectable, so create collider
					TiledObject tiledObject;

					tiledObject.m_x = objectJson["x"];
					tiledObject.m_y = objectJson["y"];
					tiledObject.m_width = objectJson["width"];
					tiledObject.m_height = objectJson["height"];

					tiledObject.m_collider = {
						static_cast<int>(tiledObject.m_x * scale),
						static_cast<int>(tiledObject.m_y * scale),
						static_cast<int>(tiledObject.m_width * scale),
						static_cast<int>(tiledObject.m_height * scale) };

					mapObjects.push_back(tiledObject);
				}
			}
		}
	}

	TiledMap* tiledMap = new TiledMap(mapTileSize, mapTileCols, mapTileRows, mapTileLayers, new ObjectLayer(mapObjects, scale), mapSpawns, scale);
	this->m_maps.insert({ mapId, tiledMap });

	spdlog::debug("[TiledMapManager::load] The map with id '{0}' loaded successfully!", mapId);

	return tiledMap;
}

void TiledMapManager::dispose(std::string mapId)
{
	this->m_maps[mapId]->dispose();
	// TODO Test this
	delete this->m_maps[mapId];
}

TiledMap* TiledMapManager::getMap(std::string mapId)
{
	return this->m_maps[mapId];
}

bool TiledMapManager::isMapAlreadyLoaded(std::string mapId)
{
	return this->m_maps.count(mapId) > 0;
}
