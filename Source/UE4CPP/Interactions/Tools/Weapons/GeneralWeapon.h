// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Tool.h"
#include "../Interfaces/Reloadable.h"
#include "GeneralWeapon.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponHit, FHitResult, HitResult);
/**
 * 
 */
UCLASS(Blueprintable)
class UE4CPP_API AGeneralWeapon : public ATool, public IReloadable
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Muzzle socket
	UPROPERTY()
	UStaticMeshSocket* MuzzleSocket;

public:
	// Weapon has mesh and Muzzle Socket on it
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	bool bHasMuzzleSocket = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int32 MaxAmmo = 12;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int32 AmmoPerClip = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float Damage = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float ReloadDuration = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float Range = 1500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FName MuzzleSocketName = "Muzzle";

	// State
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int32 CurrentAmmo = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int32 CurrentAmmoInClip = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	bool bIsReloading = false;
	
	// Actions
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool CanFire() const;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void UseAmmo();

	UFUNCTION()
	FHitResult WeaponTrace();
	void WeaponTrace(FVector& HitLocation); // 🌸

	// Reloadable interface	
	virtual bool CanReload_Implementation() override;
	virtual void Reload_Implementation() override;

	// Delegates
	UPROPERTY(BlueprintAssignable, Category = "Weapon")
	FOnWeaponHit OnWeaponHit;

private:

	UFUNCTION()
	bool _CanReload() const;

	UFUNCTION()
	void _Reload();

};