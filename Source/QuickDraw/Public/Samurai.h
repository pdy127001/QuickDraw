#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Samurai.generated.h"

class UPaperSpriteComponent;

UCLASS()
class QUICKDRAW_API ASamurai : public APawn
{
	GENERATED_BODY()

public:
	ASamurai();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPaperSpriteComponent* PaperSprite;
};
