// Copyright Benjamin Herzig


#include "UI/Widget/AuraCommonUserWidget.h"

void UAuraCommonUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
