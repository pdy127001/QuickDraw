#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QD_Exclamation.generated.h"

class UPaperSpriteComponent;

UCLASS()
class QUICKDRAW_API AQD_Exclamation : public AActor
{
	GENERATED_BODY()
	
public:	
	AQD_Exclamation();

protected:
	virtual void BeginPlay() override;

public:
	void SetPaperSpriteVisibility(bool bVisible);
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPaperSpriteComponent* PaperSprite;
};
