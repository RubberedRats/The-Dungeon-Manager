extends Window

@export var entries: DetailedItemList
@export var text_window: Label

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	force_native = true
	get_node("ScrollBar").custom_minimum_size = get_size_with_decorations()
	hide()

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta: float) -> void:
	get_node("ScrollBar").custom_minimum_size = get_size_with_decorations()

func _on_entries_item_activated(index:int) -> void:
	var entry: Array = entries.get_entries()[index]
	display_item_text(entry)

func display_item_text(items: Array) -> void:
	text_window.text = ""

	for item in items:
		var displayed_text = """
%-20s x%d
%s,  %s
%.2f GP

%s

%s""" % [
		item.get_name(), 
		item.get_quantity(),
		item.get_type().capitalize(), 
		item.get_rarity().capitalize(),
		item.get_value(),
		item.get_desc(),
		item.generate_full_description()
		]

		text_window.text += displayed_text + "\n"

	show()

func _on_close_requested() -> void:
	hide()
