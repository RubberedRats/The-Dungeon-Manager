extends Node2D

@onready var main_menu_tabs = $"MainMenuTabs"
@onready var loot_gen = $"MainMenuTabs/LootGen"

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	var size = get_window().size
	main_menu_tabs.set_size(size)
	for i in range(main_menu_tabs.get_tab_count()):
		main_menu_tabs.get_tab_control(i).set_size(size)

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta: float) -> void:
	var size = get_window().size
	main_menu_tabs.set_size(size)
	for i in range(main_menu_tabs.get_tab_count()):
		main_menu_tabs.get_tab_control(i).set_size(size)
