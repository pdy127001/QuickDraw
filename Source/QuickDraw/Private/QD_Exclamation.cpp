#include "QD_Exclamation.h"
#include "Components/SceneComponent.h"
#include "PaperSpriteComponent.h"

AQD_Exclamation::AQD_Exclamation()
{
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);
	PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSprite"));
	PaperSprite->SetupAttachment(DefaultSceneRoot);
	PaperSprite->SetRelativeLocation(FVector::ZeroVector);
	PaperSprite->SetRelativeRotation(FRotator::ZeroRotator);
	PaperSprite->SetRelativeScale3D(FVector(1.f));
}

void AQD_Exclamation::BeginPlay()
{
	Super::BeginPlay();
	SetPaperSpriteVisibility(false);
}

void AQD_Exclamation::SetPaperSpriteVisibility(bool bVisible)
{
	PaperSprite->SetVisibility(bVisible);
}



