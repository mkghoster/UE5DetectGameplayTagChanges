// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "AsyncASCGameplayTagChange.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGameplayChanged, FGameplayTag, Tag, int32, NewCount);

/**
 * Blueprint node to listener to GameplayTags being added or removed.
 */
UCLASS(BlueprintType)
class UEASYNCNODEGT_API UAsyncASCGameplayTagChange : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
	FOnGameplayChanged OnGameplayTagChanged;

	// Listens for GameplayTags being added or removed.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAsyncASCGameplayTagChange* ListenForGameplayTagChange(UAbilitySystemComponent* AbilitySystemComponent);

protected:
	UPROPERTY()
	UAbilitySystemComponent* ASC;

	virtual void TagChanged(const FGameplayTag Tag, int32 NewCount);
};
