#include "plugin.h"
#include "x64dbgBccPlugin.h"
#include "icons.h"

//---------------------------------------------------------------------------

//Initialize your plugin data here.
bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
	_plugin_registercommand(pluginHandle, "TestCommand", cbTestCommand, true);
	_plugin_registercommand(pluginHandle, "SetBpTestCommand", cbTestSetBreakpoints, true);
	_plugin_registercommand(pluginHandle, "DelBpTestCommand", cbTestDelBreakpoints, true);

	return true; //Return false to cancel loading the plugin.
}
//---------------------------------------------------------------------------

//Deinitialize your plugin data here (clearing menus optional).
bool pluginStop()
{
	_plugin_unregistercommand(pluginHandle, "TestCommand");
	_plugin_unregistercommand(pluginHandle, "SetBpTestCommand");
	_plugin_unregistercommand(pluginHandle, "DelBpTestCommand");

	_plugin_menuclear(hMenu);
	_plugin_menuclear(hMenuDisasm);
	_plugin_menuclear(hMenuDump);
	_plugin_menuclear(hMenuStack);

	return true;
}
//---------------------------------------------------------------------------

//Do GUI/Menu related things here.
void pluginSetup()
{
	ICONDATA menu_icon;
	menu_icon.data = icon;
	menu_icon.size = sizeof(icon);

	// Plugin Menu
	_plugin_menuseticon(hMenu, &menu_icon);

	_plugin_menuaddentry(hMenu, MENU_TEST, "&Menu Test");
	_plugin_menuaddentry(hMenu, MENU_SETBP, "&Set Breakpoint Test");
	_plugin_menuaddentry(hMenu, MENU_DELBP, "&Delete Breakpoint Test");
	_plugin_menuaddseparator(hMenu);
	_plugin_menuaddentry(hMenu, MENU_ABOUT, "&About...");
}
//---------------------------------------------------------------------------
