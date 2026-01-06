#include "Samurai.h"
#include "Components/SceneComponent.h"
#include "PaperSpriteComponent.h"

ASamurai::ASamurai()
{
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);

	PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSprite"));
	PaperSprite->SetupAttachment(DefaultSceneRoot);

	PaperSprite->SetRelativeLocation(FVector::ZeroVector);
	PaperSprite->SetRelativeRotation(FRotator::ZeroRotator);
	PaperSprite->SetRelativeScale3D(FVector(1.f));
}

void ASamurai::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASamurai::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

