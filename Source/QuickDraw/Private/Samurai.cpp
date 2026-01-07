#include "Samurai.h"
#include "Components/SceneComponent.h"
#include "PaperSpriteComponent.h"
#include "QD_GameModeBase.h"
#include "QD_Exclamation.h"
#include "Kismet/GameplayStatics.h"

ASamurai::ASamurai()
{
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);

	AttackPos=CreateDefaultSubobject<USceneComponent>(TEXT("AttackPos"));
	AttackPos->SetupAttachment(DefaultSceneRoot);
	
	PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSprite"));
	PaperSprite->SetupAttachment(DefaultSceneRoot);

	PaperSprite->SetRelativeLocation(FVector::ZeroVector);
	PaperSprite->SetRelativeRotation(FRotator::ZeroRotator);
	PaperSprite->SetRelativeScale3D(FVector(1.f));
	
	Cross = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Cross"));
	Cross->SetupAttachment(PaperSprite);
	
	Cross->SetRelativeScale3D(FVector(1.f));
	Cross->SetRelativeRotation(FRotator::ZeroRotator);
	Cross->SetRelativeLocation(FVector::ZeroVector);
	bCanAttack=true;
}

void ASamurai::BeginPlay()
{
	Super::BeginPlay();
	SetCrossVisibility(false);
}

void ASamurai::Attack()
{
	if (bCanAttack)
	{
		UE_LOG(LogTemp, Log, TEXT("C++ Attack"));
		AQD_GameModeBase* GM = GetWorld()->GetAuthGameMode<AQD_GameModeBase>();
		if (GM)
		{
			UE_LOG(LogTemp, Log, TEXT("GM"));
			if (GM->GamePhase==EGamePhase::Draw)
			{
				UE_LOG(LogTemp, Log, TEXT("Draw"));
				PlayAttackAnim();
				AQD_Exclamation* Exclamation =
				Cast<AQD_Exclamation>(
					UGameplayStatics::GetActorOfClass(
						GetWorld(),
						AQD_Exclamation::StaticClass()
					)
				);
				if (Exclamation)
				{
					Exclamation->SetPaperSpriteVisibility(false);
				}
			}
			else if (GM->GamePhase==EGamePhase::Wait)
			{
				UE_LOG(LogTemp, Log, TEXT("Wait"));
				SetCrossVisibility(true);
			}
			bCanAttack=false;
			GM->FinishGame();
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Not GM"));
		}
	}
}

void ASamurai::SetCrossVisibility(bool bVisible)
{
	Cross->SetVisibility(bVisible);
}

void ASamurai::PlayAttackAnim_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("PlayAttackAnim_Implementation"));
}

void ASamurai::Defeated_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("Defeated_Implementation"));
}

void ASamurai::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

