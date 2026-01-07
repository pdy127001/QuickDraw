
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "QD_GameModeBase.generated.h"

UENUM(BlueprintType)
enum class EGamePhase : uint8
{
	Intro,
	Wait,
	Draw,
	Finished
};

class AQD_Exclamation;

UCLASS()
class QUICKDRAW_API AQD_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AQD_GameModeBase();
	
	virtual void BeginPlay() override;
	
	void StartGame();
	
	void DrawGame();
	
	void FinishGame();
	
	void SetGamePhase(EGamePhase Phase);
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game")
	float GameStartTime;
	
	FTimerHandle RoundStartTimerHandle;
	
	FTimerHandle DrawTimerHandle;
	
	EGamePhase GamePhase;
};
