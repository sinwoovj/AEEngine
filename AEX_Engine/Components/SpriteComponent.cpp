#include "SpriteComponent.h"
#include "TransformComp.h"
#include "GameObject.h"


SpriteComponent::SpriteComponent(GameObject* owner) : BaseComponent(owner)
{
	mColor = Color{ 0, 0, 0 };
	AEGfxTexture* mTex = nullptr;
	ComponentManager<SpriteComponent>::GetManager()->AddComponent(this);
}

SpriteComponent::~SpriteComponent()
{
	ComponentManager<SpriteComponent>::GetManager()->RemoveComponent(this);
	AEGfxTextureUnload(mTex);
}

void SpriteComponent::Update()
{

	//Create quad
	AEGfxMeshStart();

	AEGfxTriAdd(
		-0.5f, -0.5f, 0xFFFFFFFF, 0.0f, 1.0f,
		0.5f, -0.5f, 0xFFFFFFFF, 1.0f, 1.0f,
		-0.5f, 0.5f, 0xFFFFFFFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		0.5f, -0.5f, 0xFFFFFFFF, 1.0f, 1.0f,
		0.5f, 0.5f, 0xFFFFFFFF, 1.0f, 0.0f,
		-0.5f, 0.5f, 0xFFFFFFFF, 0.0f, 0.0f);
	
	//Declare VertextList*
	AEGfxVertexList* mesh = AEGfxMeshEnd();

	//Set render mode
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	//Set color to multiply
	AEGfxSetColorToMultiply(1, 1, 1, 1.f);

	//Set color to add
	AEGfxSetColorToAdd(mColor.r / 255.f, mColor.g / 255.f, mColor.b / 255.f, 0.f);

	//Set blend Mode
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	//Set transparency
	AEGfxSetTransparency(1.0f);

	//Set texture
	AEGfxTextureSet(mTex, 0, 0);
	
	//Set transform
	//Get the transform from my owner transfrom comp
	AEMtx33 transf = own->FindComponent<TransformComp>()->GetMatrix();
	AEGfxSetTransform(transf.m);

	//call DrawMesh
	AEGfxMeshDraw(mesh, AE_GFX_MDM_TRIANGLES);

	
	AEGfxMeshFree(mesh);
}

void SpriteComponent::SetTexture(const std::string& s)
{
	if (mTex != nullptr)
		AEGfxTextureUnload(mTex);

	mTex = AEGfxTextureLoad(s.c_str());
}

void SpriteComponent::SetTexture(AEGfxTexture* Tex)
{
	if (mTex != nullptr)
		AEGfxTextureUnload(mTex);

	mTex = Tex;
}
