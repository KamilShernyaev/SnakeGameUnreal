// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnBase.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "SnakeBase.h"
#include "SnakeElementBase.h"
#include "Components/InputComponent.h"


// Sets default values
APlayerPawnBase::APlayerPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	RootComponent = PawnCamera;
}

// Called when the game starts or when spawned
void APlayerPawnBase::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(-90, 0, 0));
	GameMode = 0;
}

// Called every frame
void APlayerPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawnBase::HadlePlayerVerticalInput);
	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawnBase::HadlePlayerHorizontalInput);
}

void APlayerPawnBase::CreateSnakeActor()
{
	SnakeActor = GetWorld()->SpawnActor<ASnakeBase>(SnakeActorClass, FTransform());
	GameMode = 1;
}

void APlayerPawnBase::HadlePlayerVerticalInput(float value)
{
	if (IsValid(SnakeActor))
	{
		if (value > 0 && SnakeActor->LastMoveDirection!=EMovementDirection::DOWN && SnakeActor->ChangeDirection)
		{
			SnakeActor->LastMoveDirection = EMovementDirection::UP;
			SnakeActor->ChangeDirection = false;
		}
		if (value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::UP && SnakeActor->ChangeDirection)
		{
			SnakeActor->LastMoveDirection = EMovementDirection::DOWN;
			SnakeActor->ChangeDirection = false;
		}
	}
}

void APlayerPawnBase::HadlePlayerHorizontalInput(float value)
{
	if (IsValid(SnakeActor))
	{
		if (value > 0 && SnakeActor->LastMoveDirection != EMovementDirection::LEFT && SnakeActor->ChangeDirection)
		{
			SnakeActor->LastMoveDirection = EMovementDirection::RIGHT;
			SnakeActor->ChangeDirection = false;
		}
		if (value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::RIGHT && SnakeActor->ChangeDirection)
		{
			SnakeActor->LastMoveDirection = EMovementDirection::LEFT;
			SnakeActor->ChangeDirection = false;
		}
	}
}

int32 APlayerPawnBase::GetScore()
{
	if (IsValid(SnakeActor))
	{
		return SnakeActor->Score;
	}
	return 0;
}