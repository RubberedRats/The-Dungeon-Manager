extends DetailedItemList

@export var encounter_name: TextEdit
@export var encounter_tier: OptionButton
@export var encounter_type: OptionButton
@export var encounter_terrain: OptionButton
@export var encounter_diff: OptionButton

@onready var curr_index: int = -1
@onready var inventory_path: String = "res://Assets/Data/Items/example.json"
@onready var available_items: Dictionary = load_items(inventory_path)

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass
	
# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta: float) -> void:
	pass

func add_new_entry(n: String, i: Array) -> void:
	add_item(n)
	push_entry(i)

func generate_entry_items() -> Array:
	if (available_items.size() <= 0):
		print("Path is empty.")
		return []
	
	var num_drops = 0
	var quantity_range = [1, 1]
	if encounter_type.get_item_text(encounter_type.selected) == "Beast":
		num_drops = randi_range(1, 2)
		quantity_range = [1, 1]
	else:
		num_drops = randi_range(3, 6)
		quantity_range = [1, 3]

	if (encounter_diff.selected >= 1): # High CR enemy
		num_drops += 1
		print("Extra item")

	var output = []
	for i in range(num_drops):
		var category = available_items.keys()[randi() % available_items.size()]
		var item = available_items[category].keys()[randi() % available_items[category].size()]

		var drop = BasicItem.new()
		drop.set_name(available_items[category][item]["name"].capitalize())
		drop.set_type(available_items[category][item]["type"])
		drop.set_rarity(available_items[category][item]["rarity"])
		drop.set_value(available_items[category][item]["value"])
		drop.set_desc(available_items[category][item]["description"])
		drop.set_tags(available_items[category][item]["tags"])
		drop.set_quantity(randi_range(quantity_range[0], quantity_range[1]))

		output.append(drop)
	
	return output
	
func load_items(path: String) -> Dictionary:
	var file = FileAccess.open(path, FileAccess.READ)
	var content = file.get_as_text()

	var json = JSON.new()
	var err = json.parse(content)
	if err == OK:
		return json.data
	else:
		return Dictionary()

func _on_delete_entry_pressed() -> void:
	if (curr_index >= 0):
		remove_item(curr_index)
		remove_entry(curr_index)
		deselect_all()
		curr_index = -1

func _on_item_selected(index:int) -> void:
	curr_index = index

func _on_item_activated(_index:int) -> void:
	pass

func _on_generate_encounter_pressed() -> void:
	var encounter_drops: Array = generate_entry_items()
	var entry_name = encounter_name.get_line(0) if (encounter_name.get_line(0).length() > 0) else "Encounter {0}".format([get_entries().size() + 1])
	add_new_entry(entry_name, encounter_drops)
