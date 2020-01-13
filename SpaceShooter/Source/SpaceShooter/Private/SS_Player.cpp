// Social Cube Media 2020


#include "SS_Player.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/AudioComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASS_Player::ASS_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	ParticleSystems = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));
	ExplosionFX = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ExplosionFX"));
	DeathExplosionSound = CreateDefaultSubobject<UAudioComponent>(TEXT("DeathExplosionSound"));

	CollisionComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ShipMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ParticleSystems->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	DeathExplosionSound->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ExplosionFX->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	MaxVelocity = 250.0f;
	Current_X_Velocity = 0.0f;
	Current_Y_Velocity = 0.0f;

	bIsFiring = false;
	WeaponFireRate = 0.25f;
	TimeSinceLastShot = 0.0f;

	PlayerScore = 0.0f;


}

void ASS_Player::CollectablePickup()
{
}

// Called when the game starts or when spawned
void ASS_Player::BeginPlay()
{
	Super::BeginPlay();

	Current_Location = this->GetActorLocation();
	Current_Rotation = this->GetActorRotation();

	bHit = false;
	bDead = false;

	ExplosionFX->Deactivate();
	DeathExplosionSound->Deactivate();

	Max_Health = 100.0f;
	Current_Health = 100.0f;

	Max_Armor = 100.0f;
	Current_Armor = 100.0f;

	OnActorBeginOverlap.AddDynamic(this, &ASS_Player::OnBeginOverlap);

}

// Called every frame
void ASS_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Current_X_Velocity != 0.0f || Current_Y_Velocity != 0.0f)
	{
		New_Location = FVector(Current_Location.X + (Current_Y_Velocity * DeltaTime),
			Current_Location.Y + (Current_Y_Velocity * DeltaTime), 0);

		this->SetActorLocation(New_Location);

		Current_Location = New_Location;
	}
}

// Called to bind functionality to input
void ASS_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ASS_Player::MoveRight);
	PlayerInputComponent->BindAxis(FName("MoveUp"), this, &ASS_Player::MoveUp);
}

void ASS_Player::MoveRight(float AxisValue)
{
	Current_X_Velocity = MaxVelocity * AxisValue;
}

void ASS_Player::MoveUp(float AxisValue)
{
	Current_Y_Velocity = MaxVelocity * AxisValue;
}

void ASS_Player::FireWeapon()
{
}

void ASS_Player::StartFiring()
{
}

void ASS_Player::StopFiring()
{
}

void ASS_Player::OnBeginOverlap(AActor* PlayerActor, AActor* OtherActor)
{
}