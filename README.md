# UE5DetectGameplayTagChanges
Unreal Engine 5 - Detect Gameplay Tag changes on Actor

In this project you can find two approaches on how to detect Gameplay Tag changes on an Actor. Use each based on your needs.

## Solution 1: Basic Polling of Gameplay Tag changes
In this solution the Listener is polling if the Target Actor has Gameplay Tag changes.

Pro:
+ Easy to understand (even for gamedesigners, no need to understand GAS at all)
+ Easy to use because the Target only needs to implement IGameplayTagAssetInterface (one GameplayTagContainer is enough).

Con:
- Polling is always less performant than reacting to events, use only if solution 2 is not an option
- To prevent unnecessary polling, it is recommended to use this solution with other limiting additions e.g. low frequency, only in a trigger area, only for a some time or only close to the player.

## Solution 2: Receive Gameplay Tag change events based on AbilitySystemComponent (ASC)
In this solution the Listener is subscribed to gameplay tag change events on the Target Actor through the Target's AbilitySystemComponent.

Pro:
+ Event based so performance is better

Con:
- Target actor needs to have an AbilitySystemComponent
- Needs additional ASC, GE setups
- Harder to understand for gamedesigners
- If we want to listen to count change events we need to specify the gameplay tag which can be a limitation
