#pragma once
/***********************
Quinn Schwab
16 / 08 / 2010

SFML Tiled Map Loader

The zlib license has been used to make this software fully compatible
with SFML.See http ://www.sfml-dev.org/license.php

This software is provided 'as-is', without any express or
implied warranty.In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions :

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.
*********************** /
/**
	Fonte: https://kychka-pc.ru/podderzhat-razvitie-proekta-sfml
	Codigo adaptado da fonte citada anteriormente.
 **/
#ifndef LEVEL_H
#define LEVEL_H

#include "assets/resources/tinyxml/tinyxml.h"
#include "Entidade.h"

	namespace Entidades {
		namespace Mapas {

			using sf::Rect;

			class Object {
			public:
				int GetPropertyInt(std::string name);
				float GetPropertyFloat(std::string name);
				std::string GetPropertyString(std::string name);
				std::string name;
				std::string type;
				sf::Rect <float> rect;
				std::map <std::string, std::string> properties;//All properties of the object. Values are stored as strings and mapped by strings(names provided in editor).
			};

			struct Layer {
				int opacity;
				std::vector <sf::Sprite> tiles;
			};

			class Mapa : public Entidade {
			private:
				// Attributes
				int             width, height, tileWidth, tileHeight, spacing, margin; //Width(tiles), height(tiles), tile width(pixels), tile height(pixels) of the map.
				int                     firstTileID; // Used to offset the tile number.

				RectangleShape          background;
				sf::FloatRect           drawingBounds; // Used to clip anything off screen.
				sf::Image               tilesetImage; // The tileset image.
				sf::Texture             tilesetTexture; // The tileset texture.

				std::vector<Rect<float>>  solidObjects;//This stores all the solid areas (objects with type 'solid'). This gets checked by the IsSolid function.
				std::vector <Object>    objects; //This stores all objects (including 'solid' types)
				std::vector <Layer>     layers; //This stores each layer of sprites/tiles so they can be drawn in order.

				string                  a_tilemap;
				string                  a_tileset;

				// Init Methods
				void initBackground();


			public:
				//   Constructor & Destructor
				Mapa(const string& a_tilemap = "", const string& a_tileset = "", Texture* texture = nullptr);
				virtual ~Mapa();

				// Methods (Entidade)
				void move(const sf::Vector2f& direction, const float& dt);
				void update(const float& dt);
				void render(RenderTarget* target);
				void reset();
				void setPosition(const Vector2f&);
				void setPosition(const float& x, const float& y);
				const Vector2f& getPosition() const;
				// Getters & Setters
				void setTexture(Texture* texture);
				const int getHeight() const;

				// TileMap Methods
				bool load();
				bool load(const string& a_tilemap, const string& a_tileset); //Loads the map. Returns false if it fails.
				Object GetObject(std::string name); //Returns the first object found with the given name. This is why we need unique names :)
				bool isSolidPixel(const Vector2f& pos);
				bool isSolidPixel(int x, int y); //Returns true if the given pixel is solid.
				//bool IsSolidTile(int x, int y); //Returns true if the given tile is solid. DO WE NEED THIS?
				//void Move(int xStep, int yStep); //Moves the map. Although I would recommend using a view instead in most cases.
				void SetDrawingBounds(sf::Rect<float> bounds); //Set the area to draw. This rect is usually provided directly from the view you are using.
			};

		}
	}
}
#endif // LEVEL_H