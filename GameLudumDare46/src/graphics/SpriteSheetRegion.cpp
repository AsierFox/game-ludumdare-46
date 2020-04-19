#include "SpriteSheetRegion.h"

SpriteSheetRegion::SpriteSheetRegion(std::string textureId, std::string resourcePath, int col, int row, int totalCols, int totalRows)
	: SpriteSheetRegion(textureId, resourcePath, col, row, totalCols, totalRows, 1, SDL_FLIP_NONE)
{
}

SpriteSheetRegion::SpriteSheetRegion(std::string textureId, std::string resourcePath, int col, int row, int totalCols, int totalRows, float scale)
	: SpriteSheetRegion(textureId, resourcePath, col, row, totalCols, totalRows, scale, SDL_FLIP_NONE)
{
}

SpriteSheetRegion::SpriteSheetRegion(std::string textureId, std::string resourcePath, int col, int row, int totalCols, int totalRows, float scale, SDL_RendererFlip flip)
	: BaseSprite(textureId, resourcePath)
{
	this->m_col = col - 1;
	this->m_row = row - 1;
	this->m_totalCols = totalCols;
	this->m_totalRows = totalRows;
	this->m_scale = scale;

	int textureWidth = 0;
	int textureHeight = 0;
	TextureManager::getInstance()->queryWidthAndHeight(textureId, &textureWidth, &textureHeight);

	this->m_frameWidth = textureWidth / this->m_totalCols;
	this->m_frameHeight = textureHeight  / this->m_totalRows;

	this->m_flip = flip;
}

void SpriteSheetRegion::render(float x, float y)
{
	TextureManager::getInstance()->renderFrame(this->getTextureId(), x, y, this->m_frameWidth, this->m_frameHeight, this->getWidth(), this->getHeight(), this->m_col, this->m_row, this->m_flip);
}

void SpriteSheetRegion::renderFixed(float x, float y)
{
	TextureManager::getInstance()->renderFrameFixed(this->getTextureId(), x, y, this->m_frameWidth, this->m_frameHeight, this->getWidth(), this->getHeight(), this->m_col, this->m_row, this->m_flip);
}

void SpriteSheetRegion::dispose()
{
	TextureManager::getInstance()->destroy(this->getTextureId());
}

float SpriteSheetRegion::getWidth()
{
	return this->m_frameWidth * this->m_scale;
}

float SpriteSheetRegion::getHeight()
{
	return this->m_frameHeight * this->m_scale;
}

int SpriteSheetRegion::getCol()
{
	return this->m_col + 1;
}

void SpriteSheetRegion::updateCol(int newCol)
{
	this->m_col = newCol - 1;
}

int SpriteSheetRegion::getRow()
{
	return this->m_row + 1;
}

void SpriteSheetRegion::updateRow(int newRow)
{
	this->m_row = newRow - 1;
}
