// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "DrawDebugHelpers.h"
#include "Engine/StaticMeshSocket.h"


void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	// Get weapon mesh and add muzzle socket to it
	UStaticMesh* StaticMesh = Mesh->GetStaticMesh();

	if(StaticMesh)
	{
		MuzzleSocket = NewObject<UStaticMeshSocket>(StaticMesh);

		// defining Muzzle socket
		MuzzleSocket->SocketName = MuzzleSocketName;
		MuzzleSocket->RelativeLocation = FVector(10, 0, 0);
		MuzzleSocket->RelativeRotation = FRotator(0, 0, 0);

		// creating Muzzle socket
		StaticMesh->AddSocket(MuzzleSocket);

		// Muzzle Socket is created
		bHasMuzzleSocket = true;
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Weapon doesn't have visual representation. Defining as a virtual weapon."));
	}
}

void AWeapon::Fire()
{
	FHitResult HitResult;
	FVector StartLocation;
	FVector EndLocation;

	if(bHasMuzzleSocket)
	{
		StartLocation = Mesh->GetSocketLocation(MuzzleSocketName);
		EndLocation = StartLocation + (Mesh->GetSocketRotation(MuzzleSocketName).Vector() * Range);	
	}
	else
	{
		StartLocation = GetActorLocation();
		EndLocation = StartLocation + (GetActorRotation().Vector() * Range);
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Firing"));
	GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility);

	if(bIsDebug)
	{
		DrawDebugSphere(GetWorld(), StartLocation, 11, 10, FColor::Blue, false, 25.0f);
		DrawDebugSphere(GetWorld(), EndLocation, 11, 10, FColor::Green, false, 25.0f);
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Orange, false, 25.0f);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 11, 10, FColor::Red, true, 25.0f);
	}
}

void AWeapon::CanFire(bool& bCanFire) const
{
}

void AWeapon::CanReload(bool& bCanReload) const
{
}

void AWeapon::Reload()
{
}

void AWeapon::UseAmmo()
{
}

void AWeapon::WeaponTrace()
{
}

void AWeapon::WeaponTrace(FVector& HitLocation)
{
}