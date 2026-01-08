#include "QD_GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "QD_Exclamation.h"
AQD_GameModeBase::AQD_GameModeBase()
{
	GameStartTime=1.0f;
	GamePhase=EGamePhase::Intro;
}

void AQD_GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(
	RoundStartTimerHandle,
	this,
	&AQD_GameModeBase::StartGame,
	GameStartTime,
	false
	);
}

void AQD_GameModeBase::StartGame()
{
	SetGamePhase(EGamePhase::Wait);
	float DelayTime=FMath::RandRange(2.f, 5.f);
	GetWorld()->GetTimerManager().SetTimer(
		DrawTimerHandle,
		this,
		&AQD_GameModeBase::DrawGame,
		DelayTime,
		false
		);
}

void AQD_GameModeBase::DrawGame()
{
	SetGamePhase(EGamePhase::Draw);
	AQD_Exclamation* Exclamation =
	Cast<AQD_Exclamation>(
		UGameplayStatics::GetActorOfClass(
			GetWorld(),
			AQD_Exclamation::StaticClass()
		)
	);
	if (Exclamation)
	{
		Exclamation->SetPaperSpriteVisibility(true);
	}
	AttackAI();
}

void AQD_GameModeBase::FinishGame()
{
	SetGamePhase(EGamePhase::Finished);
	GetWorld()->GetTimerManager().SetTimer(
		ResetTimerHandle,
		this,
		&AQD_GameModeBase::ResetGame,
		2.0f,
		false
		);
}

void AQD_GameModeBase::ResetGame()
{
	SetGamePhase(EGamePhase::Intro);
	ResetSamurai();
	GetWorld()->GetTimerManager().SetTimer(
	RoundStartTimerHandle,
	this,
	&AQD_GameModeBase::StartGame,
	GameStartTime,
	false
	);
}

void AQD_GameModeBase::ResetSamurai_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("ResetSamurai_Implementation"));
}

void AQD_GameModeBase::AttackAI_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("AttackAI_Implementation"));
}

void AQD_GameModeBase::SetGamePhase(EGamePhase Phase)
{
	GamePhase=Phase;
	const FString PhaseStr = UEnum::GetValueAsString(Phase);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,       
			2.0f,             
			FColor::Cyan,   
			PhaseStr
		);
	}
}
