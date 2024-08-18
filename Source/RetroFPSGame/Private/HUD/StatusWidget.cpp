// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/StatusWidget.h"

void UStatusWidget::SetWidgetController(UObject* InController)
{
	WidgetController = InController;
	WidgetControllerSet();
}
