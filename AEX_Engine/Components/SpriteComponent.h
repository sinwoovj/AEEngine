#pragma once
#include "BaseComponent.h"
#include "GraphicsComponent.h"
#include "AEEngine.h"
#include <string>

class SpriteComponent : public BaseComponent
{
public:
	struct Color
	{
		unsigned char r = 0;
		unsigned char g = 0;
		unsigned char b = 0;
	};
private:
	//mesh of points (quad)
	// All my objects have the same quad,
	// so I will NOT make it a member variable

	//text coords (UV)

	//color
	Color mColor;

	//texture
	AEGfxTexture* mTex = nullptr;

	//Render mode?
	//Blend mode?
	//Transparency?

public:
	SpriteComponent(GameObject* owner);
	~SpriteComponent();

	//Draw
	void Update() override;


	//Gettors/Settors
	Color& GetColor() { return mColor; }
	void SetTexture(const std::string& s);
	void SetTexture(AEGfxTexture* Tex);

	void LoadFromJson(const json& data) override {};
	json SaveToJson() override { return json{}; };
};