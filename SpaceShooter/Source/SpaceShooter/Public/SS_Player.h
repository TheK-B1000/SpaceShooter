// Social Cube Media 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SS_Player.generated.h"

UCLASS()
class SPACESHOOTER_API ASS_Player : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASS_Player();

	USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditAnywhere)
	UParticleSystem* ParticleSystems;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
