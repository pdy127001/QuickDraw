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
	
	UFUNCTION(BlueprintCallable)
	virtual void Attack();
	
	virtual void SetCrossVisibility(bool bVisible);
	
	UFUNCTION(BlueprintNativeEvent)
	void PlayAttackAnim();
	
	UFUNCTION(BlueprintNativeEvent)
	void Defeated();

public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* AttackPos;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPaperSpriteComponent* PaperSprite;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPaperSpriteComponent* Cross;
	
	bool bCanAttack;
};
