// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyPawnSubmarine.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
//#include "SceneComponent.generated.h"

// Sets default values
AMyPawnSubmarine::AMyPawnSubmarine()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = Root;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneComponent"));
	SubmarineMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SubmarineMesh"));
	SubmarineMesh->SetupAttachment(Root);
	Cam = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraSubmarine"));
	Cam->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AMyPawnSubmarine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawnSubmarine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Mesh
}

// Called to bind functionality to input
void AMyPawnSubmarine::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//PlayerInputComponent->BindAxis("MoveRight", this, &AMyPawnSubmarine::MoveVertically);
	//PlayerInputComponent->BindAxis("MoveRight", this, &AMyPawnSubmarine::MoveHorizontally);

}

void AMyPawnSubmarine::MoveHorizontally(float input)
{
	//RootComponent->AddForce
}

