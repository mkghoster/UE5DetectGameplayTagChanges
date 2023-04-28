// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncASCGameplayTagChange.h"


UAsyncASCGameplayTagChange* UAsyncASCGameplayTagChange::ListenForGameplayTagChange(UAbilitySystemComponent * AbilitySystemComponent)
{
	UAsyncASCGameplayTagChange* ListenForGameplayTagChange = NewObject<UAsyncASCGameplayTagChange>();
	ListenForGameplayTagChange->ASC = AbilitySystemComponent;
	
	AbilitySystemComponent->RegisterGenericGameplayTagEvent()
		.AddUObject(ListenForGameplayTagChange, &UAsyncASCGameplayTagChange::TagChanged);

	return ListenForGameplayTagChange;
}

void UAsyncASCGameplayTagChange::TagChanged(const FGameplayTag Tag, int32 NewCount)
{
	OnGameplayTagChanged.Broadcast(Tag, NewCount);
}
